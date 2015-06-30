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
        auto val = output._particles.begin();
        for(auto it=input._particles.begin();it<input._particles.end();it++,val++)
        {
          update(*it,*val);
        }
        return true;
      }
      /*
       *
       */
      T getState(const Particles<T> &input)
      {
        auto it = input._particles.begin();
        T vals = T(_size);
        std::vector<float> __vals(_size);
        for(;it<input._particles.end();it++)
        {
          auto in = it->getStates().begin();
          auto vl = __vals.begin();
          for(;in<it->getStates().end();in++,vl++)
          {
            *vl+=*in;
          }
        }
        int len = input._particles.size();
        for(auto it=__vals.begin();it<__vals.end();it++)
        {
          *it = (*it)/float(len);
        }
        vals.setStates(__vals);
        return vals;
      }
    protected:
      int _size;
    private:
      void update(const T &input,T &output)
      {
        //
        std::vector<float> vals ;
        auto in = input.getStates();
        auto rand = getRandom();
        auto val = rand.begin();
        for(auto it=in.begin();it<in.end();it++,val++)
        {
          vals.push_back(0.91*(*it)+*val);
        }
        output.setStates(vals);
      }
  };
}// namespace particle_filter
#endif
