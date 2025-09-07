# 1. EXTERN – STATIC – VOLATILE – REGISTER

##  Extern

**Là gì:**

* `extern` là từ khóa để khai báo một biến/tên hàm **được định nghĩa ở file khác**, cho phép chia sẻ dữ liệu/hàm giữa nhiều file.

**Vì sao được tạo ra:**

* Trong C, mỗi file biên dịch thành 1 **translation unit** độc lập. Nếu không có `extern`, mỗi file chỉ thấy biến/hàm trong phạm vi nó định nghĩa.
* `extern` cho phép **liên kết toàn cục** giữa các file.

**Giải quyết vấn đề gì:**

* Chia sẻ dữ liệu/hàm chung giữa nhiều module mà không cần định nghĩa lại.
* Tránh lỗi **multiple definition** (nếu khai báo lại biến toàn cục).

**Ví dụ:**
*File A.c*:

```c
int num = 10;   // Định nghĩa biến toàn cục
```

*File B.c*:

```c
#include <stdio.h>
extern int num; // Khai báo sử dụng lại
int main() {
    printf("num = %d\n", num);
    return 0;
}
```

**Ứng dụng trong Embedded:**

* Dùng để chia sẻ biến trạng thái giữa nhiều module (VD: biến `sensor_value` định nghĩa ở driver, nhưng `extern` ở main.c).
* Giúp tổ chức project **multi-file** (driver, HAL, app layer).

---

##  Static

### Local Static

**Là gì:**

* Biến `static` cục bộ trong hàm **giữ nguyên giá trị sau mỗi lần gọi hàm**, và tồn tại suốt chương trình.

**Vì sao được tạo ra:**

* Nếu dùng biến local bình thường, giá trị bị hủy khi hàm kết thúc. Nhiều trường hợp ta cần **lưu trạng thái bên trong hàm** mà không global.

**Giải quyết vấn đề gì:**

* Lưu **state** bên trong function mà không cần biến toàn cục.

**Ví dụ:**

```c
void counter() {
    static int count = 0; // chỉ khởi tạo 1 lần
    count++;
    printf("count = %d\n", count);
}
```

**Ứng dụng Embedded:**

* Dùng để lưu **state machine state**, **debounce button counter**, biến delay trong ISR.

---

### Global Static

**Là gì:**

* Biến `static` toàn cục chỉ có phạm vi **trong file đó**, không thể `extern` ở file khác.

**Vì sao được tạo ra:**

* Tránh “đụng độ tên” khi nhiều file có biến/hàm trùng tên.

**Giải quyết vấn đề gì:**

* Tạo biến/hàm **private trong file** (giống như `private` trong OOP).

**Ví dụ:**

```c
static int internal_data = 5; // chỉ dùng trong file này
```

**Ứng dụng Embedded:**

* Dùng cho **driver nội bộ**, không muốn module khác truy cập trực tiếp.
* VD: `static buffer_uart[64]` trong `uart_driver.c` chỉ driver dùng, bên ngoài không thấy.

---

##  Volatile

**Là gì:**

* Từ khóa báo cho compiler biết: “Đừng tối ưu biến này, giá trị của nó **có thể thay đổi bất kỳ lúc nào** bởi yếu tố ngoài chương trình (ISR, hardware, DMA).”

**Vì sao được tạo ra:**

* Compiler thường tối ưu hóa biến (cache vào thanh ghi). Điều này gây lỗi khi biến bị thay đổi ngoài luồng.

**Giải quyết vấn đề gì:**

* Đảm bảo chương trình **luôn đọc giá trị thật từ RAM/hardware**, không dùng giá trị cache.

**Ví dụ:**

```c
volatile int flag = 0; 

void ISR_Handler() {
    flag = 1; // ISR thay đổi giá trị
}

int main() {
    while (!flag); // chờ ISR set flag
    printf("Flag set!\n");
}
```

**Ứng dụng Embedded:**

* Dùng cho biến được **ISR set/clear**.
* Biến trạng thái đọc từ **thanh ghi ngoại vi (GPIO, UART, ADC)**.
* Biến dùng trong **DMA, Timer interrupt**.

---

##  Register

**Là gì:**

* Từ khóa `register` gợi ý compiler nên đặt biến trong **thanh ghi CPU** để truy cập nhanh hơn thay vì RAM.

**Vì sao được tạo ra:**

* Truy cập register CPU nhanh hơn RAM nhiều. Trước đây (máy đời cũ), điều này rất quan trọng.

**Giải quyết vấn đề gì:**

* Tối ưu tốc độ cho biến dùng nhiều lần trong loop.

**Ví dụ:**

```c
void sum_array(int *arr, int n) {
    register int i; // compiler sẽ ưu tiên cho vào thanh ghi
    int sum = 0;
    for (i = 0; i < n; i++) {
        sum += arr[i];
    }
}
```

**Ứng dụng Embedded:**

* Ngày nay compiler đã tự tối ưu tốt, `register` ít khi cần.
* Nhưng trong **Embedded bare-metal**, vẫn gặp ở code cũ hoặc khi muốn hint compiler cho biến loop-critical.

---

Tóm lại:

* **Extern** → chia sẻ biến/hàm giữa file.
* **Static local** → giữ giá trị qua lần gọi hàm.
* **Static global** → ẩn biến/hàm trong file.
* **Volatile** → đảm bảo không bị tối ưu, dùng cho ISR/hardware.
* **Register** → tối ưu tốc độ, nay ít dùng vì compiler hiện đại.