#ifndef RANDOM_HPP
#define RANDOM_HPP

#include<particle_filter/Headers.hpp>

namespace particle_filter
{
  /*
   *
   */
  class Random
  {
    public:
      /*
       *
       */
      Random(int no_states):_dist(no_states)
      {
      }
      /*
       *
       */
      Random(int no_states,const std::string &mean,const std::string &cov)
      {
        arma::vec __mean(no_states);
        std::ifstream read(mean.c_str());
        for(int i=0;i<no_states;i++)
        {
          float val;
          read>>val;
          __mean[i]=val;
        }
        arma::mat __cor;
        mlpack::data::Load(cov,__cor);
        _dist = mlpack::distribution::GaussianDistribution(__mean,__cor);
      }

      /*
       *
       */
      virtual ~Random()
      {
      }
      /*
       *
       */
      std::vector<float> getRandom() const
      {
        auto it =_dist.Random();
        return std::vector<float>(it.begin(),it.end());
      }
    protected:
    private:
      /*
       *
       */
      mlpack::distribution::GaussianDistribution _dist;
  };
}// namespace particle_filter
#endif
