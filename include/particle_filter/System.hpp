#ifndef SYSTEM_HPP
#define SYSTEM_HPP

#include<particle_filter/Headers.hpp>
#include<particle_filter/Random.hpp>
#include<particle_filter/Particles.hpp>
namespace particle_filter
{
  /*
   *
   */
  template<typename T>
  class System : public Random
  {
    public:
      /*
       *
       */
      System(int size):Random(size),_size(size)
      {
        //
      }
      /*
       *
       */
      void initiate()
      {
        //
      }
      /*
       *
       */
      ~System()
      {
        //
      }
      /*
       *
       */
      bool updateStates(const Particles<T> &input, Particles<T> &output)
      {
        //
        const std::vector<T>& __input = input.getParticles();
        //
        std::vector<T>& __output = output.getParticles();
        //
        auto val = __output.begin();
        //
        for(auto it=__input.begin();it<__input.end();it++,val++)
        {
          //
          update(*it,*val);
        }
        //
        return true;
      }
      /*
       *
       */
      T getState(const Particles<T> &input)
      {
        //
        auto __input = input.getParticles();
        //
        auto it = __input.begin();
        //
        T vals = T(_size);
        //
        std::vector<float> __vals(_size);
        //
        for(;it<__input.end();it++)
        {
          //
          auto in = it->getStates().begin();
          //
          auto vl = __vals.begin();
          //
          for(;in<it->getStates().end();in++,vl++)
          {
            //
            *vl+=*in*(it->getWeight());
          }
        }
        //
        vals.setStates(__vals);
        //
        return vals;
      }
    protected:
      int _size;
    private:
      void update(const T &input,T &output)
      {
        //
        std::vector<float> vals ;
        //
        auto in = input.getStates();
        //
        auto rand = getRandom();
        //
        auto val = rand.begin();
        //
        for(auto it=in.begin();it<in.end();it++,val++)
        {
          //
          vals.push_back(0.91*(*it)+*val);
        }
        //
        output.setStates(vals);
      }
  };
}// namespace particle_filter
#endif
