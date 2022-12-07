/* 
 * Keyestudio 42 in 1 Starter Kit for Raspberry Pi Pico
 * lesson 26
 * MQ3
 * http://www.keyestudio.com
*/
//The two pins of the smoke sensor are connected to 22 and 26 respectively.
int digitalPin =  22;
int analogPin = 26;
//The following two variables store the digital signal and the analog signal respectively int analogVal = 0;
int digitalVal = 0;

void setup() {
  Serial.begin(9600); //Set baud rate to 9600
  pinMode(digitalPin, INPUT); //set pin 22 to INPUT
}

void loop() {
  analogVal = analogRead(analogPin);  //read analog signals
  digitalVal = digitalRead(digitalPin);  //read digital signals
  Serial.print(analogVal);
  if (digitalVal == 1) {
    Serial.println("    Normal");
  }
  else {
    Serial.println("    Exceeding");
  }
  delay(100); //delay in 100ms

}
