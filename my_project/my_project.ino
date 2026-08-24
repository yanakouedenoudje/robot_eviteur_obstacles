//Bibliothèques externes
#include <Servo.h>
//Modules personnels
#include "L298N.h"
#include "HCSR04.h"
#include "ecran.h"
#include "sensor_t_h.h"

Servo my_servo;
L298N driver(3, 2, 4, 5, 7, 8, 200, 100, 0);
HCSR04 hcsr04(12, 13);
ecran lcd;
sensor_dht dht(10);

//mes variables
float tempe;
float humi;
float distance;
float seuil = 15;
float distance_gauche;
float distance_droite;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600); //activer la communication au moniteur série
  my_servo.attach(9);
  my_servo.write(90);
  driver.init();
  hcsr04.init();
  lcd.init();
  dht.init();
}

void loop() {
  // put your main code here, to run repeatedly:

  //afficher donnée DHT11
  tempe = dht.tempe();
  humi = dht.humi();

  if (!lcd.error_dht(tempe, humi)) {   // si PAS d'erreur (false)
    lcd.display_temperature(tempe);
    lcd.display_humidity(humi);
  }

  //mouvements robot
  distance = hcsr04.distance();
  if(distance < seuil){
    driver.stop();
    delay(200);

    my_servo.write(0);
    delay(600);
    distance_gauche = hcsr04.distance();
    my_servo.write(90);
    delay(300);

    my_servo.write(180);
    delay(600);
    distance_droite = hcsr04.distance();
    my_servo.write(90);
    delay(300);

    if(distance_gauche < distance_droite){
      driver.move_right();
      delay(600);
      driver.stop();
    }else{
      driver.move_left();
      delay(600);
      driver.stop();
    }

  }else{
    driver.move_forwards();
  }





}
