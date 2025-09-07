# 1. STDARG (Standard Argument Handling)

`stdarg.h` cho phép viết **hàm nhận số lượng tham số không cố định** (variadic function).

## Các Macro chính

| Macro      | Ý nghĩa                                                    | Ví dụ dùng trong hàm         |
| ---------- | ---------------------------------------------------------- | ---------------------------- |
| `va_list`  | Khai báo biến dùng để lưu trạng thái danh sách tham số.    | `va_list args;`              |
| `va_start` | Khởi tạo danh sách tham số.                                | `va_start(args, count);`     |
| `va_arg`   | Lấy tham số kế tiếp, ép kiểu dữ liệu mong muốn.            | `int x = va_arg(args, int);` |
| `va_end`   | Kết thúc quá trình đọc tham số, giải phóng biến `va_list`. | `va_end(args);`              |

---

## Nguyên tắc khi khai báo hàm variadic

* Hàm phải có **ít nhất 1 tham số cố định**.
* Tham số cuối cố định chính là mốc cho `va_start`.
* Số lượng hoặc kiểu của các tham số còn lại phải được xác định bằng:

  * Tham số đếm (ví dụ `count`), hoặc
  * Chuỗi format (ví dụ `printf` dùng `%d, %f, ...`).

---

## Ví dụ 1: Tính tổng với `count`

```c
#include <stdio.h>
#include <stdarg.h>

int sum(int count, ...) {
    va_list args;
    va_start(args, count);   // bắt đầu từ "count"

    int total = 0;
    for (int i = 0; i < count; i++) {
        total += va_arg(args, int);  // lấy từng số nguyên
    }

    va_end(args);
    return total;
}

int main() {
    printf("Sum = %d\n", sum(4, 1, 2, 3, 4)); // 10
    printf("Sum = %d\n", sum(3, 10, 20, 30)); // 60
    return 0;
}
```

---

## Ví dụ 2: Custom printf (format chuỗi)

```c
#include <stdio.h>
#include <stdarg.h>

void myPrint(const char* fmt, ...) {
    va_list args;
    va_start(args, fmt);

    while (*fmt) {
        if (*fmt == 'd') {   // in số nguyên
            int i = va_arg(args, int);
            printf("%d ", i);
        } else if (*fmt == 'c') { // in ký tự
            char c = (char)va_arg(args, int);
            printf("%c ", c);
        } else if (*fmt == 'f') { // in float
            double d = va_arg(args, double);
            printf("%.2f ", d);
        }
        fmt++;
    }

    va_end(args);
    printf("\n");
}

int main() {
    myPrint("dcf", 42, 'A', 3.14); // output: 42 A 3.14
    return 0;
}
```

---

# 2. ASSERT

👉 `assert.h` dùng để **debug runtime**.

* Nếu điều kiện **true** → chương trình chạy tiếp.
* Nếu điều kiện **false** → in ra lỗi (`file`, `line`, biểu thức) và dừng chương trình.

---

## Cú pháp

```c
#include <assert.h>
assert(expression);
```

* `expression` là điều kiện cần kiểm tra.
* Nếu `expression == 0` (false) → báo lỗi.

---

## Tắt assert khi release

```c
#define NDEBUG   // định nghĩa trước khi include assert.h
#include <assert.h>
```

Khi có `NDEBUG`, tất cả `assert()` bị compiler bỏ qua → không tốn hiệu năng.

---

## Ví dụ

```c
#include <stdio.h>
#include <assert.h>

int divide(int a, int b) {
    assert(b != 0);  // kiểm tra b khác 0
    return a / b;
}

int main() {
    printf("10 / 2 = %d\n", divide(10, 2)); // OK
    printf("10 / 0 = %d\n", divide(10, 0)); // Lỗi assert
    return 0;
}
```

Output khi lỗi:

```
Assertion failed: (b != 0), function divide, file main.c, line 6.
Abort trap: 6
```

---

# So sánh STDARG vs ASSERT

| Tiêu chí    | STDARG                                    | ASSERT                              |
| ----------- | ----------------------------------------- | ----------------------------------- |
| Mục đích    | Xử lý hàm có tham số biến đổi (variadic). | Debug runtime (kiểm tra điều kiện). |
| Thư viện    | `<stdarg.h>`                              | `<assert.h>`                        |
| Thành phần  | `va_list, va_start, va_arg, va_end`       | `assert()`                          |
| Ứng dụng    | `printf`, `scanf`, custom log, sum, ...   | Kiểm tra tham số, validate input.   |
| Khi release | Luôn chạy.                                | Có thể tắt bằng `#define NDEBUG`.   |
