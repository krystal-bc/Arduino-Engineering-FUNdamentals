/*Krystal Bernal
 * Engineering FUNdamentals
 * Day 3: RGB LED
 * This program teaches for statements 
 * to control the color of an RGB LED
 * last updated 4/9/16
*/

const int redPin = 3;
const int greenPin = 5;
const int bluePin = 6;

int redValue;
int greenValue;
int blueValue;

void setup(){
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
  digitalWrite(redPin, LOW);
  digitalWrite(greenPin, LOW);
  digitalWrite(bluePin, LOW);
}



void loop(){
  redValue = 255; // choose a value between 1 and 255 to change the color.
  greenValue = 0;
  blueValue = 0;

  analogWrite(redPin, 0);
  delay(5000);

   for(int i = 0; i < 255; i++){
    redValue--;
    greenValue++;
    analogWrite(redPin, 255 - redValue);
    analogWrite(greenPin, 255 - greenValue);
    delay(50);
  }

  redValue = 0;
  greenValue = 255;
  blueValue = 0;

  for(int i = 0; i < 255; i++){
    greenValue--;
    blueValue++;
    analogWrite(greenPin, 255 - greenValue);
    analogWrite(bluePin, 255 - blueValue);
    delay(50);
  }

  redValue = 0;
  greenValue = 0;
  blueValue = 255;


  for(int i = 0; i < 255; i++){
  redValue++;
  blueValue--;
  analogWrite(redPin, 255 - redValue);
  analogWrite(bluePin, 255 - blueValue);
  delay(50);
  }
}
