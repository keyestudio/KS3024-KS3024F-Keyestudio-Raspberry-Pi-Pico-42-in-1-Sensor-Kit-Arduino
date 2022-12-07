/* 
 * Keyestudio 42 in 1 Starter Kit for Raspberry Pi Pico
 * lesson 4
 * button
 * http://www.keyestudio.com
*/
int val = 0;  //用来存放按键值
int button = 15; //按键的管脚接GP15
void setup() {
  Serial.begin(9600); //启动串口监视器并设置波特率为9600
  pinMode(button, INPUT); //设置按键管脚为输入模式
}

void loop() {
  val = digitalRead(button);  //读取按键的值并赋给变量val
  Serial.print(val);  //串口上打印出来
  if (val == 0) { //按下按键则读取到低电平，打印按下相关信息
    Serial.print("        ");
    Serial.println("Press the botton");
    delay(100);
  }

  else {  //打印松开按键相关信息
    Serial.print("        ");
    Serial.println("Loosen the botton");
    delay(100);
  }
}
