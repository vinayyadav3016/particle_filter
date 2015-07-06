#include<particle_filter/Headers.hpp>
#include<particle_filter/Particle.hpp>
#include<particle_filter/Particles.hpp>
#include<particle_filter/Sensor.hpp>
#include<particle_filter/System.hpp>
#include<particle_filter/Random.hpp>
#include<mlpack/core/util/version.hpp>
#include<particle_filter/Simulator.hpp>
#include<particle_filter/example_sensor.hpp>
#include<particle_filter/example_system.hpp>
#include<particle_filter/example_distribution.hpp>
using namespace particle_filter;
int main(int argc,char** argv)
{
  Random rand(1);
  int no_particle = std::stoi(argv[1]);
  std::ofstream out("data/vinay_x_ninza");
  ExampleSystem system(2);
  ExampleSensor sensor(1);
  ExampleDistribution dist;
  Simulator _simu(2,1,no_particle,&system,&sensor,&dist);
  std::cout<<"Simulator initialized"<<std::endl;
  Particle obs(1,0);
  Particle input(2,0);
  std::vector<float> vals;
  vals.push_back(0.0);
  //vals.push_back(0.0);
  float x=0.0;
  float z=pow(x,2)/20.0;
  int i=0;
  for(;i<std::atoi(argv[2]);i++)
  {
      //
      x = 0.5*x+25*x/(1+pow(x,2))+8*cos(1.2*i)+rand.getRandom()[0];
      z = pow(x,2)/20.0+rand.getRandom()[0];
      //
      vals[0]=z;
      obs.setStates(vals);
      vals[0] = x;
      //input.setStates(vals);
      //
      auto p=_simu.Predict(input);
      //
      auto val = _simu.update(input,obs);
      //
      std::cout<<"Error : "<<float(val)<<std::endl;
      auto v = _simu.getCurrentState();
      out<<i<<'\t'<<v.getStates()[0]<<":"<<v.getStates()[1]<<'\t'<<x<<':'<<i+1<<'\t'<<p.getStates()[0]<<":"<<z<<'\n';
  }
  out.close();
  std::cout<<std::endl;
  return 0;
}
