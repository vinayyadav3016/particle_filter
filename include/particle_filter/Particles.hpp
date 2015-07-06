#ifndef PARTICLES_HPP
#define PARTICLES_HPP
#include<particle_filter/Headers.hpp>
#include<particle_filter/Particle.hpp>

namespace particle_filter
{
  class Particles
  {
    public:
      /*
       *
       */
      Particles(int states=1,int nums=0);
      /*
       *
       */
      virtual ~Particles(){}
      /*
       *
       */
      void clear();
      /*
       *
       */
      void reset();
      /*
       *
       */
      bool modifyWeights(const std::vector<float> & weights);
      /*
       *
       */
      std::vector<float> getWeights() const;
      /*
       *
       */
      std::vector<Particle>& getParticles();
      /*
       *
       */
      const std::vector<Particle>& getParticles() const;
      /*
       *
       */
      void normalizeWeights();
      /*
       *
       */
      friend std::ostream &operator << (std::ostream &output,const Particles &n);
      /*
       *
       */
      friend std::istream &operator>> (std::istream &input,Particles &n);
      /*
       *
       */
    protected:
      /*
       *
       */
      std::vector<Particle> _particles;
      /*
       *
       */
      int _num_of_particles;
      /*
       *
       */
      std::default_random_engine generator;
    private:
  };
}
#endif
