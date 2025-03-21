int ledPin = 8;	// LED no pino 8
int botaoPin = 12;   // Botão no pino 12
int estadoBotao = 0;  //Nao mudar
void setup() {
  pinMode(ledPin, OUTPUT);	// LED como saída
  pinMode(botaoPin, INPUT_PULLUP);   // Botão como entrada
}
void loop() {
  estadoBotao = digitalRead(botaoPin); // Lê o botão
  if (estadoBotao == HIGH) {
    digitalWrite(ledPin, HIGH); // Liga o LED se apertar o botão
  } else {
    digitalWrite(ledPin, LOW);  // Desliga o LED se soltar
  }
} 
