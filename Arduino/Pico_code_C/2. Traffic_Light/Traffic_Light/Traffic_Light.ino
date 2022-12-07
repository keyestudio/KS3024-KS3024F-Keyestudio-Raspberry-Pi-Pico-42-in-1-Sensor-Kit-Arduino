/* 
 * Keyestudio 42 in 1 Starter Kit for Raspberry Pi Pico
 * lesson 2
 * Traffic_Light
 * http://www.keyestudio.com
*/
int greenPin = 12;   //绿色LED接GP12
int yellowPin = 13; //黄色LED接GP13
int redPin = 14;   //红色LED接GP14
void setup() {
  //LED接口都设置为输出模式
  pinMode(greenPin, OUTPUT);
  pinMode(yellowPin, OUTPUT);
  pinMode(redPin, OUTPUT);
}

void loop() {
  digitalWrite(greenPin, HIGH); //点亮绿色LED
  delay(5000);  //延时5秒
  digitalWrite(greenPin, LOW); //关闭绿色LED
  for (int i = 1; i <= 3; i = i + 1) {  //运行三次
    digitalWrite(yellowPin, HIGH); //点亮黄色LED
    delay(500); //延时0.5秒
    digitalWrite(yellowPin, LOW); //关闭黄色LED
    delay(500); //延时0.5秒
  }
  digitalWrite(redPin, HIGH); //点亮红色LED
  delay(5000);  //延时5s
  digitalWrite(redPin, LOW); //关闭红色LED

}
