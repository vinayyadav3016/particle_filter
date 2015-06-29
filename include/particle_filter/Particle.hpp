#ifndef PARTICLE_HPP
#define PARTICLE_HPP

#include<iostream>
#include<algorithm>
#include<vector>
#include<string>

namespace particle_filter
{
  /*
   *
   */
  class Particle
  {
    public:
      /*
       *
       */
      Particle(int states=1,float weight=0.0);
      /*
       *
       */
      virtual ~Particle();
      /*
       *
       */
      const std::vector<float>& getState() const;
      /*
       *
       */
      void setState(const std::vector<float> &state);
      /*
       *
       */
      float getWeight() const;
      /*
       *
       */
      void setWeight(float weight);
      /*
       *
       */
      void reset();
      /*
       *
       */
      friend std::ostream &operator<<(std::ostream &output,const Particle &n);
      /*
       *
       */
      friend std::istream &operator>>(std::istream &input,Particle &n);
    protected:
      /*
       *
       */
      float _weight;
      /*
       *
       */
      std::vector<float> _state;
    private:
  };
}
// namespace particle_filter
#endif
