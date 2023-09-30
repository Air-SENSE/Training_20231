#include "main.h"

#define GPIO_BUTTON_INPUT 0
#define GPIO_LED_OUTPUT 2

bool isPressed = false;

void IRAM_ATTR isr() {
  isPressed = !isPressed;
}

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(GPIO_LED_OUTPUT, OUTPUT);
  pinMode(GPIO_BUTTON_INPUT, INPUT_PULLUP);

  attachInterrupt(GPIO_BUTTON_INPUT, isr, FALLING);

}

void loop() {
  // put your main code here, to run repeatedly:
  if(isPressed) {
    digitalWrite(GPIO_LED_OUTPUT, HIGH);
  } else {
    digitalWrite(GPIO_LED_OUTPUT, LOW);
  }
  
  Serial.println(isPressed);
  delay(100);
}
