#include<particle_filter/System.hpp>

namespace particle_filter
{

  /*
   *
   */
  System::System(int size):Random(size),_size(size)
  {
    //
  }
  /*
   *
   */
  void System::initiate()
  {
    //
  }
  /*
   *
   */
  bool System::updateStates(const Particle &input,const Particles &input_state, Particles &output_state)
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
  Particle System::getState(const Particles &input_state)
  {
    //
    auto __input = input_state.getParticles();
    //
    auto it = __input.begin();
    //
    Particle vals = Particle(_size);
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
  void System::update(const Particle &input,const Particle&input_state, Particle&output_state)
  {
    //
    std::vector<float> vals ;
    //
    auto in = input_state.getStates();
    //
    auto rand = getRandom();
    //
    auto val = rand.begin();
    //
    for(auto it=in.begin();it<in.end();it++,val++)
    {
      //
      vals.push_back(0.91*(*it)+*val);
    }
    //
    output_state.setStates(vals);
  }
}
