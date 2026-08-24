#ifndef ECRAN_H
#define ECRAN_H

#include <Arduino.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

class ecran{
  public:
    ecran();
    void init();
    void display_temperature(float tempe);
    void display_humidity(float humi);
    bool error_dht(float tempe, float humi);
    void clear();
  private:
    LiquidCrystal_I2C _lcd;
};

#endif