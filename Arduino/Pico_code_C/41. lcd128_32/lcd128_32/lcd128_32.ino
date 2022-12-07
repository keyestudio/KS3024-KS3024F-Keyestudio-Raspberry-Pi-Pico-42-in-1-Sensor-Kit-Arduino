/*
   Keyestudio 42 in 1 Starter Kit for Raspberry Pi Pico
     lesson 41
   lcd128*32
   http://www.keyestudio.com
*/
#include "lcd128_32_io.h"

//Create an instance of lcd12832, sda--->20, scl--->21
lcd lcd(20, 21);

void setup() {
  lcd.Init(); //initialization
  lcd.Clear();  //
}

void loop() {
  lcd.Cursor(0, 7); //Set display position
  lcd.Display("KEYES"); //set display content
  lcd.Cursor(1, 0);
  lcd.Display("ABCDEFGHIJKLMNOPQR");
  lcd.Cursor(2, 0);
  lcd.Display("123456789+-*/<>=$@");
  lcd.Cursor(3, 0);
  lcd.Display("%^&(){}:;'|?,.~\\[]");
}
