#include<particle_filter/example_distribution.hpp>

namespace particle_filter
{
  /*
   *
   */
  ExampleDistribution::ExampleDistribution()
  {

  }
  /*
   *
   */
  float ExampleDistribution::statePDF(const Particle& input,const Particle& output) const
  {
    //
    auto states1 = input.getStates();
    //
    auto states2 = output.getStates();
    //
    float __diffs=0;
    //
    __diffs+=pow(states2[0]-((states1[0])/2.0 + 25*(states1[0])/(1+pow(states1[0],2))+8*cos(1.2*states1[1])),2);
    //std::cout<<states2[1]<<":"<<states1[1]<<std::endl;
    //
    return exp(-0.5*__diffs);
  }
  /*
   *
   */
  float ExampleDistribution::observationPDF(const Particle& input,const Particle& obs) const
  {
    //
    auto x=input.getStates()[0];
    //
    auto y=obs.getStates()[0];
    //
    return exp(-.5*pow(y-pow(x,2)/20.0,2));
    //
    return 1/exp(x/2)*exp(-0.5*pow(y/_beta/exp(x/2),2));
  }
  /*
   *
   */
  float ExampleDistribution::proposalPDF(const Particle& input,const Particle& output, const Particle& obs) const
  {
    //
    auto states1 = input.getStates();
    //
    auto states2 = output.getStates();
    //
    float __diffs=0;
    //
    __diffs+=pow(states2[0]-((states1[0])/2.0 + 25*(states1[0])/(1+pow(states1[0],2))+8*cos(1.2*states1[1])),2);
    //
    return exp(-0.5*__diffs);
  }
}//namespace particle_filter
