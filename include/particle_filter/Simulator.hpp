#ifndef SIMULATOR_HPP
#define SIMULATOR_HPP
#include<particle_filter/Headers.hpp>
#include<particle_filter/Particles.hpp>
#include<particle_filter/Particle.hpp>
#include<particle_filter/Sensor.hpp>
#include<particle_filter/System.hpp>
namespace particle_filter
{
  /*
   *
   */
  template<typename T,typename T2>
  class Simulator: public Sensor<T2>, public System<T>
  {
    /*
     */
    public:
      Simulator(int state,int obs);
      virtual ~Simulator();
    protected:
    private:
      Particles<T> _x1;
      Particles<T> _x2;
      T _state;
      T2 _observation;
  };
}//namespace particle_filer
#endif
