/* 
 * Keyestudio 42 in 1 Starter Kit for Raspberry Pi Pico
  * lesson 56
 * breathalyzer
 * http://www.keyestudio.com
*/
#include "KETM1650.h" //Import the library file of TM1650
int val = 0; //display values
//ports are connected to GP14, GP15
#define DIO 14
#define CLK 15
KETM1650 tm_4display(CLK, DIO);

void setup() {
  tm_4display.init(); //initialization
  tm_4display.setBrightness(3); //Set Brightness to 3, in the range of 1~8
  pinMode(3, OUTPUT);//the active buzzer is connected to 3
}

void loop() {
  val = analogRead(26);//Read alcohol analog value
  tm_4display.displayString(val);//Four-digit display shows val value
  if (val > 3000) {//analog values are more than3000
    digitalWrite(3, HIGH); //alarm
  } else {//otherwise
    digitalWrite(3, LOW); //turn off the buzzer
  }
  delay(100);//delay in 100ms
}
