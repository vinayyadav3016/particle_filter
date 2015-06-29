#ifndef PARTICLES_HPP
#define PARTICLES_HPP
#include<particle_filter/Headers.hpp>
#include<particle_filter/Particle.hpp>

namespace particle_filter
{
  template<typename T>
  class Particles
  {
    public:
      /*
       *
       */
      Particles(int states=1,int nums=0):_num_of_particles(nums)
      {
        for(int i=0;i<nums;i++)
        {
          _particles.push_back(T(states,i));
        }
      }
      /*
       *
       */
      virtual ~Particles(){}
      /*
       *
       */
      void clear()
      {
        //
        _particles.clear();
        //
        _num_of_particles=0;
      }
      /*
       *
       */
      void reset()
      {
        //
        for(auto it=_particles.begin();it<_particles.end();it++)
        {
          //
          it->reset();
        }
      }
      /*
       *
       */
      bool modifyWeights(const std::vector<float> & weights)
      {
        //
        if (weights.size()!=_num_of_particles)
        {
          return false;
        }
        auto val = weights.begin();
        for(auto it=_particles.begin();it<_particles.end();it++,val++)
        {
          //
          it->setWeight(*val);
        }
        return true;
      }
      /*
       *
       */
      bool resample();
      /*
       *
       */
      friend std::ostream &operator<< (std::ostream &output,const Particles<T> &n)
      {
        //
        output<<n._num_of_particles;
        for(auto it = n._particles.begin();it!=n._particles.end();it++)
        {
          output<<'\t'<<*it;
        }
        output<<std::endl;
        return output;
      }
      /*
       *
       */
      friend std::istream &operator>> (std::istream &input,Particles<T> &n)
      {
        input>>n._num_of_particles;
        for(int i=0;i<n._num_of_particles;i++)
        {
          auto t = T();
          input>>t;
          n._particles.push_back(t);
        }
        return input;
      }
      /**
       *
       */
      /*
       *
       */
    protected:
      /*
       *
       */
      std::vector<T> _particles;
      /*
       *
       */
      int _num_of_particles;
    private:

  };
}
#endif
