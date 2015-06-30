#include<particle_filter/Headers.hpp>
#include<particle_filter/Particle.hpp>
#include<particle_filter/Particles.hpp>
#include<particle_filter/Sensor.hpp>
#include<particle_filter/System.hpp>
#include<particle_filter/Random.hpp>
#include<mlpack/core/util/version.hpp>
#include<particle_filter/Simulator.hpp>
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
  std::ifstream in("data/data_y");
  std::ofstream out("data/vinay_x");
  Simulator<Particle,Particle> _simu(1,1,2000);
  std::cout<<"Simulator initialized"<<std::endl;
  Particle obs(1,0);
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
      _simu.doSingleStep(obs);
      auto v = _simu.getCurrentState();
      i++;
      out<<i<<'\t'<<v.getStates()[0]<<'\n';
  }
  in.close();
  out.close();
  std::cout<<std::endl;
  return 0;
}
