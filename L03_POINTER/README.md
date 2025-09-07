
# 1. POINTER

Pointer (con trỏ) là một biến lưu **địa chỉ của biến khác** thay vì lưu giá trị trực tiếp.
Nhờ đó ta có thể thao tác trực tiếp với vùng nhớ mà biến chiếm dụng.

---

## 1. Khai báo cơ bản

```c
int x = 10;        // biến bình thường
int *ptr = &x;     // ptr trỏ đến địa chỉ của x

printf("Address of x: %p\n", &x);
printf("Value of x through ptr: %d\n", *ptr);
```

`ptr` chứa địa chỉ của `x`.
`*ptr` (dereference) lấy giá trị tại địa chỉ mà `ptr` trỏ đến.

---

## 2. Kiến trúc Pointer

* Trên máy **32-bit** → con trỏ chiếm **4 byte**.
* Trên máy **64-bit** → con trỏ chiếm **8 byte**.
* Kích thước con trỏ **không phụ thuộc vào kiểu dữ liệu nó trỏ tới**.

---

## 3. Truyền Tham Trị vs Tham Chiếu

* **Truyền tham trị**: biến trong hàm là bản sao, không ảnh hưởng biến gốc.
* **Truyền tham chiếu (con trỏ)**: thao tác trực tiếp lên địa chỉ biến thật.

 Ví dụ: Swap 2 số

```c
#include <stdio.h>

void swap(int *a, int *b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

int main() {
    int x = 1, y = 2;
    printf("Before swap: x=%d, y=%d\n", x, y);
    swap(&x, &y);
    printf("After swap:  x=%d, y=%d\n", x, y);
    return 0;
}
```

---

## 4. Void Pointer

Con trỏ không kiểu (`void*`) có thể trỏ đến mọi loại dữ liệu.
Muốn dereference phải **ép kiểu**.

```c
#include <stdio.h>

int main() {
    int a = 10;
    double b = 3.14;
    char c = 'Z';

    void *ptr;

    ptr = &a;
    printf("int: %d\n", *(int*)ptr);

    ptr = &b;
    printf("double: %.2f\n", *(double*)ptr);

    ptr = &c;
    printf("char: %c\n", *(char*)ptr);

    return 0;
}
```

---

## 5. Function Pointer

Con trỏ có thể trỏ đến **hàm** và được dùng để gọi hàm gián tiếp.

```c
#include <stdio.h>

void add(int a, int b) { printf("Sum: %d\n", a + b); }
void sub(int a, int b) { printf("Diff: %d\n", a - b); }

void calculator(void (*f)(int, int), int x, int y) {
    f(x, y);
}

int main() {
    void (*fp)(int, int);

    fp = add;
    fp(5, 3);       // gọi add

    fp = sub;
    fp(5, 3);       // gọi sub

    calculator(add, 10, 20);
    calculator(sub, 10, 20);

    return 0;
}
```

---

## 6. Pointer to Constant

Không thể thay đổi **giá trị tại địa chỉ** thông qua con trỏ, nhưng con trỏ có thể trỏ sang biến khác.

```c
#include <stdio.h>

int main() {
    int a = 10, b = 20;
    const int *ptr = &a;

    printf("Value: %d\n", *ptr);

    // *ptr = 15; //  lỗi
    ptr = &b;    //  được

    printf("Value: %d\n", *ptr);
    return 0;
}
```

---

## 7. Constant Pointer

Con trỏ luôn trỏ đến **cùng một địa chỉ**, nhưng có thể thay đổi giá trị tại địa chỉ đó.

```c
#include <stdio.h>

int main() {
    int a = 10, b = 20;
    int *const ptr = &a;

    *ptr = 15;   //  thay đổi giá trị tại địa chỉ
    // ptr = &b; //  lỗi

    printf("Value: %d\n", *ptr);
    return 0;
}
```

---

## 8. Pointer to Pointer

Con trỏ trỏ đến con trỏ khác.

```c
#include <stdio.h>

int main() {
    int x = 42;
    int *p = &x;
    int **pp = &p;

    printf("Value of x: %d\n", **pp);
    return 0;
}
```

---

## 9. NULL Pointer

Con trỏ không trỏ đến đâu cả.
Dùng để tránh lỗi dereference lung tung.

```c
#include <stdio.h>

int main() {
    int *ptr = NULL;

    if (ptr == NULL) {
        printf("Pointer is NULL, safe to use.\n");
    }

    return 0;
}
```

---

# Tổng kết

* **Pointer cơ bản**: lưu địa chỉ, dùng `*` để dereference.
* **Void pointer**: trỏ mọi loại, phải ép kiểu.
* **Function pointer**: giúp truyền hàm như tham số.
* **Pointer to const**: không đổi giá trị qua con trỏ.
* **Const pointer**: không đổi địa chỉ, nhưng đổi giá trị được.
* **Pointer to pointer**: lưu địa chỉ của con trỏ khác.
* **NULL pointer**: an toàn khi khởi tạo.

---

Vậy là mày có bộ **Pointer notes đầy đủ + demo** rồi.

Mày có muốn tao viết thêm **so sánh `Pointer` với `Array`** (cái mà dễ nhầm lẫn nhất) không?
