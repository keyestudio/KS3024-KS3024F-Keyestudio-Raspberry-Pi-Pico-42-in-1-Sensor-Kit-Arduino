/*
   Keyestudio 42 in 1 Starter Kit for Raspberry Pi Pico
   lesson 49
   Self-extinguishing
   http://www.keyestudio.com
*/
int item = 0;
void setup() {
  Serial.begin(9600);
  pinMode(20, OUTPUT);
  pinMode(21, OUTPUT);
}

void loop() {
  item = analogRead(26);//Connect the flame sensor to 26, read the analog value of the flame sensor and assign it to item
  Serial.println(item);//the serial monitor shows analog values
  if (item < 2000) {//less than 2000
    digitalWrite(20, LOW);//open the fan
    digitalWrite(21, HIGH);
  } else {//turn off the fan
    digitalWrite(20, LOW);
    digitalWrite(21, LOW);
  }
  delay(100);
}
