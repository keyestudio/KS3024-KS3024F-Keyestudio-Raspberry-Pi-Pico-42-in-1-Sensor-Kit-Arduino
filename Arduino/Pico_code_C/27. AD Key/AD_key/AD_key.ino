/* 
 * Keyestudio 42 in 1 Starter Kit for Raspberry Pi Pico
  * lesson 27
 * AD Key
 * http://www.keyestudio.com
*/
int val = 0;
int ADkey = 26; //Define five AD buttons to connect to GPIO26
void setup() {
  Serial.begin(9600); //Set baud rate to 9600
}

void loop() {
  val = analogRead(ADkey);  //Read the analog value of the AD button and assign it to the variable val
  Serial.print(val);  //newline print variable val
  if (val <= 500) { //When no button is pressed, val is less than or equal to 500
    Serial.println("   no key  is pressed");

  } else if (val <= 1200) { //When key 5 is pressed, val is between 500 and 1200
    Serial.println("   SW5 is pressed");
  } else if (val <= 2000) { //When key 4 is pressed, val is between 1200 and 2000
    Serial.println("   SW4 is pressed");
  } else if (val <= 2800) { //When key 3 is pressed, val is between 2000 and 2800
    Serial.println("   SW3 is pressed");
  } else if (val <= 3500) { //When key 2 is pressed, val is between 2800 and 3500
    Serial.println("   SW2 is pressed");
  } else {  //When button 1 is pressed, val is greater than 3500
    Serial.println("   SW1 is pressed");
  }

}
