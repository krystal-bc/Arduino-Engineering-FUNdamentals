/*
 * Krystal Bernal
 * Engineering FUNdamentals
 * Day 5: Obstacle Avoiding Robot
 * This program uses a 4-pin Ultrasonic Sensor
 * and 2 Continuous Rotation Servos.
 * Last updated: 5/6/16
*/

/*
 * 180: Turn clockwise
 * 90:  Stops the motor
 * 0:   Turn counterclockwise
*/

#include <Servo.h> //include Servo library

Servo leftMotor;
Servo rightMotor; //declare motors

//pins for the ultrasonic sensor
const int trigPin = 4;  //sound output
const int echoPin = 7;  //sound input

int rightDistance;
int leftDistance;

const int LED = 13; //pin for LED

const int Lforward = 0;
const int Rforward = 180;

const int right = 180;
const int left = 0;
const int neutral = 90;

void setup() {
  Serial.begin(9600);                 //connect to the serial monitor
  
  rightMotor.attach(9);               //send signals to right motor through pin 5
  leftMotor.attach(10);               //send signals to left motor through pin 6
  rightMotor.write(neutral);          //set the motors to stop
  leftMotor.write(neutral);

  pinMode(trigPin, OUTPUT);           //the trigger pin is an output because it makes a sound
  pinMode(echoPin, INPUT);            // the echo pin is an input because it listens for the sound
  
  pinMode(LED, OUTPUT);
}

void loop() {
  
  int distance = checkDistance(); //check the distance in front
  if (distance > 6){              //if it is clear, move forward
      rightMotor.write(Rforward);
      leftMotor.write(Lforward);
      delay(500);
  }else if (distance <= 6){     //if something is blocking, do this routine
    rightMotor.write(neutral);            //stop
    leftMotor.write(neutral);

    rightMotor.write(right);              // turn right
    leftMotor.write(right);
    delay(900);

    rightMotor.write(neutral);
    leftMotor.write(neutral);
    rightDistance = checkDistance();      // check for objects
    delay(500);

    rightMotor.write(left);               // turn left
    leftMotor.write(left);
    delay(1750);

    rightMotor.write(neutral);
    leftMotor.write(neutral);
    leftDistance = checkDistance();       // check for objects 
    delay(500);

    rightMotor.write(neutral);            //stop
    leftMotor.write(neutral);
    delay(1000);
    
    chooseDirection(rightDistance, leftDistance); //choose which way to go
  }
}

void chooseDirection(int right, int left)
{
  if (left > right){            //if left has more room
    leftMotor.write(Lforward);  //keep going left
    rightMotor.write(Rforward); 
    delay(500); 
  }else if (right > left){      //if right has more room
    leftMotor.write(right);     //turn right
    rightMotor.write(right); 
    delay(1750);
  }else{                        //if both sides are blocked
    leftMotor.write(left); 
    rightMotor.write(left);     //turn backwards
    delay(900);
  }
}

int checkDistance(){
  
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);  //send some sound
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  /*  
   *  Duration is the time in microseconds from the sending of the ping to the reception of its echo off of an object.
   *  pulseIn() waits for the pin to go HIGH, starts timing, then waits for the pin to go LOW and stops timing.
   *  Returns the length of the pulse in microseconds or 0 if no complete pulse was received within the timeout.
   */
  long duration = pulseIn(echoPin, HIGH); //listen for the sound
  int inches = duration / 74 / 2;         //count how far a away it came from
  
  Serial.print(inches);                   //print the distance in the serial monitor
  Serial.println(" inches");

  if (inches < 6){                        //turn the LED on if an object is close
    digitalWrite(LED, HIGH);
    delay(500);
    digitalWrite(LED, LOW);
    }
  
  return inches;
}



