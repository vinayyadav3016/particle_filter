#ifndef  DISTRIBUTIONS_HPP
#define DISTRIBUTIONS_HPP

#include<particle_filter/Headers.hpp>

namespace particle_filter
{
  template<typename T,typename T2>
  class Distribution
  {
    public:
      /*
       *
       */
      Distribution(float alpha=0.91,float beta=1.0):_beta(beta),_alpha(alpha)
      {
      }
      /*
       *
       */
      virtual ~Distribution(){}
      /*
       *
       */
      float statePDF(const T& input,const T& output) const
      {
        auto states1 = input.getStates();
        auto states2 = output.getStates();
        float __diffs=0;
        for(auto it1=states1.begin(),it2=states2.begin();it1<states1.end();it1++,it2++)
        {
          __diffs+=pow(*it2-_alpha*(*it1),2);
        }
        return exp(-0.5*__diffs/states1.size());
      }
      /*
       *
       */
      float observationPDF(const T& input,const T2& obs) const
      {
        auto x=input.getStates()[0];
        auto y=obs.getStates()[0];
        return 1/exp(x/2)*exp(-0.5*pow(y/_beta/exp(x/2),2));
      }
      /*
       *
       */
      float proposalPDF(const T& input,const T& output, const T2& obs) const
      {
        auto states1 = input.getStates();
        auto states2 = output.getStates();
        float __diffs=0;
        for(auto it1=states1.begin(),it2=states2.begin();it1<states1.end();it1++,it2++)
        {
          __diffs+=pow(*it2-*it1,2);
        }
        return exp(-0.5*__diffs/states1.size());
      }
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
