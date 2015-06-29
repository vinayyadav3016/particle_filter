#ifndef SYSTEM_HPP
#define SYSTEM_HPP

#include<particle_filter/Headers.hpp>
#include<particle_filter/Random.hpp>
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
      System(int size):Random(size)
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
      bool updateStates(const T &input, T &output)
      {
        //
        auto val = output.begin();
        for(auto it=input.begin();it<input.end();it++,val++)
        {
          update(*it,*val);
        }
        return true;
      }
    protected:
    private:
      void update(const T &input,T &output)
      {
        //
        std::vector<float> vals ;
        auto in = input.getState();
        auto rand = getRandom();
        auto val = rand.begin();
        for(auto it=in.begin();it<in.end();it++.val++)
        {
          vals.push_back(0.91*(*it)+*val);
        }
        output.setState(vals);
      }
  };
}// namespace particle_filter
#endif
