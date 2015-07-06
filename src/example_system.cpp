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
    Particle ExampleSystem::getState(const Particles &input_state)
    {
      //
      auto __input = input_state.getParticles();
      //
      auto it = __input.begin();
      //
      Particle vals = Particle(_size);
      //std::cout<<"size:"<<_size<<std::endl;
      //
      std::vector<float> __vals(_size);
      //
      float len = __input.size();
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
          //std::cout<<*vl<<std::endl;
          *vl+=*in*(it->getWeight());
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
        auto it=in.begin();
        //
        //std::cout<<"Size:"<<output_state.getStates().size()<<std::endl;
        //std::cout<<"1:"<<*it<<(*(it+1)+1)<<std::endl;
        vals.push_back((*it)/2.0 + 25*(*it)/(1+pow(*it,2))+8*cos(1.2*(*(++it)))+*val);
        //
        //std::cout<<"2:"<<*it<<std::endl;
        vals.push_back((*it)+1);
        //
        output_state.setStates(vals);
        //std::cout<<output_state.getStates()[1]<<":"<<output_state.getStates()[0]<<std::endl;
    }
}//namespace particle_filter
