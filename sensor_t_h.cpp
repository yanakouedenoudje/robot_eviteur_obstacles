#include "sensor_t_h.h"

//capteur DHT11
#define DHTTYPE DHT11

sensor_dht::sensor_dht(int pin): _dht(pin, DHTTYPE){

}

void sensor_dht::init(){
  _dht.begin(); //activer le capteurDHT11
}

float sensor_dht::tempe(){
  float temp = _dht.readTemperature();
  return temp;
}

float sensor_dht::humi(){
  float hum = _dht.readHumidity();
  return hum;
}