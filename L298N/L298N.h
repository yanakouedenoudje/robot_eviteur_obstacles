#ifndef MOTOR_DRIVER_H
#define MOTOR_DRIVER_H

#include <Arduino.h>

class L298N {
  public:
    L298N(int ena, int in1, int in2, int enb, int in3, int in4, int vitesse_avance, int vitesse_recule, int arret);
    void init();
    void move_forwards();
    void move_backwards();
    void move_left();
    void move_right();
    void stop();
  private:
    int _ena;
    int _in1;
    int _in2;
    int _enb;
    int _in3;
    int _in4;
    int _vitesse_avance;
    int _vitesse_recule;
    int _arret;
};

#endif