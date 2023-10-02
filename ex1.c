#define pinLed 25
#define button 21
int buttonMode=0;


void IRAM_ATTR Interrupts(){
  buttonMode=digitalRead(button);
}
void setup(){
  Serial.begin(115200);
  pinMode(pinLed, OUTPUT);
  pinMode(button, INPUT);
  attachInterrupt(digitalPinToInterrupt(button), Interrupts, CHANGE);

}
void loop(){

  if(buttonMode){
    digitalWrite(pinLed, LOW);
  }else{
    digitalWrite(pinLed, HIGH);
  }
  delay(100);
}
