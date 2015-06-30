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
        auto it1=input._particles.begin();
        //
        //std::cout<<input._particles.begin()->getStates().size()<<'\n';
        //
        auto it2=output._particles.begin();
        //
        for(;it1<input._particles.end();it1++,it2++)
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
        std::vector<float> _weights;
        //
        for(auto it=input._particles.begin();it<input._particles.end();it++)
        {
          //
          _weights.push_back(it->getWeight());
        }
        //
        std::discrete_distribution<int> gen (_weights.begin(),_weights.end());
        //
        std::copy(input._particles.begin(),input._particles.end(),output._particles.begin());
        //
        for(auto it=output._particles.begin();it<output._particles.end();it++)
        {
          //
          int index = gen(generator);
          //
          *it=input._particles[index];
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
