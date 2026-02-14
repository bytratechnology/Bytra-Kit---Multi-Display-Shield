#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SH110X.h>
#include <khoi_tao_bytra_kit_multi_display.h>


Adafruit_SH1106G display(128, 64, &Wire, -1);

void khoi_tao_oled() {

  // Khởi tạo I2C
  Wire.begin();

  // Khởi tạo OLED
  if (!display.begin(0x3C, true)) {
    while (1);   // nếu lỗi thì đứng tại đây
  }

  // Xóa màn hình
  display.clearDisplay();
  display.setTextColor(SH110X_WHITE);

  // Hiển thị thông báo khởi động
  display.setTextSize(1);
  display.setCursor(10, 10);
  display.println("Bytra Multi Display");

  display.setTextSize(1);
  display.setCursor(10, 25);
  display.println("OLED Ready");

  display.display();
}

void setup() {
  khoi_tao_oled();
  khoi_tao_bytra_kit_multi_display();
  
}

void loop() {
}
