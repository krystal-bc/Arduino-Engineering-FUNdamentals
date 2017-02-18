/*
 Krystal Bernal
 Engineering FUNdamentals 
 Day 2: Servo & Potentiometer
 Last updated 2/26/16
*/
 
#include <Servo.h>//include the library of servo commands

Servo servo;
const int dimmerPin = A0;//set the potentiometer pin to A0

void setup() {
 servo.attach(9);
 Serial.begin(9600);
}

void loop() {
  int dimmerValue = analogRead(dimmerPin);
  Serial.print("dimmer value: ");
  Serial.println(dimmerValue);
  int angle = map(dimmerValue, 0, 1023, 0, 180);
  Serial.print("angle value: ");
  Serial.println(angle);

  servo.write(angle);
  delay(15);
}
