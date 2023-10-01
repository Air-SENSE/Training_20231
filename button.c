/**
 * @file button.c
 * @brief use button to change turn on/off led
 * @version 0.1
 * @date 2023-09-26
 * @copyright Copyright (c) 2023
 */

#define led 25
#define button 18
int buttonMode=0;

void IRAM_ATTR isrFunction() {
  buttonMode=digitalRead(button);
}
void setup(){
    Serial.begin(115200);
    pinMode(led, OUTPUT);
    pinMode(button, INPUT);
    attachInterrupt(digitalPinToInterrupt(button), isrFunction, CHANGE);
}
void loop(){
    if(buttonMode){
        digitalWrite(led, LOW);
        Serial.println("led is off");
    }
    else{
        digitalWrite(led, HIGH);
        Serial.println("led is on");
    }
    delay(1000);
}

