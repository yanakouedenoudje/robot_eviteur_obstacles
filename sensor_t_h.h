#ifndef TEHU_H
#define TEHU_H

#include <Arduino.h>
#include <DHT.h>

class sensor_dht{
  public:
    sensor_dht(int pin);
    void init();
    float tempe();
    float humi();
  private:
    DHT _dht;

};

#endif
