/*
   Keyestudio 42 in 1 Starter Kit for Raspberry Pi Pico
   lesson 62
   Comprehensive experiment
   http://www.keyestudio.com
*/
#include"ir.h"//the library of IR receiver
#include "xht11.h"
#include "adxl345_io.h"

//ADXL345 sda-->20,scl-->21
adxl345 adxl345(20, 21);

//the IR receiver is connected to GP11
IR IRreceive(11);

//xht11 to gpio19
xht11 xht(19);

//rgb is connected to 2,3 and 4
int r_pin = 2;
int g_pin = 3;
int b_pin = 4;

//the joystick module is connected to ports
int X = 26;
int Y = 27;
int KEY = 22;

//The potentiometer pin is connected to the analog port 28
int resPin = 28;

//LED is connected to GP14
int LED = 14;

//the obstacle avoidance sensor is connected to GP0
int Avoid = 0;

//interfaces of the Ultrasonic sensor
int Trig = 6;
int Echo = 7;

//interfaces of the button module
int button = 16;

int PushCounter = 0;//save the number of pressing the button
int yushu = 0;
unsigned char dht[4] = {0, 0, 0, 0};//receive 32 bit data
bool ir_flag = 1;
float out_X, out_Y, out_Z;

void counter() {
  delay(10);
  ir_flag = 0;
  if (!digitalRead(button)) {
    PushCounter++;
  }
}

void setup() {
  Serial.begin(9600);//set baud rate to 9600
  pinMode(KEY, INPUT);//the button of the joystick module
  pinMode(button, INPUT);//button module
  attachInterrupt(digitalPinToInterrupt(button), counter, FALLING);  //
  pinMode(Avoid, INPUT);//Obstacle avoidance sensor
  pinMode(Trig, OUTPUT);//Ultrasonic Module
  pinMode(Echo, INPUT);
  adxl345.Init();
  delay(1000);
}

void loop() {
  yushu = PushCounter % 8;
  if (yushu == 0) {  //remainder is 0
    yushu_0();  //rgb display
  } else if (yushu == 1) {  //remainder is 1
    yushu_1();  //show IR remote signals
  } else if (yushu == 2) {  //remainder is 2
    yushu_2();  //show temperature and humidity
  } else if (yushu == 3) {  //remainder is 3
    yushu_3();  //show values of the joystick module
  }else if (yushu == 4) {  //remainder is 4
    yushu_4();  //potentiometer controls LED
  } else if (yushu == 5) {  //remainder is
    yushu_5();  //detect obstacles
  } else if (yushu == 6) {  //remainder is 6
    yushu_6();  //show the distance detected by the ultrasonic sensor
  } else if (yushu == 7) {  //余数为7
    yushu_7();  //ADXL345三轴加速度值
  }
}

//RGB
void yushu_0() {
  int R = random(0, 255);
  int G = random(0, 255);
  int B = random(0, 255);
  analogWrite(r_pin, R);
  analogWrite(g_pin, G);
  analogWrite(b_pin, B);
  delay(300);
}

//Infrared reception
void yushu_1() {
  ir_flag = 1;
  while (ir_flag) {
    int key = IRreceive.getKey();
    if (key != -1) {
      Serial.println(key);
    }
  }
}

void yushu_2() {
  if (xht.receive(dht)) { //check and return true
    Serial.print("RH:");
    Serial.print(dht[0]); //湿度的整数部分,dht[1]为小数部分
    Serial.print("%  ");
    Serial.print("Temp:");
    Serial.print(dht[2]); //温度的整数部分,dht[3]为小数部分
    Serial.println("C");
  } else {    //read errors
    Serial.println("sensor error");
  }
  delay(1200);
}

void yushu_3() {
  int x = analogRead(X);
  int y = analogRead(Y);
  int key = digitalRead(KEY);
  Serial.print("X:");
  Serial.print(x);
  Serial.print("    Y:");
  Serial.print(y);
  Serial.print("    KEY:");
  Serial.println(key);
  delay(100);
}

void yushu_4() {
  int RES = analogRead(resPin);
  int res = map(RES, 0, 4095, 0, 255);
  Serial.println(res);
  analogWrite(LED, res);
  delay(100);
}

void yushu_5() {
  int val = digitalRead(Avoid);
  if (val == 0) {//detect obstacles
    Serial.println("There are obstacles");
  }
  else {//no obstacles are detected
    Serial.println("All going well");
  }
  delay(100);
}

void yushu_6() {
  float distance = checkdistance();
  Serial.print("distance:");
  Serial.print(distance);
  Serial.println("cm");
  delay(100);
}

void yushu_7() {
  adxl345.readXYZ(&out_X, &out_Y, &out_Z);
  Serial.print(out_X);
  Serial.print("g   ");
  Serial.print(out_Y);
  Serial.print("g   ");
  Serial.print(out_Z);
  Serial.println("g");
  delay(100);
}

float checkdistance() {
  digitalWrite(Trig, LOW);
  delayMicroseconds(2);
  digitalWrite(Trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(Trig, LOW);
  float distance = pulseIn(Echo, HIGH) / 58.00;
  delay(10);
  return distance;
}
