#include<particle_filter/Sensor.hpp>

namespace particle_filter
{

  /*
   *
   */
  Sensor::Sensor(int size):Random(size),_size(size)
  {
    //
  }
  /*
   *
   */
  void Sensor::initiate()
  {
    //
  }
  /*
   *
   */
  bool Sensor::updateMeasurement(const Particles &input, Particles &output)
  {
    //
    const std::vector<Particle>& __input = input.getParticles();
    //
    std::vector<Particle>& __output = output.getParticles();
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
  void Sensor::update(const Particle &input,Particle &output)
  {
    //
    std::vector<float> vals;
    //
    auto in = input.getStates();
    //
    auto rand = this->getRandom();
    //
    auto val = rand.begin();
    //
    for(auto it=in.begin();it<in.end();it++,val++)
    {
      //
      vals.push_back(1*exp(*it/2)*(*val));
    }
    //
    output.setStates(vals);
  }
}
