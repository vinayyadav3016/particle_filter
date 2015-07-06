#include<particle_filter/example_sensor.hpp>

namespace particle_filter
{
    /*
     *
     */
    ExampleSensor::ExampleSensor(int size):Sensor(size)
    {
    }
    /*
     *
     */
    Particle ExampleSensor::getMeasurement(const Particles &input_measurement)
    {
      //
      auto __input = input_measurement.getParticles();
      //
      float len = __input.size();
      //
      auto it = __input.begin();
      //
      Particle vals = Particle(_size);
      //std::cout<<_size<<std::endl;
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
          *vl+=(*in)*(it->getWeight());
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
    void ExampleSensor::update(const Particle &input,const Particle &input_state,Particle &output_measurement)
    {
        std::vector<float> vals ;
        //
        auto in = input_state.getStates();
        //
        auto rand = getRandom();
        //
        float time = input.getStates()[0];
        //
        auto val = rand.begin();
        //
        for(int i=0;i<_size;i++,val++)
        {
            float value =(pow(in[0],2)/20.0)+*val;
            vals.push_back(value);
        }
        //
        output_measurement.setStates(vals);
     }
}//namespace particle_filter
