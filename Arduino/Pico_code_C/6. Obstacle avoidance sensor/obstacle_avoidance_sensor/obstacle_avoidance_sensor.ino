/* 
 * Keyestudio 42 in 1 Starter Kit for Raspberry Pi Pico
 * lesson 6
 * obstacle avoidance sensor
 * http://www.keyestudio.com
*/
int val = 0;
void setup() {
  Serial.begin(9600);//设置波特率为9600
  pinMode(16, INPUT);//设置引脚GP16为输入模式
}

void loop() {
  val = digitalRead(16);//读取数字电平
  Serial.print(val);//打印读取的电平信号
  if (val == 0) {//检测到障碍物
    Serial.print("        ");
    Serial.println("There are obstacles");
    delay(100);
  }
  else {//没检测到障碍物
    Serial.print("        ");
    Serial.println("All going well");
    delay(100);
  }
}
