#include<particle_filter/example_system.hpp>

namespace particle_filter
{
    /*
     *
     */
    ExampleSystem::ExampleSystem(int size):System(size)
    {
    }
    /*
     *
     */
    void ExampleSystem::update(const Particle &input,const Particle &input_state,Particle &output_state)
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
        for(auto it=in.begin();it<in.end();it++,val++)
        {
            //
            vals.push_back((*it)/2.0 + 25*(*it)/(1+pow(*it,2))+8*cos(1.2*time)+*val);
        }
        //
        output_state.setStates(vals);
    }
}//namespace particle_filter
