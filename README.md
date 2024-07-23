# C-C++-Advanced-Study
- [1a. COMPILER](#1a-COMPILER)
- [1b. MACRO](#1b-MACRO)
- [2a. STDARG](#2a-STDARG)
- [2b. ASSERT](#2b-ASSERT)
- [3. POINTER](#3-POINTER)
- [4. MEMORY LAYOUT](#4-MEMORY-LAYOUT)
- [5. EXTERN - STATIC - VOLATILE - REGISTER](#5-EXTERN---STATIC---VOLATILE---REGISTER)
- [6a. GOTO](#5a-GOTO)
- [6b. SETJMP](#5b-SETJMP)
- [7. BIT MAINPULATION](#7-BIT-MAINPULATION)
- [8. STRUCT - UNION](#8-STRUCT---UNION)
- [9. JSON](#9-JSON)
- [10. LINKED LIST](#10-LINKED-LIST)
- [11. STACK - QUEUE](#11-STACK---QUEUE)
- [12. BINARY SEARCH - FILE OPERATIONS - CODE STANDARDS](#12-BINARY-SEARCH---FILE-OPERATIONS---CODE-STANDARDS)
- [13. CLASS](#13-CLASS)
  
# 1a. COMPILER

Compiler Là phần mềm để dịch ngôn ngữ bậc cao về ngôn ngữ máy.

Các Compiler: gcc, g++. Clang, GNU ...

Các bước Compiler thực hiện: Preprocessor, Compilation, Assembler, Linker

## 1. Preprocessor (Tiền xử lý)

Từ những file .c, .h, .cpp, .hpp chuyển sang file .i
Lệnh tiền xử lý từ gcc: gcc -E NameFile.c -o NameFile.i

Preprocessor: Là thực hiện việc gộp vào cùng một file đối với là lệnh include, còn nếu là Macro thì sẽ thay thế đoạn định nghĩa sau đó và sẽ xoá hết tất cả comment.

## 2. Compilation

Tạo file Assembly code ( .s)từ file .i
Lệnh tạo ra Assembly từ gcc: gcc -S NameFile.i -o NameFile.s

Compilation: tạo ra file Assembly

## 3. Assembler

Tạo object file .o từ file .s
Lệnh tạo ra Object file từ gcc: gcc -C NameFile.s -o NameFile.o

## 4. Linker

Liên kết các Object file lại với nhau.
tạo ra được file .exe
Lệnh liên kết các file từ gcc: gcc NameFile.o NameFile.o -o NameFileLinker

# 1b. MACRO

MACRO
=======
Macro là nhóm lệnh dùng để thay thế định nghĩa những đoạn lệnh sau đó
Macro gồm những nhóm lệnh sau: 
- #include (include thư viện hoặc các file khác)
- #define, #undef (định nghĩa/gỡ định nghĩa những giá trị sau đó)
- #if, #elif, #else, #ifdef, #ifndef

- Sự khác nhau giửa Macro và Function
    + Macro: Thay thế đoạn định nghĩa vào chương trình nếu gọi nhiều lần thì thay thế nhiều lần => Kích thước lớn hơn; Bù lại tốc độ xử lý nhanh hơn.
    + Function: Viết chương trình 1 lần sau này chỉ cần gọi lại => Kích thước chương trình lớn hơn; Tốc độ xử lý chậm hơn vì phải qua những cơ chế như: lưu vào main Stack poiter hay đếm (Program counter)  

STDARG-ASERT
=======
## Sự khác nhau giửa Macro và Function
+ Macro: Thay thế đoạn định nghĩa vào chương trình nếu gọi nhiều lần thì thay thế nhiều lần => Kích thước lớn hơn; Bù lại tốc độ xử lý nhanh hơn.
+ Function: Viết chương trình 1 lần sau này chỉ cần gọi lại => Kích thước chương trình bé hơn __Nhưng__ Tốc độ xử lý chậm hơn vì phải qua những cơ chế lưu vào main Stack poiter hay đếm (Program counter).
## Macro Funcion 
*Demo 1*

<details><summary> *Demo 1* </summary>
<p>

```C
#include"stdio.h"
#define CREATE_FNC(name, cmd)       \
void name(){                        \
    printf(#cmd);                   \
}

#define CREATE_VAR(name)            \
    int int_##name;                 \
    float float_##name;             \
    char char_##name;               \

CREATE_FNC(fnc1, hello FNC 1 \n);
CREATE_FNC(fnc2, hello FNC 2 \n);

int main(int argc, char const *argv[]){
    fnc1();
    CREATE_VAR(temp)
    fnc2();
    return 0;
}
```

</p>
</details>

*Lưu ý: Viết Macro Fuction phải có dấu \ ở cuối dòng và dòng dòng cuối cùng thì không cần __chỉ viết tới dòng kế cuối__*

## Operator

__#__: thay thế cho 1 chuỗi truyền vào và không cần nháy kép (*Demo 1*).

__##__: Nối chuỗi lại với nhau (*Demo 1*).

__VA_ARGS__: Cho phép truyền các đối số vào mà không biết trước số lượng cần truyền (*Demo 2 phía dưới*).



<details><summary> Demo 2 </summary>
<p>

```C
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

int main(int argc, char const *argv[])
{

    display("one", "two", "three", "dog", "cat");

    PRINT_MENU("Option 1", "Option 2", "Option 3","Option4", "Exit");

    // Giả sử option được nhập từ người dùng
    int option ;
    scanf("%d", &option);

    HANDLE_OPTION(option,
        CASE_OPTION(1, feature1)
        CASE_OPTION(2, feature2)
        CASE_OPTION(3, feature3)
        CASE_OPTION(4, feature4))
    return 0;
}
```

</p>
</details>

# 2a. STDARG

- Thư viện STDARG giúp viết những chương trình không biết trước tham số đầu vào.

*Khai báo hàm phải có khai báo biến đầu tiên là Label định nghĩa số Input cho Function*

## Cần khai báo 4 hàm khi dùng Lib này:

- *va_list:* Đây là kiểu dữ liệu của thư viện stdarg khai báo giá trị để lưu mảng các giá trị.
    
- *va_start:* Hàm này truyền 2 đối số. có chức năng Stat chương trình
    
    + Đối số 1: Truyền vào biến của chứa kiểu dữ liệu __va_list__ 
        
    + Đối số 2: truyền vào label của số input
        
- *va_arg:* Hàm này có 2 đối số. Có chức năng ép kiểu dữ liệu cho các giá trị tiếp theo trong mảng giá trị
    
- *va_end:* Hàm này có chức năng thu hồi biến của kiểu dữ liệu __va_list__ 

# 2b. ASSERT

Libary này cung cấp khả năng Debug. Libary này cho phép kiểm tra nếu điều kiện thêm vào đúng thì chương trình chạy như bình thường. 
Nếu điều kiện của chương trình sai thì chương trình sẽ dừng lại và đưa lên message lỗi.
Dùng lệnh #define NDEBUG để tắt Debug này.

# 3. POINTER

- Pointer là một biến mà giá trị của nó là địa chỉ của một biến mà nó trỏ đến. Qua đó có thể thao tác trên bộ nhớ một cách đơn giản hơn. 

<details><summary> Demo </summary>
<p>
    
```C
int x = 10;         // Khai báo biến
int *ptr = &x;      // Khai báo pointer trỏ vào biến x
// Lúc này Pointer sẽ có giá trị là địa chỉ của biến x 
int y = *ptr_x;     // Gán giá trị của Pointer cho biến y tức là gán giá trị địa chỉ của biến x cho biến y
```

</p>
</details>

## Kiến trúc của Pointer 
- Phụ thuộc vào kiến trúc của máy tính: 32 bit => 4 byte; 64 bit => 8 byte

## Ứng dụng Pointer

Bình thường khi ta truyền vào hàm một Tham Trị (Giá trị biến) khi bắt đầu thực hiện hàm lúc này biến trong function sẽ được cung cấp cho 1 địa chỉ mới và sau khi hàm kết thúc thì địa chỉ này cũng được trả lại và 2 biến đó không thay đổi giá trị.
Nhưng khi ta truyền vào trong đó một Tham Chiếu (Địa chỉ biến) thì vẫn thực hiện trên địa chỉ đó và trả về là giá trị được hoán đổi. Demo ở đoạn code sau.

<details><summary>Demo</summary>
<p>
    
```C
#include <stdio.h>
void swap(int *a, int *b){
    int tmp;
    tmp = *a;
    *a = *b;
    *b = tmp;
}
int main(int argc, const char *argv[]){
    int x = 1;
    int y = 2;
    printf("x after is %d, y is after %d \n", x, y);
    swap(&x,&y);
    printf("x before is %d, y is before %d \n", x, y);
}
```

</p>
</details>

## Void Pointer

Void pointer được sử dụng để trỏ vào biến mà không biết trước kiểu dữ liệu.

*Lưu ý khi dùng void pointer phải ép kiểu khi muốn in giá trị.*


<details><summary> Xem Code Demo </summary>
<p>

```C
#include <stdio.h>
#include <stdlib.h>

int main() {   
    int value = 5;
    double test = 15.7;
    char letter = 'A';
    
    void *ptr = &value;
    printf("value is: %d\n", *(int*)(ptr));

    ptr = &test;
    printf("value is: %f\n", *(double*)(ptr));

    ptr = &letter;
    printf("value is: %c\n", *(char*)(ptr));

    return 0;
}
```

</p>
</details>


## Function Pointer

Function Pointer (con trỏ hàm) có thể trỏ vào một hàm và giá trị của con trỏ hàm là giá trị địa chỉ của hàm mà nó trỏ tới. 
Function Pointer giúp truyền vào 1 function khác. 

<details><summary>Code Demo Function Pointer</summary>
<p>
    
```C

#include <stdio.h>

void sum(int a, int b){
    printf("Sum of %d and %d is: %d\n",a,b, a+b);
}

void subtract(int a, int b){
    printf("Subtract of %d by %d is: %d \n",a,b, a-b);
}

void multiple(int a, int b){
    printf("Multiple of %d and %d is: %d \n",a,b, a*b );
}

void divide(int a, int b){
    if (b == 0)
    {
        printf("Mau so phai khac 0\n");
        return;
    }
    printf("%d divided by %d is: %f \n",a,b, (double)a / (double)b);
}
void calculator(void (*ptr)(int, int), int a, int b){
    printf("Program calculate: \n");
    ptr(a,b);
}

int main(){
    // Method 1: 
    calculator(sum,5,2);
    calculator(subtract,5,2);
    calculator(multiple,5,2);
    calculator(divide,5,2);
    // Method 2:
    void (*ptr[])(int, int) = {sum, divide, multiple};
    ptr[1](5,6);

    return 0;
}
```

</p>
</details>

## Pointer To Constrant

- Là định nghĩa một con trỏ không thể thay đổi giá trị (Read-only) tại địa chỉ mà nó trỏ đến thông qua dereference nhưng giá trị tại địa chỉ đó có thể thay đổi(Có thể thay đổi biến trỏ tới).

<details><summary>Code Demo Pointer To Constant</summary>
<p>
    
```C

#include <stdio.h>
#include <stdlib.h>

int main() {
    char a = 'a';
    char b = 'b';

    char const *ptrToConstant = &a;

    printf("value: %c\n", *ptrToConstant);
    printf("address: %d\n", ptrToConstant);

    // *ptrToConstant = 'c'; //Lỗi

    ptrToConstant = &b;

    printf("value: %c\n", *ptrToConstant);
    printf("address: %d\n", ptrToConstant);
    return 0;
}

```

</p>
</details>

## Constrant Pointer

- Có thể thay đổi được giá trị mà nó trỏ tới nhưng không thể thay đổi được địa chỉ nó trỏ tới

<details><summary>Code Demo Constant Pointer</summary>
<p>
    
```C

#include <stdio.h>
#include <stdlib.h>

int main() {
    char a = 'a';
    char b = 'b';

    char *const cons_ptr = &a;

    printf("value: %c\n", *cons_ptr);
    printf("address: %d\n", cons_ptr);

    *cons_ptr = 'c';

    printf("value: %c\n", *cons_ptr);
    printf("address: %d\n", cons_ptr);

    cons_ptr = &b; // Lỗi
    return 0;
}

```

</p>
</details>

## Pointer To Pointer

- Giá trị con trỏ này là địa chỉ của con trỏ kia.

## NULL Pointer

- Null Pointer là một con trỏ không trỏ tới bất cứ địa chỉ nào. Vì khi một Pointer được khởi tạo luôn luôn phải gán giá trị cho nó hoặc là phải để NULL. 

- Để tránh *Dereferencing* 

# 4. MEMORY LAYOUT

Chương trình main.c (trên windown) hoặc main.hex (trên vđk) được lưu vào bộ nhớ SSD hoặc Flash. Đối với Windown khi ấn run còn trên VĐK thì bật lên thì lập tức chương trình sẽ được copy vào bộ nhớ RAM để thực thi.

## Text segment

- Quyền: Read-Only, Run
- Chứa chỉ lệnh ngôn ngữ máy.

## Data Segment (Initial data segment)

- Quyền: Read-Write
- Chứa: Biến toàn cục, Static được khởi tạo giá trị khác 0.
- Các biến sẽ được thu hồi khi chương trình kết thúc.

## BSS Segment (Uninitialized Data Segment)

- Quyền: Read-Write
- Chứa: Biến toàn cục, static được khởi tạo giá trị bằng không hoặc không gán giá trị (Không tường minh).
- Các biến sẽ được thu hồi khi chương trình kết thúc.

## Stack

- Quyền: Read-Write
- Chứa: Biến cục bộ và tham số truyền vào. 
- Vùng nhớ này sẽ được thu hồi khi ra khỏi hàm. Bộ nhớ này có tốc độ truy cập nhanh nhất
- Hệ điều hành sẽ quản lý bộ nhớ này.

## Heap

- Quyền: Read-Write
- Chứa: Là vùng nhwos dùng để thực hiện cấp phát động. 
- Vùng nhớ này sẽ không được huỷ khi sử dụng xong nên phải được thu hồi khi thực hiện hàm free().


Stack và Heap là 2 vùng nhớ cố định và có giới hạn nếu không cân nhắc khi sữ dụng dễ xãy ra tình trạng Overflow


# 5. EXTERN - STATIC - VOLATILE - REGISTER

## Extern
Extern là dùng để khai báo một biến đã khai báo ở 1 file nào đó và được sử dụng trong 1 file mà biến Extern này được khai báo giúp dữ liệu tại biến này luôn được cập nhật tài 2 file.

*ví dụ về Khai báo:*

- Bên file A:

int num = 10;

- Bên file B(file cần liên kết biến num):

extern int num;

## Static
### Local Static
Static local là những biến hoạt động trong 1 hàm nhất định và không bị thu hồi địa chỉ khi hàm kết thúc. Nằm trong vùng nhớ BSS(uninitialized data segment).

### Global Static
Global static cũng tương tự local static nhưng chỉ khác là biến này hoạt động trong toàn bộ file. Gobal Static còn giúp tránh trường hợp trùng tên giửa các file với nhau.

## Volatile
Volotile trong c cho phép ngăn chặn việc tối ưu hoá biến làm cho giá trị biến đó không thay đổi khi có tác động bên ngoài. 

## Register

Register cho phép chuyển vùng nhớ từ ram sang thanh ghi (register). Việc này giúp việc tính toán trở nên nhanh hơn. Tuy vậy số lượng Register có hạn nên chỉ nên sài những biến thực sự cần thiết.

Khai báo register bằng cách đặt tên trước kiểu dữ liệu *ví dụ*:

register int a = 10;

# 6a. GOTO

Goto là một trong những câu lệnh giúp kiểm soát flow hoạt động của chương trình. Nhưng các này thường ít được khuyên dùng do vấn đề bảo trình và đọc gặp khó khăn. Đối với goto chỉ hoạt động được trong cục bộ.

<details><summary>Code Demo Example flow</summary>
<p>
    
```C

#include <stdio.h>
int main() {
    int i = 0;
    // Đặt nhãn    
    start:
        if (i >= 5) {
            goto end;  // Chuyển control đến nhãn "end"
        }
        printf("%d ", i);
        i++;
        goto start;  // Chuyển control đến nhãn "start"

    // Nhãn "end"
    end:
        printf("\n");
        return 0;
}

```
</p>
</details>

# 6b. SETJMP

- setjmp.h: Đây là một thư viện dùng để xử lý ngoại lệ(gần tương tự như goto) Nhưng thư viện này mạnh hơn Goto ở chỗ có thể hoạt động toàn cục. Thư viện này cung cấp 2 hàm là:

    + setjmp: có 1 tham số truyền vào là biến có kiểu dữ liệu __jmp_buf__ 
    Hàm có giá trị trả về int.

    + longjmp: Có 2 tham số truyền vào: Đầu tiên là Biến truyền vào của setjmp, thứ hai là tham số được set tuỳ ý để con trỏ dịch về setjmp và lúc này setjmp sẽ trả về tham số thứ 2 này

<details><summary>Code Demo Goto</summary>
<p>
    
```C

#include "stdio.h"
#include "setjmp.h"
#define END 1

jmp_buf value_Control;

int count = 0;
int main(){

    int number = setjmp(value_Control);

    if(number == 0){
        printf("setjmp return is: %d \n", number);
        count++;
    }
    else{
        printf("setjmp return is: %d \n", number);
        if (count == END) return 0;
    }

    longjmp(value_Control, 2);

    return 0;
}

// Giá trị đầu tiên sau khi chạy chương trình là giá trị trả về của setjmp đầu tiên sẽ là 0 sau khi chạy xong if thì 

//Xuống longjmp với tham số được set là 2 thì sẽ nhảy ngược lại hàm setjmp có biến value_Control và trả về con số mà biến longjmp đã set là 2. 
```
</p>
</details>

# 7. BIT MASK

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

# 8. STRUCT - UNION

## Struct

Struct là một cấu trúc dữ liệu có thể tự định nghĩa thành một kiểu dữ liệu mới có thể gom các biến có kiểu dữ liệu khác nhau thành một struct. Struct cho phép tạo cấu trúc dữ liệu lớn hơn và có tổ chức hơn.

```C
typedef struct Student {
    int studentID;
    char name[50];
    double GPA;
}Student;
```

## Union
Union là một cấu trúc dữ liệu nhưng dữ liệu trong 1 union sẽ nhỏ hơn Struct bởi vì một thời điểm chỉ có một biến trong union sử dụng dữ liệu đó.

```C
typedef union Student {
    int studentID;
    char name[50];
    double GPA;
}Student;
```


# 9. JSON
JSON là viết tắt của "Java Scrip Object Notation - Ghi chú về đối tượng Javascrip". JSON là một định dạng dùng để truyền dữ liệu. Json có cú pháp dựa trên 1 cặp key-value

- Đối với Object bao gồm tập hợp nhiều key-value

```C
// Đây là 1 Object JSON

char  *json = "
{
    "name": "Hung",
    "age": 20,
    "grades": [85, 90, 78]
}
"
```
- Các định dạng của JSON

```C

typedef enum{
    JSON_NULL, 
    JSON_BOLEAN,    // True or False
    JSON_NUMBER,    // Number include int, double
    JSON_STRING,
    JSON_ARRAY,
    JSON_OBJECT     //Object Json in {} 
}
"
```

**Value có thể là bất cứ giá trị nào trong 6 kiểu dữ liệu trên nhưng mặc định Key phải là String**


# 10. LINKED LIST

Linked list là một cấu trúc dữ liệu dùng để lưu trữ dữ liệu. Một Linked list gồm nhiều node. Trong mỗi node thì gồm 2 phần tử

- Giá trị dữ liệu: Giá trị dữ liệu như trong 1 list, arr bình thường

- Pointer đến node sau đó. Pointer này có thể là Null nếu nó là phần tử duy nhất hoặc là phần tử cuối cùng trong mảng.

# 11. STACK - QUEUE


## Stack
Stack là cấu trúc dữ liệu theo nguyên tắc là Last In Fist Out (LIFO). 

Stack gồm 3 cơ chế:
- Push: Đặt vào 1 phần tử lên đầu tiên.
- Pop: Xoá phần tử đầu tiên ra.
- Top: Lấy ra phần tử đầu tiên ra.

## Queue
Queue là cấu trúc dữ liệu theo nguyên tắc Fist In Fist Out. 

Stack gồm 3 cơ chế:
- Inqueue: Đưa 1 phần tử vào hàng chờ.
- Dequeue: Lấy phần tử đầu tiên trong hàng đợi.
- front: Lấy giá trị của phần tử đầu tiên.


# 12. BINARY SEARCH - FILE OPERATIONS - CODE STANDARDS

## Binary Search

Binary Search là thuật toán tìm kiếm đượng ứng dụng cho các dãy số được sắp theo theo trật tự nhất định từ lớn đến bé hoặc ngược lại.  
- B1: Lấy giá trị ở giử để so sánh với giá tìm. Từ đó có được khoảng giá trị cần tìm là lớn hơn hoặc bé hơn giá trị ở giửa
- B2: Tiếp tục thực hiện việc chia tôi mảng để lấy phần tử ở giửa nếu chưa bằng thì vẫn tiếp tục chia đôi tới khi nào tìm ra giá trị thì thôi.
 
```Pseudocode

khai báo x; // x là số cần tìm
//  chia mảng ra làm 2 với phần tử ở giửa mảng được gắn là x
//  Phần tử đầu mảng là left, phần tử cuối mảng là right.
if arr[mid] == x
  return mid
else if arr[mid] > x
  return right = mid - 1  //bỏ các phần tử bên phải
else if arr[mid] < x
  return left = mid + 1   // bỏ các phần tử bên trái

```

## File Operations
Các hàm cần thiết trong xử lý file

- fopen(): Return 1 con trỏ file
Mode open:
  + r:   Mở file ở chế độ đọc.                       Mở thành công => return địa chỉ phần tử đầu tiên.    Mở không thành công => Return NULL.
  + rb:  Mở file ở chế độ đọc Binary.                Mở thành công => return địa chỉ phần tử đầu tiên.    Mở không thành công => Return NULL.
  + w:   Mở file ở chế độ ghi.                       File tồn tại => Ghi đè dữ liệu mới.    File không tồn tại thì tạo file mới.    Mở không thành công => Return NULL.
  + wb:  Mở file ở chế độ ghi.                       File tồn tại => Ghi đè dữ liệu mới.    File không tồn tại thì tạo file mới.    Mở không thành công => Return NULL.
  + a:   Mở file ở chế độ nối ghi vào phàn tử tiếp theo trong file.    File không tồn tại thì tạo file mới.    Mở không thành công => Return NULL.
  + ab:  Mở file ở chế độ nối ghi vào phần tử tiếp theo trong file ở dạng Binary.    File không tồn tại thì tạo file mới.    Mở không thành công => Return NULL.
  + r+:  Mở file ở chế độ Read-Write.                Mở thành công => return địa chỉ phần tử đầu tiên.    Mở không thành công => Return NULL.
  + rb+: Mở file ở chế độ Read-Write Binary.         Mở thành công => return địa chỉ phần tử đầu tiên.    Mở không thành công => Return NULL.
  + w+:  Mở file ở chế độ Read-Write.                File tồn tại => Trả về địa chỉ phần tử đầu tiên.    File không tồn tại thì tạo file mới.
  + wb+: Mở file ở chế độ Read-Write Binary.         File tồn tại => Trả về địa chỉ phần tử đầu tiên.    File không tồn tại thì tạo file mới.
  + a+:  Mở file ở chế độ nối và read.               File tồn tại thì trả về địa chỉ cuối cùng.          File không tồn tại thì tạo file mới.
  + ab+:  Mở file ở chế độ nối và read file Binary.  File tồn tại thì trả về địa chỉ cuối cùng.          File không tồn tại thì tạo file mới.
- fscanf(): Định dạng lại chuỗi.


<details><summary>Code Demo fscanf()</summary>
<p>
    
```C

#include <stdio.h>
#include <stdlib.h>
int main()
{
   char str1[10], str2[10], str3[10];
   int year;
   FILE * fp;

   fp = fopen ("baitapc.txt", "w+");
   fputs("Toi sinh nam 2016", fp);
   
   rewind(fp);
   fscanf(fp, "%s %s %s %d", str1, str2, str3, &year);
   
   printf("Doc chuoi 1: |%s|\n", str1 );
   printf("Doc chuoi 2: |%s|\n", str2 );
   printf("Doc chuoi 3: |%s|\n", str3 );
   printf("Doc so nguyen: |%d|\n", year );

   fclose(fp);
   
   return(0);
}

```
</p>
</details>

- fgets(): Copy nội dung trong file vào mảng.

<details><summary>Viết chương trình mở file myfile.txt để đọc 100 ký tự dòng đầu tiên và xuất ra màn hình</summary>
<p>
    
```C
#include <stdio.h>
int main()
{
  FILE * pFile;
  char mystring [100];
  pFile = fopen ("myfile.txt" , "r");
  if (pFile == NULL) perror ("Error opening file");
  else
  {
    if ( fgets (mystring , 100 , pFile) != NULL )
      puts (mystring);
    fclose (pFile);
  }
  return 0;
}
```

</p>
</details>

- fgetc(): Láy giá trị hiện tại của file. Return kiểu char


<details><summary> Code Demo fgetc </summary>
<p>
    
```C

#include <stdio.h>
int main ()
{
  FILE * pFile;
  int c;
  int n = 0;
  pFile=fopen ("myfile.txt","r");
  if (pFile==NULL) perror("Error opening file");
  else
  {
    do
    {
      c = fgetc(pFile);
      if (c == '$') n++;
    } while (c != EOF);
    fclose(pFile);
    printf("The file contains %d dollar sign characters ($).\n",n);
  }
  return 0;
}

```
</p>
</details>

- fread(): Đọc một số lượng Byte được chỉ định là File .bin

<details><summary>Code Demo fread()</summary>
<p>
    
```C

fread(void *ptr,size_t size,size_t count,FILE *stream);
  ptr: buffer chứa data đọc được
  size: kích thước mỗi phần tử
  count: số phần tử cần đọc
  stream: con trỏ file

```

</p>
</details>

- fprintf(): Ghi 1 chuỗi vào file. Có thể thêm danh sách các đối số
- fputs(): Ghi chuỗi vào file

<details><summary> Code Demo fputs() </summary>
<p>
    
```C

#include <stdio.h>
int main ()
{
  FILE * pFile;
  char sentence [256];
  printf("Enter sentence to append: ");
  fgets(sentence,256,stdin);
  pFile = fopen("mylog.txt","a");
  fputs(sentence,pFile);
  fclose(pFile);
  return 0;
}

```
</p>
</details>
  
- fputc(): Ghi 1 kí tự vào file

<details><summary>Code Demo fputc() </summary>
<p>
    
```C

#include <stdio.h>
int main ()
{
  FILE * pFile;
  char c;
  pFile = fopen("alphabet.txt","w");
  if (pFile!=NULL)
  {
    for (c = 'A' ; c <= 'Z' ; c++)
    fputc ( c , pFile );
    fclose (pFile);
  }
  return 0;
}

```
</p>
</details>

- fwrite(): Ghi 1 byte được chỉ định vào FIle .bin

<details><summary>Code Demo fwrite() </summary>
<p>
    
```C

#include <stdio.h>
#include <string.h>
int main()
{
  FILE *fp;
  char c[] = "Example for function fread and fwrite";
  char buffer[100];
  fp = fopen("file.txt", "rw");
  fwrite(c, strlen(c) + 1, 1, fp);
  fseek(fp, SEEK_SET, 0);
  fread(buffer, strlen(c)+1, 1, fp);
  printf("%s\n", buffer);
  fclose(fp);
  return(0);
}

```
</p>
</details>

- fclose(): Đóng file đã mở
- feof(): Kiểm tra kí tự hiện tại có phải kí tự cuối cùng của file hay chưa.

# 13. CLASS

Class là một kiểu dữ liệu tương tự như struct hay union. Sự khác nhau của Class và những kiểu dữ liệu còn lại là có phạm vi truy cập như: Public, private, protected.

Ví dụ về Class
```C++

#include <iostream>
#include <string>

using namespace std;

class SinhVien{
    public:
        int ID;
        string NAME;
        string CLASS;
        void Display(){
            cout << "MSSV: " << ID << endl;
            cout << "Name: " << NAME << endl;
            cout << "Class: " << CLASS << endl;
        }
};

int main(int argc, char const* argv[])
{
    SinhVien sv1;
    sv1.ID = 15;
    sv1.NAME = "Hung";
    sv1.CLASS = "IOT17";
    sv1.Display();
    return(0);
}

```

- Public: 