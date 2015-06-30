#ifndef SENSOR_HPP
#define SENSOR_HPP

#include<particle_filter/Headers.hpp>
#include<particle_filter/Random.hpp>
namespace particle_filter
{
  /*
   *
   */
  template<typename T>
  class Sensor : public Random
  {
    public:
      /*
       *
       */
      Sensor(int size):Random(size)
      {
        //
      }
      /*
       *
       */
      void initiate()
      {
        //
      }
      /*
       *
       */
      ~Sensor()
      {
        //
      }
      /*
       *
       */
      bool updateMeasurement(const std::vector<T> &input, std::vector<T> &output)
      {
        //
        auto val = output.begin();
        for(auto it=input.begin();it<input.end();it++,val++)
        {
          update(*it,*val);
        }
        return true;
      }
    protected:
    private:
      void update(const T &input,T &output)
      {
        //
        std::vector<float> vals ;
        auto in = input.getState();
        auto rand= getRandom();
        auto val = rand.begin();
        for(auto it=in.begin();it<in.end();it++,val++)
        {
          vals.push_back(1*exp(*it/2.0)*(*val));
        }
        output.setState(vals);
      }
  };
}// namespace particle_filter
#endif
