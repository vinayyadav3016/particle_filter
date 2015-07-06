#ifndef EXAMPLE_DISTRIBUTION_HPP
#define EXAMPLE_DISTRIBUTION_HPP
#include<particle_filter/Headers.hpp>
#include<particle_filter/Distributions.hpp>
namespace particle_filter
{
  class ExampleDistribution:public Distribution
  {
    public:
      /*
       *
       */
      ExampleDistribution();
      /*
       *
       */
      virtual ~ExampleDistribution(){}
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
    protected:
    private:
  };
}
#endif
