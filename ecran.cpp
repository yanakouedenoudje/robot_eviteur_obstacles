#include "ecran.h"

//adresse, colonnes, lignes
ecran::ecran() : _lcd(0x27, 16, 2) {
}

//initialiser lcd
void ecran::init(){
  _lcd.init(); //initialiser lcd
  _lcd.backlight(); //allumer le rétroéclairage
  //mettre le cursor sur 1ere colonne 1ere ligne
}

//afficher valeur temperature sur lcd
void ecran::display_temperature(float tempe) {
  _lcd.setCursor(0, 0);
  _lcd.print("T = ");
  _lcd.print(tempe);
  _lcd.print((char)223);
  _lcd.print("C");
}

//afficher valeur humidity sur lcd
void ecran::display_humidity(float humi){
  _lcd.setCursor(0, 1);
  _lcd.print("h = ");
  _lcd.print(humi);
  _lcd.print("HR");
}

bool ecran::error_dht(float tempe, float humi){
  if(isnan(tempe) || isnan(humi)){
    _lcd.setCursor(0, 0);
    _lcd.print("DHT error");
    _lcd.setCursor(0, 1);
    _lcd.print("Check sensor");
    delay(3000);
    _lcd.clear();
    return true;
  }
  return false;
}

void ecran::clear(){
  _lcd.clear();
}