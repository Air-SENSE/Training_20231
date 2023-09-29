#include <Arduino.h>
const int ledPin = 2;
const int buttonPin = 4;
volatile int ledState = 0;

void buttonInterrupt() {
  ledState = 1 - ledState;
  digitalWrite(ledPin, ledState);
}
void setup() {
  Serial.begin(115200);
  pinMode (ledPin, OUTPUT);
  pinMode (buttonPin, INPUT);
  attachInterrupt(digitalPinToInterrupt(buttonPin), buttonInterrupt, FALLING);
}

void loop() {
 
}
