#include "khoi_tao_bytra_kit_multi_display.h"
#include <Wire.h>

// ================== BUZZER ==================
#define BUZZER_PIN A3

// ================== 32 LED ĐƠN ==================
#define LED_SER   A0
#define LED_SRCLK A1
#define LED_RCLK  A2

// ================== MAX7219 7 ĐOẠN ==================
#define MAX_DIN 2
#define MAX_CS  3
#define MAX_CLK 4

// ================== MAX7219 MATRIX ==================
#define MATRIX_DIN 5
#define MATRIX_CS  6
#define MATRIX_CLK 7

// ================== LCD I2C ==================
#define LCD_ADDR 0x27   // đổi 0x3F nếu module bạn khác
#define OLED_ADDR 0x3C

// ===================================================
// GỬI DỮ LIỆU MAX7219
// ===================================================
void max7219_gui(byte address, byte data, byte din, byte cs, byte clk) {
    digitalWrite(cs, LOW);
    shiftOut(din, clk, MSBFIRST, address);
    shiftOut(din, clk, MSBFIRST, data);
    digitalWrite(cs, HIGH);
}

// ===================================================
// KHỞI TẠO MAX7219
// ===================================================
void khoi_tao_max7219(byte din, byte cs, byte clk) {

    pinMode(din, OUTPUT);
    pinMode(cs, OUTPUT);
    pinMode(clk, OUTPUT);

    max7219_gui(0x09, 0x00, din, cs, clk);
    max7219_gui(0x0A, 0x08, din, cs, clk);
    max7219_gui(0x0B, 0x07, din, cs, clk);
    max7219_gui(0x0C, 0x01, din, cs, clk);
    max7219_gui(0x0F, 0x00, din, cs, clk);

    for (int i = 1; i <= 8; i++) {
        max7219_gui(i, 0x00, din, cs, clk);
    }
}

// ===================================================
// TẮT 32 LED ĐƠN
// ===================================================
void tat_32_led_don() {

    pinMode(LED_SER, OUTPUT);
    pinMode(LED_SRCLK, OUTPUT);
    pinMode(LED_RCLK, OUTPUT);

    digitalWrite(LED_RCLK, LOW);
    for (int i = 0; i < 4; i++) {
        shiftOut(LED_SER, LED_SRCLK, MSBFIRST, 0x00);
    }
    digitalWrite(LED_RCLK, HIGH);
}

// ===================================================
// TẮT LCD (TẮT CẢ BACKLIGHT)
// ===================================================
void tat_lcd() {

    Wire.begin();
    Wire.beginTransmission(LCD_ADDR);
    Wire.write(0x00);  // tất cả bit LOW → tắt backlight
    Wire.endTransmission();
}

void tat_oled() {

    Wire.begin();

    Wire.beginTransmission(OLED_ADDR);
    Wire.write(0x00);     // Command mode
    Wire.write(0xAE);     // Display OFF
    Wire.endTransmission();
}


// ===================================================
// KHỞI TẠO TOÀN BỘ KIT
// ===================================================
void khoi_tao_bytra_kit_multi_display() {

    // Buzzer
    pinMode(BUZZER_PIN, OUTPUT);
    digitalWrite(BUZZER_PIN, LOW);

    // 32 LED đơn
    tat_32_led_don();

    // 7 đoạn
    khoi_tao_max7219(MAX_DIN, MAX_CS, MAX_CLK);

    // Matrix
    khoi_tao_max7219(MATRIX_DIN, MATRIX_CS, MATRIX_CLK);

    // LCD
    tat_lcd();

    // OLED
    tat_oled();
}

// ===================================================
// TẮT HẾT THIẾT BỊ
// ===================================================
void tat_het_thiet_bi() {

    digitalWrite(BUZZER_PIN, LOW);

    tat_32_led_don();

    for (int i = 1; i <= 8; i++) {
        max7219_gui(i, 0x00, MAX_DIN, MAX_CS, MAX_CLK);
        max7219_gui(i, 0x00, MATRIX_DIN, MATRIX_CS, MATRIX_CLK);
    }

    tat_lcd();
}
