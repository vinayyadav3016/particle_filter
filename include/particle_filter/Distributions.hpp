#ifndef  DISTRIBUTIONS_HPP
#define DISTRIBUTIONS_HPP

#include<particle_filter/Headers.hpp>
#include<particle_filter/Particle.hpp>

namespace particle_filter
{
  class Distribution
  {
    public:
      /*
       *
       */
      Distribution(float alpha=0.91,float beta=1.0);
      /*
       *
       */
      virtual ~Distribution(){}
      /*
       *
       */
      virtual float statePDF(const Particle& input,const Particle& output) const;
      /*
       *
       */
      virtual float observationPDF(const Particle& input,const Particle& obs) const;
      /*
       *
       */
      virtual float proposalPDF(const Particle& input,const Particle& output, const Particle& obs) const;
      /*
       *
       */
    protected:
      float _alpha;
      float _beta;
    private:
  };
}//namespace particle_filter
#endif
