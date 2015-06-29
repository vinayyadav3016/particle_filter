#include<particle_filter/Headers.hpp>
#include<particle_filter/Particle.hpp>
#include<particle_filter/Particles.hpp>
#include<particle_filter/Sensor.hpp>
#include<particle_filter/System.hpp>
#include<particle_filter/Random.hpp>
#include<mlpack/core/util/version.hpp>
using namespace particle_filter;
int main(int argc,char** argv)
{
  //Particles<Particle> p(10,10);
  Random rand(5);
  auto val = rand.getRandom();
  for(auto it=val.begin();it<val.end();it++)
  {
      std::cout<<*it<<'\t';
  }
  std::cout<<std::endl;
  return 0;
}
