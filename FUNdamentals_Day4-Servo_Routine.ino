/*
 * Krystal Bernal
 * Engineering FUNdametals
 * Day 4: Servo Routine
 * This program uses 2 Continuous Rotation Servos.
 * Last updated: 3/25/16
*
 * Parallax motor specs
 * 180: Turn clockwise
 * 90: Stops the motor
 * 0: Turn counterclockwise
*/

#include <Servo.h> //include Servo library

Servo leftMotor;
Servo rightMotor; //declare motors

const int Lforward = 0;
const int Rforward = 180;

const int right = 180;
const int left = 0;
const int neutral = 90;

void setup() {
  Serial.begin(9600);
  
  rightMotor.attach(9);               //send signals to right motor through pin 5
  leftMotor.attach(10);               //send signals to left motor through pin 6
  rightMotor.write(neutral);          //set the motors to neutral
  leftMotor.write(neutral);
}

void loop() {
    
    rightMotor.write(Rforward);
    leftMotor.write(Lforward);
    delay(3000);
    
    rightMotor.write(neutral);
    leftMotor.write(neutral);
    delay(1000);
    
    rightMotor.write(right);  // turn right
    leftMotor.write(right);
    delay(500);

    rightMotor.write(left);   // turn left
    leftMotor.write(left);
    delay(750);

    rightMotor.write(right);  // reset facing forward
    leftMotor.write(right);
    delay(500);
    
}
