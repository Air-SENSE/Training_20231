/**
 * @file Bai 1
 * @author Trương Quốc Ánh
 * @brief Using Button to change the led status
 * @version 0.2
 * @date 2023-09-29
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#include <Arduino.h>
#define LED 14
#define BUTTON 12
bool ledStatus = 0;
 void IRAM_ATTR isr()
{
    ledStatus = !ledStatus;
}
void setup() {
  // put your setup code here, to run once:
 Serial.begin(9600);
 pinMode(LED, OUTPUT);
 pinMode(BUTTON, INPUT_PULLUP);
 attachInterrupt(BUTTON, isr, FALLING);
}

void loop() {
  // put your main code here, to run repeatedly:

  if(ledStatus)
  {
    digitalWrite(LED, HIGH);
    Serial.print("LED ON\n");
  }
  else 
  {
    digitalWrite(LED, LOW);
    Serial.print("LED OFF\n");
  }
  delay(100);
}

