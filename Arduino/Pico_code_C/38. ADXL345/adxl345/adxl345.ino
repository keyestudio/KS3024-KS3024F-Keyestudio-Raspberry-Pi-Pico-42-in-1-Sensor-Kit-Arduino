/*
   Keyestudio 42 in 1 Starter Kit for Raspberry Pi Pico
   lesson 38
   ADXL345
   http://www.keyestudio.com
*/
#include "adxl345_io.h"
//the port is sda-->9,scl-->910
adxl345 adxl345(9, 10);

float out_X, out_Y, out_Z;

void setup() {
  Serial.begin(57600);//Start serial port monitoring and set the baud rate to 57600
  adxl345.Init();
}

void loop() {
  adxl345.readXYZ(&out_X, &out_Y, &out_Z);
  Serial.print(out_X);
  Serial.print("g   ");
  Serial.print(out_Y);
  Serial.print("g   ");
  Serial.print(out_Z);
  Serial.println("g");
  delay(100);
}
