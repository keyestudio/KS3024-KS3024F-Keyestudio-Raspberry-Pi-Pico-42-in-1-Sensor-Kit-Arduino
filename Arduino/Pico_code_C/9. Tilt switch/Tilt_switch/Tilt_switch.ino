/* 
 * Keyestudio 42 in 1 Starter Kit for Raspberry Pi Pico
 * lesson 9
 * Tilt switch
 * http://www.keyestudio.com
*/
int val; //存放倾斜传感器输出的电平值

void setup() {
  Serial.begin(9600);
  pinMode(17, INPUT);  //倾斜传感器管脚接GP17，设置GP17为输入模式
}

void loop() {
  val = digitalRead(17); //读取模块的电平信号
  Serial.println(val);  //换行打印出来
  delay(100); //延时100毫秒

}
