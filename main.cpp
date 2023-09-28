#include <Arduino.h>
#define button 15 
#define led 2 

void setup() {
  pinMode(button, INPUT);
  pinMode(led, OUTPUT);
  Serial.begin(115200);
}

void loop() {
  // Đọc trạng thái của nút
  int buttonState = digitalRead(button);

  // Nếu nút nhấn được nhấn
  if (buttonState) {
    // Đổi trạng thái của LED
    digitalWrite(led, !digitalRead(led));
  }
  delay(100);
}
