#include <Arduino.h>

#define SER   A0
#define SRCLK A1
#define RCLK  A2

void khoi_tao_32led_don() {
  pinMode(SER, OUTPUT);
  pinMode(SRCLK, OUTPUT);
  pinMode(RCLK, OUTPUT);

  digitalWrite(RCLK, LOW);
  for (int i = 0; i < 4; i++) {
    shiftOut(SER, SRCLK, MSBFIRST, 0x00);
  }
  digitalWrite(RCLK, HIGH);
}

void bat_tat_led_theo_cum(int cum0, int cum1, int cum2, int cum3) {
  byte data[4];

  data[0] = cum0 ? 0xFF : 0x00;
  data[1] = cum1 ? 0xFF : 0x00;
  data[2] = cum2 ? 0xFF : 0x00;
  data[3] = cum3 ? 0xFF : 0x00;

  digitalWrite(RCLK, LOW);
  for (int i = 3; i >= 0; i--) {
    shiftOut(SER, SRCLK, MSBFIRST, data[i]);
  }
  digitalWrite(RCLK, HIGH);
}

void sang_dan_trai_sang_phai() {
  static uint32_t data = 0;
  static int i = 0;

  data |= (1UL << i);

  digitalWrite(RCLK, LOW);
  shiftOut(SER, SRCLK, MSBFIRST, (data >> 24) & 0xFF);
  shiftOut(SER, SRCLK, MSBFIRST, (data >> 16) & 0xFF);
  shiftOut(SER, SRCLK, MSBFIRST, (data >> 8) & 0xFF);
  shiftOut(SER, SRCLK, MSBFIRST, data & 0xFF);
  digitalWrite(RCLK, HIGH);

  delay(80);

  i++;
  if (i >= 32) {
    data = 0;
    i = 0;
    delay(300);
  }
}

void setup() {
  khoi_tao_32led_don();
  bat_tat_led_theo_cum(0, 0, 0, 1);
}

void loop() {
  sang_dan_trai_sang_phai();
}
