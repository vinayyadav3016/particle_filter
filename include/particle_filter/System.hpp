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
      bool updateStates(const Particle& input,const Particles &input_state, Particles &output_state);
      /*
       *
       */
      Particle getState(const Particles &input_state);
    protected:
      /*
       *
       */
      int _size;
      /*
       *
       */
      virtual void update(const Particle &input,const Particle &input_state,Particle &output_state);
    private:
  };
}// namespace particle_filter
#endif
