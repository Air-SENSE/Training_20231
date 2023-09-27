
#define pinLed 27
#define button 19

void setup(){
  Serial.begin(115200);
  pinMode(pinLed, OUTPUT);
  pinMode(button, INPUT);
}
void loop(){
  int buttonMode=digitalRead(button);
  if(buttonMode){
    digitalWrite(pinLed, LOW);
  }else{
    digitalWrite(pinLed, HIGH);
  }
  delay(100);
}