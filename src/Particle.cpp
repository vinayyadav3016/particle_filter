#include<particle_filter/Particle.hpp>

namespace particle_filter
{
  /**
   * Particle constructor
   */
  Particle::Particle(int states,float weight):_weight(weight),_state(states)
  {
    //
  }
  /*
   *
   */
  Particle::~Particle()
  {
    //
  }
  /*
   *
   */
  void Particle::setStates(const std::vector<float> &state)
  {
    //
    if(state.size()!=_state.size())
    {
      return;
    }
    auto val = _state.begin();
    for(auto it=state.begin();it<state.end();it++,val++)
    {
      *val = *it;
    }
  }
  /*
   *
   */
  const std::vector<float>& Particle::getStates() const
  {
    //
    return _state;
  }
  /*
   *
   */
  void Particle::setWeight(float weight)
  {
    //
    _weight = weight;
  }
  /*
   *
   */
  float Particle::getWeight() const
  {
    //
    return _weight;
  }
  /*
   *
   */
  void Particle::reset()
  {
    //
    _weight=0;
    _state.resize(_state.size());
  }
  /*
   *
   */
  std::ostream &operator<<(std::ostream &output,const Particle &n)
  {
    //
    //
    for(auto it=n._state.begin();it<n._state.end();it++)
    {
      output<<*it<<'\t';
    }
    output<<n._weight;
    return output;
  }
  /*
   *
   */
  std::istream &operator>>(std::istream &input,Particle &n)
  {
    //
    //
    for(auto it=n._state.begin();it<n._state.end();it++)
    {
      input>>*it;
    }
    input>>n._weight;
    return input;
  }
}
