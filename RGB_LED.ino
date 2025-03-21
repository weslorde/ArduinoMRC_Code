int pinoR = 9;
int pinoG = 10;
int pinoB = 11;

int valorR = 0;
int valorG = 0;
int valorB = 0;

// Fatores de correção — ajuste conforme necessário
float fatorR = 0.6;
float fatorG = 0.8;
float fatorB = 1.0;

void setup() {
  Serial.begin(9600);
  pinMode(pinoR, OUTPUT);
  pinMode(pinoG, OUTPUT);
  pinMode(pinoB, OUTPUT);
  Serial.println("Digite valores RGB (0-255) separados por vírgula. Ex: 255,100,50");
}

void loop() {
  if (Serial.available()) {
    String input = Serial.readStringUntil('\n');
    input.trim();

    int separador1 = input.indexOf(',');
    int separador2 = input.lastIndexOf(',');

    if (separador1 > 0 && separador2 > separador1) {
      valorR = input.substring(0, separador1).toInt();
      valorG = input.substring(separador1 + 1, separador2).toInt();
      valorB = input.substring(separador2 + 1).toInt();

      // Aplica compensação de brilho
      int rComp = constrain(valorR * fatorR, 0, 255);
      int gComp = constrain(valorG * fatorG, 0, 255);
      int bComp = constrain(valorB * fatorB, 0, 255);

      analogWrite(pinoR, rComp);
      analogWrite(pinoG, gComp);
      analogWrite(pinoB, bComp);

      Serial.print("Cor (corrigida): R=");
      Serial.print(rComp);
      Serial.print(" G=");
      Serial.print(gComp);
      Serial.print(" B=");
      Serial.println(bComp);
    } else {
      Serial.println("Formato inválido. Use: R,G,B");
    }
  }
}