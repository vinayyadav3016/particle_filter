#ifndef SENSOR_HPP
#define SENSOR_HPP

#include<particle_filter/Headers.hpp>
#include<particle_filter/Random.hpp>
#include<particle_filter/Particles.hpp>
namespace particle_filter
{
  /*
   *
   */
  class Sensor : public Random
  {
    public:
      /*
       *
       */
      Sensor(int size);
      /*
       *
       */
      void initiate();
      /*
       *
       */
      ~Sensor()
      {
        //
      }
      /*
       *
       */
      bool updateMeasurement(const Particle &input, const Particles &input_state, Particles &output_state);
    protected:
      /*
       *
       */
      virtual void update(const Particle &input,const Particle &input_state,Particle &output_state);
      /*
       *
       */
      int _size;
    private:
  };
}// namespace particle_filter
#endif
