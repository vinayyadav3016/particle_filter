#include<particle_filter/Particles.hpp>

namespace particle_filter
{
  /*
   *
   */
  Particles::Particles(int states,int nums):_num_of_particles(nums)
  {
    for(int i=0;i<nums;i++)
    {
      _particles.push_back(Particle(states,1));
    }
  }
  /*
   *
   */
  void Particles::clear()
  {
    //
    _particles.clear();
    //
    _num_of_particles=0;
  }
  /*
   *
   */
  void Particles::reset()
  {
    //
    for(auto it=_particles.begin();it<_particles.end();it++)
    {
      //
      it->reset();
    }
  }
  /*
   *
   */
  bool Particles::modifyWeights(const std::vector<float> & weights)
  {
    //
    if (weights.size()!=_num_of_particles)
    {
      return false;
    }
    auto val = weights.begin();
    for(auto it=_particles.begin();it<_particles.end();it++,val++)
    {
      //
      it->setWeight(*val);
    }
    return true;
  }
  /*
   *
   */
  std::vector<float> Particles::getWeights() const
  {
      std::vector<float> weights;
    for(auto it=_particles.begin();it<_particles.end();it++)
    {
      //
      weights.push_back(it->getWeight());
    }
    return weights;
  }
  /*
   *
   */
  std::vector<Particle>& Particles::getParticles()
  {
    //
    return _particles;
  }
  /*
   *
   */
  const std::vector<Particle>& Particles::getParticles() const
  {
    //
    return _particles;
  }
  /*
   *
   */
  void Particles::normalizeWeights()
  {
    float val =1e-6;
    for(auto it=_particles.begin();it<_particles.end();it++)
    {
      val+=it->getWeight();
    }
    for(auto it=_particles.begin();it<_particles.end();it++)
    {
      it->setWeight(it->getWeight()/val);
    }
  }
  /*
   *
   */
  std::ostream &operator<< (std::ostream &output,const Particles &n)
  {
    //
    output<<n._num_of_particles;
    for(auto it = n._particles.begin();it!=n._particles.end();it++)
    {
      output<<'\t'<<*it;
    }
    output<<std::endl;
    return output;
  }
  /*
   *
   */
  std::istream &operator>> (std::istream &input,Particles &n)
  {
    input>>n._num_of_particles;
    for(int i=0;i<n._num_of_particles;i++)
    {
      Particle t = Particle();
      input>>t;
      n._particles.push_back(t);
    }
    return input;
  }
}
// namespace particle_filter
