/*
   lcd128_32软件IIC子程序,适用于arduino, esp32, raspberry pi pico
   2022/2/26
   Dengfei
   示例代码只能显示95个有限字符(font_7x8[95])
*/
#include "lcd128_32_io.h"

//创建lcd12832示例，sda--->20， scl--->21
lcd lcd(20, 21);

void setup() {
  lcd.Init(); //初始化
  lcd.Clear();  //清屏
}

void loop() {
  lcd.Cursor(0, 2); //设置显示位置
  lcd.Display("WINNER  WINNER"); //设置显示内容
  lcd.Cursor(1, 2);
  lcd.Display("CHICKEN DINNER");
  lcd.Cursor(2, 2);
  lcd.Display("good good study");
  lcd.Cursor(3, 3);
  lcd.Display("day  day  up! ");
}
