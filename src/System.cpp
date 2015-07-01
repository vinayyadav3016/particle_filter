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
  bool System::updateStates(const Particles &input, Particles &output)
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
  Particle System::getState(const Particles &input)
  {
    //
    auto __input = input.getParticles();
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
  void System::update(const Particle&input, Particle&output)
  {
    //
    std::vector<float> vals ;
    //
    auto in = input.getStates();
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
    output.setStates(vals);
  }
}
