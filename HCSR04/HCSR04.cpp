#include "HCSR04.h"

HCSR04::HCSR04(int trig, int echo){
  _trig = trig;
  _echo = echo;
  _a = 0.9381058091341319;
  _b = -0.10270927147431053;
}

void HCSR04::init(){
  pinMode(_trig, OUTPUT); //envoi le signal
  pinMode(_echo, INPUT); //reçoit le signal
}

float HCSR04::distance(){

  //envoie signal depuis la borne trig
  digitalWrite(_trig, LOW);
  delayMicroseconds(2);
  digitalWrite(_trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(_trig, LOW);

  //recevoir le signal
  long duree = pulseIn(_echo, HIGH);

  //distance en cm, la vitesse du son = 340m/s et = 0.034cm/s
  float distance = (duree * 0.034)/2;

  //distance + régression linéaire
  float distance_predict = (_a * distance) + _b;

  return distance_predict;

}