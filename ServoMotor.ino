#include <Servo.h>
Servo meuServo;
void setup() {
  meuServo.attach(9); // Pino de controle do servo
}
void loop() {
  int AnguloInicial = 0;
  int AnguloFinal = 180;

  // Gira de 0° a 180°
  for (int angulo = AnguloInicial; angulo <= AnguloFinal; angulo += 1) {
    meuServo.write(angulo);
    delay(15);
  }
  delay(500);
  // Volta de 180° a 0°
  for (int angulo = AnguloFinal; angulo >= AnguloInicial; angulo -= 1) {
    meuServo.write(angulo);
    delay(15);
  }
  delay(500);
}
