Chuẩn rồi 👍. Bài **Struct – Union** nếu chỉ dừng lại ở “gom dữ liệu” thì hơi sơ sài, đặc biệt trong mảng **Embedded** thì 2 khái niệm này cực kỳ hay gặp. Mình viết bổ sung chi tiết hơn cho bạn nhé 👇

---

# 7. STRUCT – UNION

## 1. Struct

### Khái niệm

* `struct` cho phép gom nhiều biến **khác kiểu dữ liệu** vào một khối duy nhất.
* Mỗi trường có **vùng nhớ riêng biệt**, tổng dung lượng = tổng các trường (có thể thêm *padding* để căn chỉnh theo boundary).

### Ví dụ cơ bản

```c
typedef struct {
    int studentID;
    char name[50];
    double GPA;
} Student;
```

* `sizeof(Student)` ≈ 64 bytes (do padding, căn chỉnh 8 bytes cho `double`).

### Padding & Alignment

Trong Embedded, **memory alignment** rất quan trọng:

* Truy cập sai alignment có thể chậm, thậm chí gây **bus fault** trên ARM Cortex-M.
* Ví dụ:

```c
typedef struct {
    char a;   // 1 byte
    int b;    // 4 byte
    char c;   // 1 byte
} Example;
```

Trên ARM:

* `a` ở offset 0
* padding 3 byte để `b` nằm tại offset 4
* `b` = 4 byte
* `c` ở offset 8
* padding 3 byte để struct tổng kích thước = 12 bytes

📌 Dùng `#pragma pack(1)` hoặc `__attribute__((packed))` để **giảm padding** (nhưng trade-off tốc độ).
→ Rất hay dùng khi định nghĩa **packet giao tiếp** (CAN, UART, Modbus).

---

## 2. Union

### Khái niệm

* `union` cho phép nhiều trường dùng **chung một vùng nhớ**.
* Kích thước của union = kích thước trường lớn nhất.
* Tại một thời điểm, **chỉ có 1 trường là hợp lệ**.

### Ví dụ cơ bản

```c
typedef union {
    uint32_t u32;
    uint16_t u16[2];
    uint8_t  u8[4];
} Data32;
```

📌 Ứng dụng:

* **Type punning**: đọc cùng một vùng nhớ theo nhiều cách khác nhau.
* Dùng trong **protocol parsing** (ví dụ: tách 1 `uint32_t` thành 4 byte gửi UART).

---

## 3. Ứng dụng trong Embedded

### 3.1 Mapping thanh ghi (Register Map)

Các thanh ghi ngoại vi thường mô tả bằng struct:

```c
typedef struct {
    volatile uint32_t CR1;   // Control register 1
    volatile uint32_t CR2;   // Control register 2
    volatile uint32_t SR;    // Status register
} USART_TypeDef;

#define USART1 ((USART_TypeDef *)0x40011000UL)
```

→ Giúp truy cập `USART1->CR1 = 0x01;` thay vì viết địa chỉ “magic number”.

---

### 3.2 Truyền dữ liệu giao tiếp

Union để đóng gói/unpack dữ liệu:

```c
typedef union {
    float f;
    uint8_t bytes[4];
} FloatBytes;

void sendFloatUART(float value) {
    FloatBytes fb;
    fb.f = value;
    for (int i = 0; i < 4; i++) {
        UART_Send(fb.bytes[i]);
    }
}
```

→ Tránh lỗi `reinterpret_cast` hoặc `memcpy`.

---

### 3.3 Bitfield trong struct

Struct hỗ trợ **bit-field**, rất hữu ích trong **embedded control register**:

```c
typedef struct {
    uint32_t ENABLE : 1;
    uint32_t MODE   : 2;
    uint32_t SPEED  : 3;
    uint32_t        : 26; // reserved
} GPIO_CR_t;

volatile GPIO_CR_t * const GPIO_CR = (GPIO_CR_t *)0x40020000;

GPIO_CR->ENABLE = 1;
GPIO_CR->MODE = 2;
```

📌 Lưu ý:

* Bitfield **không portable** tuyệt đối (endian, compiler padding).
* Thường dùng với cùng một compiler/MCU trong dự án embedded → an toàn.

---

## 4. So sánh nhanh

| Đặc điểm  | Struct                                  | Union                                          |
| --------- | --------------------------------------- | ---------------------------------------------- |
| Bộ nhớ    | Tổng tất cả field (+padding)            | Bằng field lớn nhất                            |
| Đồng thời | Giữ nhiều field                         | Chỉ 1 field hợp lệ tại 1 thời điểm             |
| Ứng dụng  | Data model, register map                | Data overlay, protocol parsing                 |
| Embedded  | Peripheral register, sensor data struct | UART/CAN frame parsing, float↔bytes conversion |

---
Tóm lại:

* **Struct**: gom dữ liệu **đồng thời**, phù hợp để mô tả **cấu trúc phức tạp** hoặc **register map**.
* **Union**: dùng khi muốn **truy cập nhiều kiểu dữ liệu trên cùng một vùng nhớ**, rất hữu ích trong **truyền thông & parsing**.