#include <Arduino.h>

#define MAX_DIN 2
#define MAX_CS  3
#define MAX_CLK 4

void max7219_gui(byte address, byte data) {
  digitalWrite(MAX_CS, LOW);
  shiftOut(MAX_DIN, MAX_CLK, MSBFIRST, address);
  shiftOut(MAX_DIN, MAX_CLK, MSBFIRST, data);
  digitalWrite(MAX_CS, HIGH);
}

void khoi_tao_module_led_7doan() {
  pinMode(MAX_DIN, OUTPUT);
  pinMode(MAX_CS, OUTPUT);
  pinMode(MAX_CLK, OUTPUT);

  max7219_gui(0x09, 0x00); 
  max7219_gui(0x0A, 0x08);
  max7219_gui(0x0B, 0x07);
  max7219_gui(0x0C, 0x01);
  max7219_gui(0x0F, 0x00);

  for (int i = 1; i <= 8; i++) {
    max7219_gui(i, 0x00);
  }
}

void hien_thi_led_7doan_vi_tri(uint8_t vi_tri, byte ma_nhi_phan) {
  if (vi_tri < 1 || vi_tri > 8) return;
  max7219_gui(vi_tri, ma_nhi_phan);
}

uint8_t led_7doan[10] = {
  0b01111110, // 0
  0b00110000, // 1
  0b01101101, // 2
  0b01111001, // 3
  0b00110011, // 4
  0b01011011, // 5
  0b01011111, // 6
  0b01110000, // 7
  0b01111111, // 8
  0b01111011  // 9
};

void setup() {
  khoi_tao_module_led_7doan();
}

void loop() {
  for(int so = 0; so < 100; so++)
  {
    int hang_chuc = so / 10;
    int hang_donvi = so % 10;

    // Nếu hàng chục = 0 thì tắt LED vị trí 1
    if(hang_chuc == 0)
    {
        hien_thi_led_7doan_vi_tri(2, 0x00);  // 0x00 = tắt LED
    }
    else
    {
        hien_thi_led_7doan_vi_tri(2, led_7doan[hang_chuc]);
    }

    hien_thi_led_7doan_vi_tri(1, led_7doan[hang_donvi]);

    delay(500);
  }
}