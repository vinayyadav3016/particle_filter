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
      bool updateMeasurement(const Particles &input, Particles &output);
    protected:
      /*
       *
       */
      virtual void update(const Particle &input,Particle &output);
      /*
       *
       */
      int _size;
    private:
  };
}// namespace particle_filter
#endif
