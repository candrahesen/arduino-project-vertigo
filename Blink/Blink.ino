/*
 * Blink
 * Turns on an LED ON for one second, then OFF for one second, repeatedly
 * 
 * This example code is in the public domain
 */

// Pin 13 has an LED connected on most Arduino boards
// give it a name:
int pinA = 2;
int pinB = 3;
int pinC = 4;
int pinD = 5;
int pinE = 6;
int pinF = 7;
int pinG = 8;

//the setup routine runs once when press reset:
void setup() {
  // initialize the digital pin as an output
  pinMode(pinA, OUTPUT);
  pinMode(pinB, OUTPUT);
  pinMode(pinC, OUTPUT);
  pinMode(pinD, OUTPUT);
  pinMode(pinE, OUTPUT);
  pinMode(pinF, OUTPUT);
  pinMode(pinG, OUTPUT);

}

// the loop routine runs over and over again forever:
void loop() {
  //0
  digitalWrite(pinA, LOW);        // turn the LED ON (HIGH is the voltage level)
  digitalWrite(pinB, LOW);        // turn the LED ON (HIGH is the voltage level)
  digitalWrite(pinC, LOW);        // turn the LED ON (HIGH is the voltage level)
  digitalWrite(pinD, LOW);        // turn the LED ON (HIGH is the voltage level)
  digitalWrite(pinE, LOW);        // turn the LED ON (HIGH is the voltage level)
  digitalWrite(pinF, LOW);        // turn the LED ON (HIGH is the voltage level)
  digitalWrite(pinG, HIGH);        // turn the LED ON (HIGH is the voltage level)
  delay(1000);                    // wait for a second

  //1
  digitalWrite(pinA, HIGH);        // turn the LED ON (HIGH is the voltage level)
  digitalWrite(pinB, LOW);        // turn the LED ON (HIGH is the voltage level)
  digitalWrite(pinC, LOW);        // turn the LED ON (HIGH is the voltage level)
  digitalWrite(pinD, HIGH);        // turn the LED ON (HIGH is the voltage level)
  digitalWrite(pinE, HIGH);        // turn the LED ON (HIGH is the voltage level)
  digitalWrite(pinF, HIGH);        // turn the LED ON (HIGH is the voltage level)
  digitalWrite(pinG, HIGH);        // turn the LED ON (HIGH is the voltage level)
  delay(1000);                    // wait for a second

  //H
  digitalWrite(pinA, HIGH);        // turn the LED ON (HIGH is the voltage level)
  digitalWrite(pinB, LOW);        // turn the LED ON (HIGH is the voltage level)
  digitalWrite(pinC, LOW);        // turn the LED ON (HIGH is the voltage level)
  digitalWrite(pinD, HIGH);        // turn the LED ON (HIGH is the voltage level)
  digitalWrite(pinE, LOW);        // turn the LED ON (HIGH is the voltage level)
  digitalWrite(pinF, LOW);        // turn the LED ON (HIGH is the voltage level)
  digitalWrite(pinG, LOW);        // turn the LED ON (HIGH is the voltage level)
  delay(1000);                    // wait for a second

  //8
  digitalWrite(pinA, LOW);        // turn the LED ON (HIGH is the voltage level)
  digitalWrite(pinB, LOW);        // turn the LED ON (HIGH is the voltage level)
  digitalWrite(pinC, LOW);        // turn the LED ON (HIGH is the voltage level)
  digitalWrite(pinD, LOW);        // turn the LED ON (HIGH is the voltage level)
  digitalWrite(pinE, LOW);        // turn the LED ON (HIGH is the voltage level)
  digitalWrite(pinF, LOW);        // turn the LED ON (HIGH is the voltage level)
  digitalWrite(pinG, LOW);        // turn the LED ON (HIGH is the voltage level)
  delay(1000);                    // wait for a second

}
