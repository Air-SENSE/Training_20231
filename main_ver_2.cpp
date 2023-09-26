/**
 * @file main.cpp Version 2
 * @brief Use real button instead of Serial button
 * Use Serial button to avoid noise 
 * When press the button, the mode will change
*/
#include <Arduino.h>
#define led 26
#define button 25

bool mode=0;
//mode=0 - led off
//mode=1 - led on

void setup(){
  pinMode(led, OUTPUT);
  pinMode(button,INPUT_PULLUP);
  Serial.begin(9600);
}

void loop(){
  if(!digitalRead(button))mode=!mode;
    
	if(mode){
      digitalWrite(led, HIGH);
      Serial.println("Light is on");
    } else {
      digitalWrite(led, LOW);
      Serial.println("Light is off");
      }
  
}
