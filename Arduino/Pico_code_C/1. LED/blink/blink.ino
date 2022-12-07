/* 
 * Keyestudio 42 in 1 Starter Kit for Raspberry Pi Pico
 * lesson 1.2
 * Blink
 * http://www.keyestudio.com
*/
int ledPin = 0; //定义LED管脚接GP0
void setup() {
  pinMode(ledPin, OUTPUT);//设置模式为输出
}

void loop() {
  digitalWrite(ledPin, HIGH); //输出高电平，点亮
  delay(1000);//延迟1000毫秒
  digitalWrite(ledPin, LOW); //输出低电平，熄灭
  delay(1000);//延迟1000毫秒

}
