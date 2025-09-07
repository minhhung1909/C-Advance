# 1. COMPILER

Compiler là phần mềm dịch ngôn ngữ bậc cao về ngôn ngữ máy.

Các Compiler: `gcc`, `g++`, `clang`, `GNU`, ...

Các bước Compiler thực hiện: **Preprocessor → Compilation → Assembler → Linker**

---

## 1.1. Preprocessor (Tiền xử lý)

* Từ file `.c`, `.h`, `.cpp`, `.hpp` → ra file `.i`.
* Lệnh:

  ```bash
  gcc -E NameFile.c -o NameFile.i
  ```
* Công việc:

  * Thay thế các `#include` → gộp nội dung file header vào.
  * Thay thế macro `#define`.
  * Xóa comment.

---

## 1.2. Compilation

* Tạo file Assembly `.s` từ `.i`.
* Lệnh:

  ```bash
  gcc -S NameFile.i -o NameFile.s
  ```
* Công việc: dịch C sang mã Assembly.

---

## 1.3. Assembler

* Tạo Object file `.o` từ `.s`.
* Lệnh:

  ```bash
  gcc -c NameFile.s -o NameFile.o   # (-c chứ không phải -C)
  ```

---

## 1.4. Linker

* Liên kết các Object file lại → ra file thực thi (`.exe` hoặc ELF).
* Lệnh:

  ```bash
  gcc main.o utils.o -o program
  ```

---

# 2. MACRO

Macro là nhóm lệnh để thay thế trực tiếp đoạn code vào chương trình.

Các loại macro:

* `#include` (chèn file hoặc thư viện khác).
* `#define`, `#undef` (định nghĩa / gỡ định nghĩa).
* `#if, #elif, #else, #ifdef, #ifndef`.

---

## Sự khác nhau giữa Macro và Function

* **Macro**:

  * Thay thế trực tiếp code.
  * Gọi nhiều lần → chương trình dài hơn (kích thước lớn hơn).
  * Chạy nhanh (vì không qua lời gọi hàm).

* **Function**:

  * Định nghĩa một lần, nhiều nơi chỉ cần gọi.
  * Kích thước chương trình nhỏ hơn.
  * Chạy chậm hơn một chút (phải gọi qua stack, PC, register...).
  * Compiler hiện đại có `inline function` → vừa nhỏ gọn, vừa nhanh, thay thế macro function an toàn hơn.

---

# STDARG – ASSERT (liên quan macro nâng cao)

## Macro Function

*Demo 1:*

```c
#include "stdio.h"
#define CREATE_FNC(name, cmd)       \
void name(){                        \
    printf(#cmd);                   \
}

#define CREATE_VAR(name)            \
    int int_##name;                 \
    float float_##name;             \
    char char_##name;

CREATE_FNC(fnc1, hello FNC 1 \n);
CREATE_FNC(fnc2, hello FNC 2 \n);

int main(){
    fnc1();
    CREATE_VAR(temp)
    fnc2();
    return 0;
}
```

Lưu ý: macro function phải có `\` ở cuối mỗi dòng (trừ dòng cuối).

---

## Operator trong Macro

* `#`: biến đối số thành chuỗi (stringize).
* `##`: nối token lại với nhau.
* `__VA_ARGS__`: cho phép truyền số lượng tham số không cố định.

---

*Demo 2:*

```c
#include <stdio.h>

#define PRINT_MENU(...)                             \
    do {                                            \
        const char* items[] = {__VA_ARGS__};        \
        int n = sizeof(items) / sizeof(items[0]);   \
        for (int i = 0; i < n; i++) {               \
            printf("%d. %s\n", i + 1, items[i]);    \
        }                                           \
    } while (0)

#define CASE_OPTION(number, function)   \
case number:                            \
    function();                         \
    break;

#define HANDLE_OPTION(option, ...)                  \
    switch (option) {                               \
        __VA_ARGS__                                 \
        default: printf("Invalid option!\n");       \
    }

#define display(...)                                                    \
    do{                                                                 \
        const char *items[] = {__VA_ARGS__};                            \
        int size = sizeof(items) / sizeof(items[0]);                    \
        for(int i = 0; i < size; i++){                                  \
            printf("Char times %d have char is: %s \n", i, items[i]);   \
        }                                                               \
    } while(0)                                       

void feature1() { printf("Feature 1 selected ... Do something \n"); }
void feature2() { printf("Feature 2 selected ... Do something \n"); }
void feature3() { printf("Feature 3 selected ... Do something \n"); }
void feature4() { printf("Feature 4 selected ... Do something \n"); }

int main(){
    display("one", "two", "three", "dog", "cat");

    PRINT_MENU("Option 1", "Option 2", "Option 3","Option 4", "Exit");

    int option;
    scanf("%d", &option);

    HANDLE_OPTION(option,
        CASE_OPTION(1, feature1)
        CASE_OPTION(2, feature2)
        CASE_OPTION(3, feature3)
        CASE_OPTION(4, feature4))
    return 0;
}
```