const int trigPin = 9;
const int echoPin = 10;
long duracao;
float distancia;
void setup() {
  Serial.begin(9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}
void loop() {
  // Emite um pulso de 10 microsegundos
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
   // Mede o tempo do eco
  duracao = pulseIn(echoPin, HIGH);
  // Calcula a distância (em cm)
  distancia = duracao * 0.034 / 2;
  Serial.print("Distância: ");
  Serial.print(distancia);
  Serial.println(" cm");
  delay(500);
}
