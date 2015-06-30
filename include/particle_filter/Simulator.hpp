#ifndef SIMULATOR_HPP
#define SIMULATOR_HPP
#include<particle_filter/Headers.hpp>
#include<particle_filter/Particles.hpp>
#include<particle_filter/Particle.hpp>
#include<particle_filter/Sensor.hpp>
#include<particle_filter/System.hpp>
#include<particle_filter/Distributions.hpp>
namespace particle_filter
{
  /*
   *
   */
  template<typename T,typename T2>
  class Simulator: public Sensor<T2>, public System<T>,public Distribution<T,T2>
  {
    /*
     */
    public:
      Simulator(int state,int obs,int num_of_particels):System<T>(state),Sensor<T2>(obs),_x1(state,num_of_particels),
        _x2(state,num_of_particels),_observation(obs),_state(state),Distribution<T,T2>()
      {
      }
      /*
       *
       */
      virtual ~Simulator(){}
      /*
       *
       */
      T getCurrentState() const
      {
        return _state;
      }
      /*
       *
       */
      void doSingleStep(const T2& obs)
      {
        //
        simulate(_x1,_x2,obs);
        //
        resample(_x2,_x1);
        //
        this->_observation=obs;
        //
        this->_state = this->getState(_x1);
      }
      /*
       *
       */
      void simulate(const Particles<T> &input,Particles<T> &output,const T2&obs)
      {
        //
        this->updateStates(input,output);
        //
        this->update(input,output,obs);
        //
        output.normalizeWeights();
      }
      /*
       *
       */
      void update(const Particles<T> &input,Particles<T> &output,const T2& obs)
      {
        //
        auto __input = input.getParticles();
        //
        std::vector<T>& __output = output.getParticles();
        //
        auto it1=__input.begin();
        //
        auto it2=__output.begin();
        //
        for(;it1<__input.end();it1++,it2++)
        {
          //
          auto val = this->statePDF(*it1,*it2);
          //
          val*=this->observationPDF(*it2,obs);
          //
          val/=this->proposalPDF(*it1,*it2,obs);
          //
          it2->setWeight(it1->getWeight()*val);
        }
      }
      /*
       *
       */
      void resample(const Particles<T> &input,Particles<T> &output)
      {
        //
        auto __input = input.getParticles();
        //
        std::vector<T>& __output = output.getParticles();
        //
        std::vector<float> _weights;
        //
        for(auto it=__input.begin();it<__input.end();it++)
        {
          //
          _weights.push_back(it->getWeight());
        }
        //
        std::discrete_distribution<int> gen (_weights.begin(),_weights.end());
        //
        std::copy(__input.begin(),__input.end(),__output.begin());
        //
        for(auto it=__output.begin();it<__output.end();it++)
        {
          //
          int index = gen(generator);
          //
          *it=__input[index];
        }
        //
        output.normalizeWeights();
      }
      /*
       *
       */
    protected:
    private:
      /*
       *
       */
      Particles<T> _x1;
      /*
       *
       */
      Particles<T> _x2;
      /*
       *
       */
      T _state;
      /*
       *
       */
      T2 _observation;
      /*
       *
       */
      std::default_random_engine generator;
  };
}//namespace particle_filer
#endif
