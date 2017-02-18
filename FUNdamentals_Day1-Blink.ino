/* Krystal Bernal
 * Engineering FUNdamentals
 * Day 1: Blink
 * This program uses an LED
 * Last updated: 02/26/16
*/

void setup() {
  // initialize digital pin 13 as an output.
  pinMode(13, OUTPUT);
}

// the loop function runs over and over again forever
void loop() {
  digitalWrite(13, HIGH); 
  delay(1000);              
  digitalWrite(13, LOW);   
  delay(1000);
}
