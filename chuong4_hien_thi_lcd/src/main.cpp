#include <Arduino.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);   // địa chỉ thường là 0x27 hoặc 0x3F

void khoi_tao_lcd_1602() {
  Wire.begin();        // khởi tạo I2C
  lcd.init();          // khởi tạo LCD
  lcd.backlight();     // bật đèn nền
  lcd.clear();         // xóa màn hình
}

void dich_noi_dung_phai_trai(uint8_t dong, String noi_dung, int toc_do) {
  if (dong > 1) return;

  int do_dai = noi_dung.length();

  for (int i = 0; i < do_dai + 16; i++) {
    lcd.setCursor(0, dong);

    String hien_thi = "";

    for (int j = 0; j < 16; j++) {
      int index = i - 16 + j;
      if (index >= 0 && index < do_dai) {
        hien_thi += noi_dung[index];
      } else {
        hien_thi += " ";
      }
    }

    lcd.print(hien_thi);
    delay(toc_do);
  }
}

void dich_noi_dung_trai_phai(uint8_t dong, String noi_dung, int toc_do) {
  if (dong > 1) return;

  int do_dai = noi_dung.length();

  for (int i = do_dai + 16; i >= 0; i--) {
    lcd.setCursor(0, dong);

    String hien_thi = "";

    for (int j = 0; j < 16; j++) {
      int index = i - 16 + j;
      if (index >= 0 && index < do_dai) {
        hien_thi += noi_dung[index];
      } else {
        hien_thi += " ";
      }
    }

    lcd.print(hien_thi);
    delay(toc_do);
  }
}

void setup() {
  khoi_tao_lcd_1602();
}

void loop() {
  // dich_noi_dung_phai_trai(0, "BYTRA ACADEMY", 500);
  // dich_noi_dung_trai_phai(1, "LCD 1602 I2C", 500);
  lcd.setCursor(0, 0);
  lcd.print("Bytra Academy");
}
