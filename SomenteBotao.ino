const int botaoPin = 12;
void setup() {
  pinMode(botaoPin, INPUT_PULLUP);
  Serial.begin(9600);
}
void loop() {
  if (digitalRead(botaoPin) == LOW) { // LOW porque o botão está no GND
    Serial.println("Botão pressionado!");
    delay(200);
  }
}
