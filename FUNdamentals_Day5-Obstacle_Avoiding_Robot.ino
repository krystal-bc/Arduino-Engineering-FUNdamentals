/*
 * Krystal Bernal
 * Engineering FUNdamentals
 * Day 5: Obstacle Avoiding Robot
 * This program uses a 4-pin Ultrasonic Sensor
 * and 2 Continuous Rotation Servos.
 * Last updated: 3/25/16
*/

/*
 * Parallax motor specs
 * 180: Turn clockwise
 * 90: Stops the motor
 * 0: Turn counterclockwise
*/

#include <Servo.h> //include Servo library

Servo leftMotor;
Servo rightMotor; //declare motors

const int trigPin = 2;//decide where the pins on the sensors will go
const int echoPin = 4;

const int Lforward = 0;
const int Rforward = 180;

const int right = 180;
const int left = 0;
const int neutral = 90;

int rightDistance;
int leftDistance;

void setup() {
  Serial.begin(9600);
  
  rightMotor.attach(9);               //send signals to right motor through pin 5
  leftMotor.attach(10);               //send signals to left motor through pin 6
  rightMotor.write(neutral);          //set the motors to neutral
  leftMotor.write(neutral);

  pinMode(trigPin, OUTPUT);           //the trigger pin is an output
  pinMode(echoPin, INPUT);            // the echo pin is an input
}

void loop() {
  
  int distance = checkDistance();
  if (distance > 5){
      rightMotor.write(Lforward);
      leftMotor.write(Lforward);
  }else if (distance < 5){
    rightMotor.write(neutral);
    leftMotor.write(neutral);

    rightMotor.write(right);  // turn right
    leftMotor.write(right);
    delay(500);
    
    rightDistance = checkDistance();      // check for obstacles
    delay(500);

    rightMotor.write(left);   // turn left
    leftMotor.write(left);
    delay(1000);

    leftDistance = checkDistance();       // check for obstacles
    delay(500);

    rightMotor.write(right);  // reset facing forward
    leftMotor.write(right);
    delay(500);
    
    chooseDirection();
     
  }

  delay(100);
}

void chooseDirection()
{
  if (leftDistance > rightDistance) //if left is less obstructed 
  {
    leftMotor.write(left);  //turn left
    rightMotor.write(left); 
    delay(500); 
  }
  else if (rightDistance>leftDistance) //if right is less obstructed
  {
    leftMotor.write(right); //turn right
    rightMotor.write(right); 
    delay(500);
  }
   else //if they are equally obstructed
  {
    leftMotor.write(right); 
    rightMotor.write(right); //turn 180 degrees
    delay(1000);
  }
}

int checkDistance(){
  
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  /*  
   *  Duration is the time in microseconds from the sending of the ping to the reception of its echo off of an object.
   *  pulseIn() waits for the pin to go HIGH, starts timing, then waits for the pin to go LOW and stops timing.
   *  Returns the length of the pulse in microseconds or 0 if no complete pulse was received within the timeout.
   */
  long duration = pulseIn(echoPin, HIGH);
  int inches = duration / 74 / 2;
  
  Serial.print(inches);
  Serial.print("in  ");
  Serial.println();
  
  return inches;
  }



