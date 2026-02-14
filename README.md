# BytraKit - Multi Display Shield

Bộ kit học lập trình nhúng với Arduino Nano, hỗ trợ đa loại màn hình và thiết bị hiển thị.

![Bytra Technology](https://img.shields.io/badge/Bytratechnology-Bytra%20Kit-blue)

## Giới thiệu

BytraKit Multi Display Shield là board mở rộng (shield) được thiết kế để kết nối với Arduino Nano, tích hợp nhiều module hiển thị và thiết bị ngoại vi giúp học tập và phát triển dự án nhúng.

## Tính năng

- **Buzzer** – Còi báo, phát âm thanh
- **32 LED đơn** – Điều khiển qua shift register (74HC595)
- **Nút bấm** – 5 nút nhấn (chân 8, 9, 10, 11, 12)
- **Led 7 đoạn** – Module MAX7219
- **LED Matrix** – Ma trận LED MAX7219
- **LCD I2C** – Màn hình LCD 16x2 giao tiếp I2C
- **OLED** – Màn hình OLED SH1106/SSD1306

## Cấu trúc dự án

| Thư mục | Mô tả |
|---------|-------|
| `chuong0_bat_tat_buzzer` | Điều khiển còi buzzer |
| `chuong1_32led_don` | Điều khiển 32 LED đơn qua shift register |
| `chuong2_nut_nhan` | Đọc nút bấm và điều khiển LED |
| `chuong3_module_led_7doan` | Hiển thị trên LED 7 đoạn MAX7219 |
| `chuong4_hien_thi_lcd` | Hiển thị văn bản trên LCD I2C |
| `chuong5_hien_thi_oled` | Hiển thị trên màn hình OLED |
| `chuong6_module_led_matrix` | Điều khiển ma trận LED MAX7219 |
| `khoi_tao_bytra_kit_multi_display` | Thư viện khởi tạo và điều khiển toàn bộ kit |

## Yêu cầu phần cứng

- Arduino Nano (ATmega328P)
- BytraKit Multi Display Shield
- Cáp USB (để nạp code)

## Yêu cầu phần mềm

- [PlatformIO](https://platformio.org/) (khuyến nghị) hoặc Arduino IDE

## Cài đặt

### Sử dụng PlatformIO

1. Cài đặt [PlatformIO](https://platformio.org/install)
2. Mở thư mục từng chapter (ví dụ: `chuong0_bat_tat_buzzer`)
3. Build và upload:

```bash
cd chuong0_bat_tat_buzzer
pio run -t upload
```

### Sử dụng Arduino IDE

1. Copy nội dung file `src/main.cpp` vào Arduino IDE
2. Cài đặt thư viện cần thiết (nếu có)
3. Chọn board: **Arduino Nano** với bộ xử lý **ATmega328P**
4. Chọn cổng COM và nhấn Upload

## Sơ đồ chân (Pinout)

| Thiết bị | Chân Arduino |
|----------|--------------|
| Buzzer | A3 |
| 32 LED (SER) | A0 |
| 32 LED (SRCLK) | A1 |
| 32 LED (RCLK) | A2 |
| LED 7 đoạn (DIN, CS, CLK) | 2, 3, 4 |
| LED Matrix (DIN, CS, CLK) | 5, 6, 7 |
| Nút bấm | 8, 9, 10, 11, 12 |
| LCD I2C | SDA, SCL |
| OLED | SDA, SCL |

## Sử dụng thư viện khởi tạo

Để khởi tạo toàn bộ thiết bị trên kit và tắt các thiết bị không dùng:

```cpp
#include <khoi_tao_bytra_kit_multi_display.h>

void setup() {
  khoi_tao_bytra_kit_multi_display();  // Khởi tạo và tắt thiết bị không dùng
  // ... code của bạn
}

void loop() {
  // ...
}
```

Để tắt tất cả thiết bị trước khi kết thúc:

```cpp
tat_het_thiet_bi();
```

## Đóng góp

Mọi đóng góp đều được chào đón! Vui lòng tạo issue hoặc pull request.

## Giấy phép

Dự án được phát hành dưới giấy phép MIT.

## Liên hệ

- **Bytra Technology** - [GitHub](https://github.com/bytratechnology)
