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
  class Simulator
  {
    /*
     */
    public:
      Simulator(int state,int obs,int num_of_particels,System* system,Sensor* sensor,Distribution* dist);
      /*
       *
       */
      virtual ~Simulator(){}
      /*
       *
       */
      Particle getCurrentState() const;

      /*
       *
       */
      void doSingleStep(const Particle& obs);
      /*
       *
       */
      void simulate(const Particles &input,Particles &output,const Particle&obs);
      /*
       *
       */
      void update(const Particles &input,Particles &output,const Particle& obs);
      /*
       *
       */
      void resample(const Particles &input,Particles &output);
      /*
       *
       */
    protected:
    private:
      /*
       *
       */
      Particles _x1;
      /*
       *
       */
      Particles _x2;
      /*
       *
       */
      Particle _state;
      /*
       *
       */
      Particle _observation;
      /*
       *
       */
      std::default_random_engine generator;
      /*
       *
       */
      System* _system;
      /*
       *
       */
      Sensor* _sensor;
      /*
       *
       */
      Distribution* _distribution;
  };
}//namespace particle_filer
#endif
