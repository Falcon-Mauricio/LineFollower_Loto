#include <Arduino.h>

// Pines motores
const int IN1_A = 19;
const int IN2_A = 21;
const int IN1_B = 22;
const int IN2_B = 23;

// Canales PWM
const int canalA1 = 0;
const int canalA2 = 1;
const int canalB1 = 2;
const int canalB2 = 3;

// Configuración PWM
const int frecuenciaPWM = 8000;   // 8 kHz
const int resolucionPWM = 12;     // 12 bits
const int PWM_mitad = 1028;       // 50% de 4095

void detenerMotores() {
  ledcWrite(canalA1, 0);
  ledcWrite(canalA2, 0);
  ledcWrite(canalB1, 0);
  ledcWrite(canalB2, 0);
}

void avanzar() {
  ledcWrite(canalA1, PWM_mitad);
  ledcWrite(canalA2, 0);

  ledcWrite(canalB1, PWM_mitad);
  ledcWrite(canalB2, 0);
}

void retroceder() {
  ledcWrite(canalA1, 0);
  ledcWrite(canalA2, PWM_mitad);

  ledcWrite(canalB1, 0);
  ledcWrite(canalB2, PWM_mitad);
}

void setup() {
  // Configurar canales PWM
  ledcSetup(canalA1, frecuenciaPWM, resolucionPWM);
  ledcSetup(canalA2, frecuenciaPWM, resolucionPWM);
  ledcSetup(canalB1, frecuenciaPWM, resolucionPWM);
  ledcSetup(canalB2, frecuenciaPWM, resolucionPWM);

  // Asociar pines con canales
  ledcAttachPin(IN1_A, canalA1);
  ledcAttachPin(IN2_A, canalA2);
  ledcAttachPin(IN1_B, canalB1);
  ledcAttachPin(IN2_B, canalB2);

  Serial.begin(115200);
}

void loop() {
  Serial.println("Avanzando...");
  avanzar();
  delay(3000);

  Serial.println("Detenido...");
  detenerMotores();
  delay(1000);

  Serial.println("Retrocediendo...");
  retroceder();
  delay(3000);

  Serial.println("Detenido...");
  detenerMotores();
  delay(1000);
}
