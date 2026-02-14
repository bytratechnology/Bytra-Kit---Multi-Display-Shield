#include <Arduino.h>
#include <MD_Parola.h>
#include <MD_MAX72XX.h>
#include <SPI.h>
#include <khoi_tao_bytra_kit_multi_display.h>

#define HARDWARE_TYPE MD_MAX72XX::FC16_HW
#define MAX_DEVICES 4

#define DATA_PIN 5
#define CS_PIN   6
#define CLK_PIN  7

MD_Parola matrix = MD_Parola(HARDWARE_TYPE, DATA_PIN, CLK_PIN, CS_PIN, MAX_DEVICES);

void khoi_tao_led_ma_tran() {
  matrix.begin();
  matrix.setIntensity(5);      // 0-15
  matrix.displayClear();
  matrix.setZoneEffect(0, true, PA_FLIP_LR);
  matrix.setZoneEffect(0, true, PA_FLIP_UD);
}

void setup() {
  khoi_tao_bytra_kit_multi_display();
  khoi_tao_led_ma_tran();
  matrix.displayText(
    "HAPPY NEW YEAR 2026", // chuoi hien thi
    PA_LEFT,            // canh trái
    100,                 // tốc độ (ms)
    0,                  // thời gian dừng
    PA_SCROLL_RIGHT,     // hiệu ứng vào
    PA_SCROLL_RIGHT      // hiệu ứng ra
  );  
}

void loop() {
  if (matrix.displayAnimate()) {
    matrix.displayReset();
  }
}

