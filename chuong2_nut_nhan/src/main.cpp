#include <Arduino.h>
#include <khoi_tao_bytra_kit_multi_display.h>

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

void khoi_tao_nut_nhan() {
  pinMode(8, INPUT);
  pinMode(9, INPUT);
  pinMode(10, INPUT);
  pinMode(11, INPUT);
  pinMode(12, INPUT);
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

bool doc_nut_nhan_co_chong_doi(uint8_t pin) {
  if (digitalRead(pin) == LOW) {
    delay(20);
    if (digitalRead(pin) == LOW) {
      while (digitalRead(pin) == LOW){};
      delay(20);
      return true;
    }
  }
  return false;
}

int trang_thai = 0;

void setup(){
  khoi_tao_bytra_kit_multi_display();
  khoi_tao_32led_don();
  khoi_tao_nut_nhan();
}

void loop(){
  if(doc_nut_nhan_co_chong_doi(8)){
    trang_thai++;
    if (trang_thai > 1) trang_thai = 0;
  }

  if(trang_thai == 1){
    bat_tat_led_theo_cum(1, 0, 0, 0);
  } else {
    bat_tat_led_theo_cum(0, 0, 0, 0);
  }
}
