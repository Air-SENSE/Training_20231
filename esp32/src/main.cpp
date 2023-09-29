#include <Arduino.h>
# define button 13
# define led 5
int press = 0;

void IRAM_ATTR handle(){
  press = digitalRead(button);
}
void setup() {
  Serial.begin(115200);
  pinMode(led, OUTPUT);
  pinMode(button, INPUT);
  attachInterrupt(button, handle, CHANGE);
}

void loop() {
  // press = digitalRead(13);
  // Serial.println(press);
  Serial.println(press);
  if(press == LOW){
    digitalWrite(led, HIGH);
  }
  else{
    digitalWrite(led, LOW);
  }

}