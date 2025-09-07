# 1. GOTO

**Là gì:**

* `goto` là một câu lệnh nhảy (jump statement) trong C, cho phép chuyển luồng chương trình đến một nhãn (label) được định nghĩa trong cùng một hàm.

**Vì sao được tạo ra:**

* Khi C ra đời (thập niên 70), chưa có nhiều cấu trúc điều khiển nâng cao (`break`, `continue`, `switch-case`, exception handling…).
* `goto` là cách đơn giản để thoát khỏi vòng lặp, hoặc xử lý luồng phức tạp.

**Giải quyết vấn đề gì:**

* Giúp rút ngắn code khi cần **thoát nhiều vòng lặp lồng nhau**.
* Giúp gom code xử lý lỗi vào một chỗ (error handling).

**Ví dụ code:**

```c
#include <stdio.h>

int main() {
    int i = 0;
start:                     // nhãn
    if (i >= 5) {
        goto end;          // nhảy đến nhãn end
    }
    printf("%d ", i);
    i++;
    goto start;            // nhảy lại nhãn start

end:
    printf("\nDone!\n");
    return 0;
}
```

**Ứng dụng trong Embedded:**

* Dùng trong **error handling** ở driver: nếu một bước khởi tạo lỗi thì `goto` nhảy xuống cleanup/free resource.
* Dùng khi **thoát nhiều vòng lặp** mà không cần flag phụ.

Ví dụ trong **driver**:

```c
int init_driver() {
    if (init_gpio() != 0) goto error;
    if (init_uart() != 0) goto error;
    if (init_i2c() != 0) goto error;
    return 0;
error:
    deinit_all();
    return -1;
}
```

---

# 2. SETJMP / LONGJMP

**Là gì:**

* `setjmp` và `longjmp` (trong `<setjmp.h>`) là cơ chế **nhảy không cục bộ (non-local jump)**, cho phép nhảy ra ngoài phạm vi hàm hiện tại về một điểm đã lưu trước đó.
* `setjmp` lưu trạng thái (stack, register, program counter).
* `longjmp` khôi phục trạng thái và tiếp tục chạy từ vị trí `setjmp`.

**Vì sao được tạo ra:**

* `goto` chỉ hoạt động trong **cùng một hàm**.
* Với hệ thống phức tạp, đôi khi cần nhảy về một điểm an toàn trong **toàn chương trình**, ví dụ khi có lỗi nghiêm trọng.

**Giải quyết vấn đề gì:**

* Xử lý ngoại lệ (exception handling) trong C (C không có `try-catch`).
* Cho phép thoát ra khỏi nhiều tầng hàm mà không cần return liên tiếp.

**Ví dụ code:**

```c
#include <stdio.h>
#include <setjmp.h>
#define END 1

jmp_buf env;
int count = 0;

int main() {
    int ret = setjmp(env);  

    if (ret == 0) {
        printf("First time setjmp return = %d\n", ret);
        count++;
    } else {
        printf("After longjmp, setjmp return = %d\n", ret);
        if (count == END) return 0;
    }

    longjmp(env, 2); // nhảy về setjmp, giá trị trả về của setjmp = 2
    return 0;
}
```

**Ứng dụng trong Embedded:**

* Dùng để viết **error recovery system** (giống try-catch trong C++/Java).
* Trong **RTOS hoặc firmware**, có thể dùng để nhảy về “safe point” khi phát hiện lỗi phần cứng.
* Trong **parser hoặc interpreter**, dùng để thoát khi gặp lỗi cú pháp.

---

Tóm lại:

* `goto` → nhảy trong **cùng hàm**, tiện cho **error handling nội bộ**.
* `setjmp/longjmp` → nhảy **giữa nhiều hàm**, tiện cho **exception handling toàn cục**.