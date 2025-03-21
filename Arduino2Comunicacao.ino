#include <SoftwareSerial.h>
SoftwareSerial serialOutroArduino(10, 11); // (TX, RX)
const int ledPin = 13;
bool estadoLED = false;
void setup() {
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, estadoLED);
  Serial.begin(9600);              // Comunicação com o PC
  serialOutroArduino.begin(9600);  // Comunicação com o outro Arduino
  Serial.println("Sistema pronto.");
}
void loop() {
  // Envia mensagem do PC para o outro Arduino
  if (Serial.available()) {
	String msg = Serial.readStringUntil('\n');
    serialOutroArduino.println(msg);
  } 
  // Recebe mensagem do outro Arduino
  if (serialOutroArduino.available()) {
	String recebido = serialOutroArduino.readStringUntil('\n');
    Serial.println("Recebido do outro Arduino: " + recebido);
	// Verifica se a mensagem contém "LED"
	recebido.trim(); // Remove espaços e quebras
    recebido.toUpperCase(); // Deixa tudo maiúsculo pra garantir
	if (recebido == "LED") {
  	estadoLED = !estadoLED; // Inverte o estado
      digitalWrite(ledPin, estadoLED);
      Serial.println("LED alterado para: " + String(estadoLED ? "LIGADO" : "DESLIGADO"));
	}
  }
}
