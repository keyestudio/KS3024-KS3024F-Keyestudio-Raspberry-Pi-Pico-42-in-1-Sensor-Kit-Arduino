/*
   Keyestudio 42 in 1 Starter Kit for Raspberry Pi Pico
     lesson 10
   collision sensor
   http://www.keyestudio.com
*/
int val = 0;
void setup() {
  Serial.begin(9600);//Set baud rate to 9600
  pinMode(17, INPUT);//Set the pin of the collision sensor to INPUT
}

void loop() {
  val = digitalRead(17);//Read values of the collision sensor
  Serial.print(val);//print out
  if (val == 0) {//set val to 0
    Serial.print("        ");
    Serial.println("The end of his!");
    delay(100);
  }
  else {//Set val to 1
    Serial.print("        ");
    Serial.println("All going well");
    delay(100);
  }
}
