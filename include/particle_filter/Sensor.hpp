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
      bool updateMeasurement(const Particle &input, const Particles &input_state, Particles &output_measuresments);
      /*
       *
       */
      Particle getMeasurement(const Particles &input_measurement);
      /*
       *
       */
      virtual float getError(const Particle& input,const Particle& output);
    protected:
      /*
       *
       */
      virtual void update(const Particle &input,const Particle &input_state,Particle &output_measurement);
      /*
       *
       */
      int _size;
    private:
  };
}// namespace particle_filter
#endif
