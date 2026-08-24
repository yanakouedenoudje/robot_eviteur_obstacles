#ifndef SENSOR_ULTRASON_H
#define SENSOR_ULTRASON_H

#include <Arduino.h>

class HCSR04{
  public:
    HCSR04(int trig, int echo);
    void init();
    float distance();
  private:
    int _trig;
    int _echo;
    float _a;
    float _b;
};

#endif