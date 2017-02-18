/* Krystal Bernal
 * Engineering FUNdamentals
 * Day 1: Blink Augmented
 * This program uses 3 LEDs
 * Last updated: 02/26/16
 */

void setup() {
  pinMode(13, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(8, OUTPUT);
}

void loop() {
  digitalWrite(12, HIGH);
  delay(1000);
  digitalWrite(12, LOW);
  delay(1000);
  
  digitalWrite(8, HIGH);
  delay(500);
  digitalWrite(8, LOW);
  delay(500);

  digitalWrite(13, HIGH);
}
