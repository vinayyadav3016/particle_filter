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
  bool Sensor::updateMeasurement(const Particle &input, const Particles &input_state, Particles &output_state)
  {
    //
    const std::vector<Particle>& __input = input_state.getParticles();
    //
    std::vector<Particle>& __output = output_state.getParticles();
    //
    auto val = __output.begin();
    //
    for(auto it=__input.begin();it<__input.end();it++,val++)
    {
      //
      update(input,*it,*val);
    }
    //
    return true;
  }
  /*
   *
   */
  void Sensor::update(const Particle &input,const Particle &input_state,Particle &output_state)
  {
    //
    std::vector<float> vals;
    //
    auto in = input_state.getStates();
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
    output_state.setStates(vals);
  }
}
