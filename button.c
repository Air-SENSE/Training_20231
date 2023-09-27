/**
 * @file button.c
 * @brief use button to change turn on/off led
 * @version 0.1
 * @date 2023-09-26
 * @copyright Copyright (c) 2023
 */

#define led 25
#define button 18
int buttonMode= 0;

void setup(){
    Serial.begin(115200);
    pinMode(led, OUTPUT);
    pinMode(button, INPUT_PULLUP);
}
void loop(){
    buttonMode=digitalRead(button);
    Serial.println(buttonMode);
    if(buttonMode){
        digitalWrite(led, LOW);
        Serial.println("led is off");
    }
    else{
        digitalWrite(led, HIGH);
        Serial.println("led is on");
    }
    delay(100);
}