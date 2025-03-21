int ledPin = 13;	// LED no pino 13
void setup() {
  pinMode(ledPin, OUTPUT);	// LED como saída
}
void loop() {
digitalWrite(ledPin, HIGH); // Liga o LED se apertar o botão
delay(1000);
digitalWrite(ledPin, LOW);  // Desliga o LED se soltar
delay(1000);
} 
