#include<Arduino.h>
#define BUTTON_PIN 26  
#define LED_PIN    18  


int led_state = LOW;    
int button_state;       

void setup() {
    
    Serial.begin(115200);
    Serial.println("Hello, ESP32!");
    pinMode(LED_PIN, OUTPUT);
    pinMode(BUTTON_PIN, INPUT_PULLUP);
    button_state = digitalRead(BUTTON_PIN);
}

void loop() {
    button_state = digitalRead(BUTTON_PIN);
    delay(100);
    if (button_state == LOW) {
      Serial.println("The button is pressed");
      // toggle state of LED
      digitalWrite(LED_PIN, HIGH);
      delay(5000);
      digitalWrite(LED_PIN, LOW);
      delay(1000);
    }else{
      digitalWrite(LED_PIN, LOW);
      delay(1000);
    } 