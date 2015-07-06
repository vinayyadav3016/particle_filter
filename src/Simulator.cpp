#include<particle_filter/Simulator.hpp>

namespace particle_filter
{
  Simulator::Simulator(int state, int obs, int num_of_particels, System *system, Sensor *sensor, Distribution *dist):_x1(state,num_of_particels),
  _x2(state,num_of_particels),_x3(obs,num_of_particels),_observation(obs),_prediction(obs),_state(state),_system(system),_sensor(sensor),_distribution(dist)
  {
  }
  /*
  *
  */
  Particle Simulator::getCurrentState() const
  {
    return _state;
  }
  /*
  *
  */
  Particle Simulator::getCurrentPrediction() const
  {
    return _prediction;
  }
  /*
   *
   */
  const Particle& Simulator::Predict(const Particle& input)
  {
      _system->updateStates(input,_x1,_x2);
      _sensor->updateMeasurement(input,_x2,_x3);
      _x3.modifyWeights(_x1.getWeights());
      _prediction = _sensor->getMeasurement(_x3);
      return _prediction;
  }
  /*
   *
   */
  float Simulator::update(const Particle& input,const Particle& obs)
  {
      this->_observation=obs;
      this->update(_x1,_x2,obs);
      _x2.normalizeWeights();
      resample(_x2,_x1);
      _x1.normalizeWeights();
      this->_state = _system->getState(_x1);
      return _sensor->getError(_prediction,obs);
  }
  /*
   *
   */
  void Simulator::simulate(const Particles &input,Particles &output,const Particle&obs)
  {
    //
    _system->updateStates(Particle(),input,output);
    //
    this->update(input,output,obs);
    //
    output.normalizeWeights();
  }
  /*
   *
   */
  void Simulator::update(const Particles &input,Particles &output,const Particle& obs)
  {
    //
    auto __input = input.getParticles();
    //
    std::vector<Particle>& __output = output.getParticles();
    //
    auto it1=__input.begin();
    //
    auto it2=__output.begin();
    //
    for(;it1<__input.end();it1++,it2++)
    {
      //
      auto val = _distribution->statePDF(*it1,*it2);
      //
      val*=_distribution->observationPDF(*it2,obs);
      //
      val/=_distribution->proposalPDF(*it1,*it2,obs);
      //
      it2->setWeight(it1->getWeight()*val);
    }
  }
  /*
   *
   */
  void Simulator::resample(const Particles &input,Particles &output)
  {
    //
    auto __input = input.getParticles();
    //
    std::vector<Particle>& __output = output.getParticles();
    //
    std::vector<float> _weights;
    //
    for(auto it=__input.begin();it<__input.end();it++)
    {
      //
      _weights.push_back(it->getWeight());
    }
    //
    std::discrete_distribution<int> gen (_weights.begin(),_weights.end());
    //
    std::copy(__input.begin(),__input.end(),__output.begin());
    //
    for(auto it=__output.begin();it<__output.end();it++)
    {
      //
      int index = gen(generator);
      //
      *it=__input[index];
    }
    //
    output.normalizeWeights();
  }
}
