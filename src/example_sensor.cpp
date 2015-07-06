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
            float value =0;
            for(auto it=in.begin();it<in.end();it++)
            {
              //
              value+=pow(*it,2)/20.0+*val;
            }
            vals.push_back(value);
        }
        //
        output_measurement.setStates(vals);
     }
}//namespace particle_filter
