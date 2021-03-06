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
using namespace particle_filter;
int main(int argc,char** argv)
{
  //Particles<Particle> p(10,10);
  /*Random rand(5,"data/mean.csv","data/cor.csv");
  auto val = rand.getRandom();
  for(auto it=val.begin();it<val.end();it++)
  {
      std::cout<<*it<<'\t';
  }
  */
  int no_particle = std::stoi(argv[1]);
  std::ifstream in("data/data_y");
  std::ofstream out("data/vinay_x");
  System system(1);
  Sensor sensor(1);
  Distribution dist;
  Simulator _simu(1,1,no_particle,&system,&sensor,&dist);
  std::cout<<"Simulator initialized"<<std::endl;
  Particle obs(1,0);
  Particle input(1,0);
  std::vector<float> vals;
  vals.push_back(0.0);
  int i=0;
  while(!in.eof())
  {
      float val;
      in>>val;
      //std::cout<<val<<std::endl;
      vals[0]=val;
      obs.setStates(vals);
      vals[0] = i;
      input.setStates(vals);
      _simu.Predict(input);
      val = _simu.update(input,obs);
      std::cout<<"Error : "<<float(val)<<std::cout<<std::endl;
      auto v = _simu.getCurrentState();
      auto p = _simu.getCurrentPrediction();
      i++;
      out<<i<<'\t'<<v.getStates()[0]<<'\t'<<p.getStates()[0]<<'\n';
  }
  in.close();
  out.close();
  std::cout<<std::endl;
  return 0;
}
