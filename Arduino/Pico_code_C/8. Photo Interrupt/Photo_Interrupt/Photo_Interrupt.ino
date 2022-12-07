/* 
 * Keyestudio 42 in 1 Starter Kit for Raspberry Pi Pico
 * lesson 8
 * Photo_Interrupt
 * http://www.keyestudio.com
*/
int PushCounter = 0; //计数变量赋初值0
int State = 0; //存放传感器输出当前的状态
int lastState = 0; //存放传感器上一次输出的状态

void setup() {
  Serial.begin(9600);//设置波特率为9600
  pinMode(3, INPUT);//设置光折断传感器管脚为输入模式
}

void loop() {
  State = digitalRead(3);//读取当前状态
  if (State != lastState) {//如果与上一次读取的状态不相同
    if (State == 1) {//挡住光线
      PushCounter = PushCounter + 1;//计数加1
      Serial.println(PushCounter);//打印计数
    }
  }
  lastState = State;//更新状态
}
