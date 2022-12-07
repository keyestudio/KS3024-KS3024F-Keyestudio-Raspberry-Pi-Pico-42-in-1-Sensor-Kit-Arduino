/* 
 * Keyestudio 42 in 1 Starter Kit for Raspberry Pi Pico
 * lesson 3
 * Laser sensor
 * http://www.keyestudio.com
*/
int laserPin = 2; //定义激光引脚为2
void setup() {
  pinMode(laserPin, OUTPUT);//定义激光引脚为输出模式
}

void loop() {
  digitalWrite(laserPin, HIGH); //打开激光
  delay(2000);  //延时2秒
  digitalWrite(laserPin, LOW); //关闭激光
  delay(2000);  //延时2秒

}
