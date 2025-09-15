
# BIT MASK

- Bit mask là kỹ thuật sử lý bit dùng để lưu trữ hoặc thao tác nó với các cờ hoặc trạng thái.

- Ứng dụng thường được dùng trong việc tối ưu hoá bộ nhớ, giúp chương trình chạy nhanh hơn, quản lý các trạng thái, quyền truy cập của các đối tượng.

## NOT bitwise

- Dùng để đảo trạng thái bit hiện tại 

```C
int a = 0b01    // = 1
int b = ~a  // result = -2
```

## AND bitwise

```C
Bảng Sự Thật
X1  X2  Y
0   0   0
0   1   0
1   0   0
1   1   1
```

## OR bitwise

```C
Bảng Sự Thật
X1  X2  Y
0   0   0
0   1   1
1   0   1
1   1   1
```

## XOR bitwise

Nếu tổng số bit 1 trên cột là lẻ thì nó là 1

```C
Bảng Sự Thật
Y = X1 ^ X2
X1  X2  Y
0   0   0
0   1   1
1   0   1
1   1   0
```

## Shift bitwise
Shift bit có 2 loại là:

- Shift Right: là dịch bit sang bên phải và thêm số 0 vào bên trái số bit đã dịch

```C
result = 0b0101 >> 1
result // 0b0010 
```

- Shift Left: là dịch bit sang bên trái và thêm số 0 vào bên phải số bit đã dịch

```C
result = 0b0101 << 1
result // 0b1010
```

## 1. Quản lý trạng thái bằng biến cờ (flags)

Thay vì dùng nhiều biến `bool`, ta gộp lại trong 1 byte:

```c
#include <stdio.h>
#include <stdint.h>

#define FLAG_SENSOR1   (1 << 0)   // bit 0
#define FLAG_SENSOR2   (1 << 1)   // bit 1
#define FLAG_MOTOR_ON  (1 << 2)   // bit 2

uint8_t status = 0;

int main() {
    // Bật sensor1
    status |= FLAG_SENSOR1;

    // Kiểm tra sensor1 có bật chưa
    if (status & FLAG_SENSOR1) {
        printf("Sensor1 is ON\n");
    }

    // Tắt sensor1
    status &= ~FLAG_SENSOR1;

    // Toggle motor
    status ^= FLAG_MOTOR_ON;
}
```

 Đây là cách thường dùng trong hệ thống nhúng để tiết kiệm RAM và gom trạng thái.

---

## 2. Truy cập thanh ghi (Register)

Ví dụ bật/tắt LED trên STM32 thông qua thanh ghi `GPIOx_ODR` (Output Data Register):

```c
#define LED_PIN   (1 << 5)    // LED ở chân số 5

// Bật LED
GPIOA->ODR |= LED_PIN;

// Tắt LED
GPIOA->ODR &= ~LED_PIN;

// Đảo trạng thái LED
GPIOA->ODR ^= LED_PIN;
```

 Đây chính là lý do **bitmask** cực kỳ quan trọng trong embedded, vì hầu hết register đều dạng **bit field**.

---

## 3. Kiểm tra trạng thái trong Peripheral Register

Ví dụ đọc trạng thái nút nhấn từ thanh ghi `GPIOx_IDR` (Input Data Register):

```c
#define BUTTON_PIN  (1 << 13)

if (GPIOC->IDR & BUTTON_PIN) {
    // Button đang được nhấn
} else {
    // Button thả
}
```

---

## 4. Kết hợp nhiều flag

Khi muốn bật nhiều thứ cùng lúc:

```c
status |= (FLAG_SENSOR1 | FLAG_SENSOR2);   // bật cả 2 sensor

status &= ~(FLAG_SENSOR1 | FLAG_MOTOR_ON); // tắt sensor1 và motor
```

---

## 5. Cấu hình Peripheral bằng bitmask

Ví dụ cấu hình UART Baud Rate hoặc mode thông qua thanh ghi Control:

```c
#define USART_CR1_UE    (1 << 13)  // USART Enable
#define USART_CR1_TE    (1 << 3)   // Transmitter Enable
#define USART_CR1_RE    (1 << 2)   // Receiver Enable

USART1->CR1 = (USART_CR1_UE | USART_CR1_TE | USART_CR1_RE);  // Bật cả 3
```

---

Tóm lại:

* **Flag quản lý trạng thái** → tiện cho hệ thống RTOS/event-driven.
* **Thanh ghi GPIO/UART/SPI** → set/clear bằng bitmask.
* **Tối ưu bộ nhớ** → thay vì 8 biến bool, gom hết vào 1 byte.