const int ledPin = 2;
const int buttonPin = 4;
int stateLed = 0;

void setup() {
  Serial.begin(115200);
  Serial.println("Hello, ESP32!");
  pinMode (ledPin, OUTPUT);
  pinMode (buttonPin, INPUT);
}

void loop() {
  if (digitalRead(buttonPin) == HIGH) {
    int stateLed = digitalRead(ledPin);
    digitalWrite (ledPin, 1 - stateLed);
  } 
}
