/**
 * @file main.cpp
 * @brief Use Serial button to change mode on/off of the light
 * When press 'p' the mode will change
*/
#include <Arduino.h>
#define led 26

bool mode=0;
char press;

void setup(){
  pinMode(led, OUTPUT);
  Serial.begin(9600);
}

void loop(){
  press=Serial.read();
  if(press=='p')mode=!mode;
  
  if(mode){
    digitalWrite(led, HIGH);
    Serial.println("Light is on");
  } else {
      digitalWrite(led, LOW);
      Serial.println("Light is off");
      }

}
