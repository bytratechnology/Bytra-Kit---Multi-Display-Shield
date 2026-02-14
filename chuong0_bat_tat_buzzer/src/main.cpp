#include <Arduino.h>

void khoi_tao_buzzer() {
  pinMode(A3, OUTPUT);
  digitalWrite(A3, LOW);
}

void setup() {
  khoi_tao_buzzer();
}

void loop() {
  digitalWrite(A3, HIGH);
  delay(100);
  
  digitalWrite(A3, LOW);
  delay(100);
}
