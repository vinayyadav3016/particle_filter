#include<particle_filter/Distributions.hpp>

namespace particle_filter
{
  /*
   *
   */
  Distribution::Distribution(float alpha,float beta):_beta(beta),_alpha(alpha)
  {
    //
  }
  /*
   *
   */
  float Distribution::statePDF(const Particle& input,const Particle& output) const
  {
    //
    auto states1 = input.getStates();
    //
    auto states2 = output.getStates();
    //
    float __diffs=0;
    //
    for(auto it1=states1.begin(),it2=states2.begin();it1<states1.end();it1++,it2++)
    {
      //
      __diffs+=pow(*it2-_alpha*(*it1),2);
    }
    //
    return exp(-0.5*__diffs/states1.size());
  }
  /*
   *
   */
  float Distribution::observationPDF(const Particle& input,const Particle& obs) const
  {
    //
    auto x=input.getStates()[0];
    //
    auto y=obs.getStates()[0];
    //
    return 1/exp(x/2)*exp(-0.5*pow(y/_beta/exp(x/2),2));
  }
  /*
   *
   */
  float Distribution::proposalPDF(const Particle& input,const Particle& output, const Particle& obs) const
  {
    //
    auto states1 = input.getStates();
    //
    auto states2 = output.getStates();
    //
    float __diffs=0;
    //
    for(auto it1=states1.begin(),it2=states2.begin();it1<states1.end();it1++,it2++)
    {
      //
      __diffs+=pow(*it2-*it1,2);
    }
    //
    return exp(-0.5*__diffs/states1.size());
  }
}
