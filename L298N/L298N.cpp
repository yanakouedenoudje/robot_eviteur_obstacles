#include "L298N.h"

L298N::L298N(int ena, int in1, int in2, int enb, int in3, int in4, int vitesse_avance, int vitesse_recule, int arret){
  _ena = ena; //pin vitesse moteur roues gauche
  _in1 = in1; // pin commande avance roues gauche
  _in2 = in2; // pin commande recule roues gauche
  _enb = enb; //pin vitesse moteur roues droite
  _in3 = in3; // pin commande avance roues droite
  _in4 = in4; // pin commande recule roues droite
  _vitesse_avance = vitesse_avance; //vitesse avance
  _vitesse_recule = vitesse_recule; //vitesse recule
  _arret = arret; //vitesse d'arrêt
}

void L298N::init(){
  pinMode(_ena, OUTPUT);
  pinMode(_in1, OUTPUT);
  pinMode(_in2, OUTPUT);
  pinMode(_enb, OUTPUT);
  pinMode(_in3, OUTPUT);
  pinMode(_in4, OUTPUT);
}

void  L298N::move_forwards(){
  analogWrite(_ena, _vitesse_avance);
  analogWrite(_enb, _vitesse_avance);
  digitalWrite(_in1, HIGH);
  digitalWrite(_in2, LOW);
  digitalWrite(_in3, HIGH);
  digitalWrite(_in4, LOW);
}

void L298N::move_backwards(){
  analogWrite(_ena, _vitesse_recule);
  analogWrite(_enb, _vitesse_recule);
  digitalWrite(_in1, LOW);
  digitalWrite(_in2, HIGH);
  digitalWrite(_in3, LOW);
  digitalWrite(_in4, HIGH);
}

void L298N::move_left(){
  //roues gauche
  digitalWrite(_in1, LOW);
  digitalWrite(_in2, HIGH);

  //roues droite
  digitalWrite(_in3, HIGH);
  digitalWrite(_in4, LOW);

  //vitesses
  analogWrite(_ena, _vitesse_recule);
  analogWrite(_enb, _vitesse_avance);
}

void L298N::move_right(){
  //roues droite
  digitalWrite(_in3, LOW);
  digitalWrite(_in4, HIGH);
  
  //roues gauche
  digitalWrite(_in1, HIGH);
  digitalWrite(_in2, LOW);
  
  //vitesses
  analogWrite(_ena, _vitesse_avance);
  analogWrite(_enb, _vitesse_recule);
}

void L298N::stop(){
  //vitesses
  analogWrite(_ena, _arret);
  analogWrite(_enb, _arret);
}