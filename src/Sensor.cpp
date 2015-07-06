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
  bool Sensor::updateMeasurement(const Particle &input, const Particles &input_state, Particles &output_measuresments)
  {
    //
    const std::vector<Particle>& __input = input_state.getParticles();
    //
    std::vector<Particle>& __output = output_measuresments.getParticles();
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
  Particle Sensor::getState(const Particles &input_state)
  {
    //
    auto __input = input_state.getParticles();
    //
    float len = __input.size();
    //
    auto it = __input.begin();
    //
    Particle vals = Particle(_size);
    //
    std::vector<float> __vals(_size);
    //
    for(;it<__input.end();it++)
    {
      //
      auto in = it->getStates().begin();
      //
      auto vl = __vals.begin();
      //
      for(;in<it->getStates().end();in++,vl++)
      {
        //
        *vl+=(*in)/len;
      }
    }
    //
    vals.setStates(__vals);
    //
    return vals;
  }
  /*
   *
   */
  void Sensor::update(const Particle &input, const Particle &input_state, Particle &output_measurement)
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
    output_measurement.setStates(vals);
  }
  /*
   *
   */
  float Sensor::getError(const Particle &input, const Particle &output)
  {
      //
      float error=0;
      //
      auto __input = input.getStates();
      //
      auto __output = output.getStates();
      //
      for(auto it=__input.begin(),it1=__output.begin();it<__input.end();it++,it1++)
      {
          //
          error+=pow((*it1)-(*it),2);
      }
      return sqrt(error);
  }
}
