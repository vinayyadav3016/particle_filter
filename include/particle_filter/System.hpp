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
  class System : public Random
  {
    public:
      /*
       *
       */
      System(int size);
      /*
       *
       */
      void initiate();
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
      bool updateStates(const Particles &input, Particles &output);
      /*
       *
       */
      Particle getState(const Particles &input);
    protected:
      /*
       *
       */
      int _size;
      /*
       *
       */
      virtual void update(const Particle&input,Particle &output);
    private:
  };
}// namespace particle_filter
#endif
