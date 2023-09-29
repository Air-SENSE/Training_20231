/**
 * @file main_ver_3.cpp
 * @brief use interrupt to optimize
*/
#include <Arduino.h>
#define led 26
#define button 25

bool mode=0;
//mode=0 - led off
//mode=1 - led on
/**
 * @brief ISR function (Interrupt Service Routine)
 * When interrupt is triggered, ISR function will excute 
 * IRAM_ATTR is used to place the function in RAM, instead of Flash to execute faster
 */
void IRAM_ATTR change_Mode(){
    mode=!mode;
}
void setup(){
  pinMode(led, OUTPUT);
  pinMode(button,INPUT_PULLUP);
  attachInterrupt(button, change_Mode, RISING);
  Serial.begin(9600);
}

void loop(){
	if(mode){
      digitalWrite(led, HIGH);
      Serial.println("Light is on");
    } else {
      digitalWrite(led, LOW);
      Serial.println("Light is off");
      }
}
