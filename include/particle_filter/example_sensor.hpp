#ifndef EXAMPLE_SENSOR_HPP
#define EXAMPLE_SENSOR_HPP
#include<particle_filter/Headers.hpp>
#include<particle_filter/Sensor.hpp>
namespace particle_filter
{
    /*
     *
     */
    class ExampleSensor:public Sensor
    {
        public:
            /*
             *
             */
            ExampleSensor(int size);
            /*
             *
             */
            virtual ~ExampleSensor(){}
            /*
             *
             */
            virtual Particle getMeasurement(const Particles &input_measurement);
        protected:
            /*
             *
             */
            virtual void update(const Particle &input,const Particle &input_state,Particle &output_measurement);
        private:
    };
}//namespace particle_filter
#endif
