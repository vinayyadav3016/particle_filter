#ifndef EXAMPLE_SYSTEM_HPP
#define EXAMPLE_SYSTEM_HPP
#include<particle_filter/Headers.hpp>
#include<particle_filter/System.hpp>
namespace particle_filter
{
    /*
     *
     */
    class ExampleSystem:public System
    {
        public:
            /*
             *
             */
            ExampleSystem(int size);
            /*
             *
             */
            virtual ~ExampleSystem(){}
        protected:
            /*
             *
             */
            virtual void update(const Particle &input,const Particle &input_state,Particle &output_state);
        private:
    };
}//namespace particle_filter
#endif
