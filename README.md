# C-C++-Advanced-Study
- [1a. COMPILER - MACRO](L01_COMPILER_MACRO/README.md)
- [2. STDARG - ASSERT](L02_STDARG-ASERT/README.md)
- [3. POINTER](L03_POINTER/README.md)
- [4. STORAGE CLASSES](L04_STORAGE_CLASSES/README.md)
- [5. Control Flow và Xử lý Lỗi](L05_Goto-setjmp/README.md)




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
    
```c

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
    
```c

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
```c++

#include <iostream>
#include <string>
using namespace std;
class SinhVien{
    public:
        int ID;         // Protective
        string NAME;    // Protective
        string CLASS;   // Protective
        void Display(){
            cout << "MSSV: " << ID << endl;
            cout << "Name: " << NAME << endl;
            cout << "Class: " << CLASS << endl;
        }
};
int main(int argc, char const* argv[])
{
    SinhVien sv1;       //Object
    sv1.ID = 15;
    sv1.NAME = "Hung";
    sv1.CLASS = "IOT17";
    sv1.Display();
    return(0);
}
```
Đối với các biến mang kiểu dữ liệu của Class (Ví dụ class trên là SinhVien) thì được gọi là Object. Object chỉ có phạm vi truy cập là Public.

### Public: 
- Protective: thường là cái Variable (Nhưng không được gọi là variable mà phải gọi là protective).
- Method: Tương tự với Protective thì đây là những hàm nhưng không được gọi là hàm mà phải gọi là method.

### Private: 
Private là phạm vi truy cập mà chỉ có nhưng protective, method, constructor... trong Class là được phép truy cập. Object thì không được quyền truy cập tới phạm vi này.

Tương tự Static trong C thì chính là vùng private này.

### Protected: 

### Constructor:

Constructor là hàm tự động được gọi ra đầu tiên khi object được khởi tạo. Constructor phải có tên trùng với tên của Class.

### Destractor:

Destractor là trái ngược của constractor và tuân thủ theo cấu trúc FILO(First In Last Out) tức là những giá trị mà sau khi Constructor khai báo ra thì được Destractor thu hồi lại.

Ví dụ Constructor :

```c++
#include <iostream>
#include <string>
using namespace std;
class SinhVien{
    public:
        SinhVien(string name, string classroom);    // Init Constructor
        int ID;         // Protective
        string NAME;    // Protective
        string CLASS;   // Protective
        void Display(); // init Method
};

SinhVien::SinhVien(string name, string classroom){  // setup Constructor
    static int id = 15;
    SinhVien::ID = id;
    id++;

    SinhVien::NAME =  name;
    SinhVien::CLASS = classroom;
}

void SinhVien::Display(){
    cout << "MSSV: " << ID << endl;
    cout << "Name: " << NAME << endl;
    cout << "Class: " << CLASS << endl;
}


int main(int argc, char const* argv[])
{
    SinhVien sv1("Hung", "AIOT"), sv2("Hoa", "KT");
    sv1.Display();
    sv2.Display();
    return(0);
}
```
## Các lưu ý trong Class:

### Quy tắc Code:

- Tách các phần định nghĩa ra file mới (*.hpp).

```c++
// File .hpp
#include <iostream>
#include <string>

class SinhVien{
    public:
        int ID;
        string NAME;
        string CLASS; 
        void Display()
};
```

```c++
// File main.cpp
#include <iostream>
#include <string>
#include <main.hpp>

using namespace std;

void SinhVien::Display(){
    cout << "MSSV: " << ID << endl;
    cout << "Name: " << NAME << endl;
    cout << "Class: " << CLASS << endl;
}

int main(int argc, char const* argv[]){
    SinhVien sv1;       //Object
    sv1.ID = 15;
    sv1.NAME = "Hung";
    sv1.CLASS = "IOT17";
    sv1.Display();
    return(0);
}
```
### Giá trị mặc định trong Class:

insuaranceState luôn là 1 (YES) nếu không điền vào thông tin gì và nếu điền vào thì sẽ được thay đổi.

```c++
#include <iostream>
#include <string>
using namespace std;

typedef enum{
    NO, YES
}insurance;


class SinhVien{
    public:
        SinhVien(string name, string classroom);    // init Constructor
        void Display(insurance insuaranceState); // init Method
    private:
        int ID;         // Protective
        string NAME;    // Protective
        string CLASS;   // Protective
};


SinhVien::SinhVien(string name, string classroom){
    static int id = 15;
    SinhVien::ID = id;
    id++;

    SinhVien::NAME =  name;
    SinhVien::CLASS = classroom;


}

void SinhVien::Display(insurance insuaranceState = YES){
    cout << "MSSV: " << ID << endl;
    cout << "Name: " << NAME << endl;
    cout << "Class: " << CLASS << endl;
    cout << "State Insurance: " << insuaranceState <<endl;
}

int main(int argc, char const* argv[])
{
    SinhVien sv1("Hung", "AIOT"), sv2("Hoa", "KT");
    sv1.Display(NO);
    sv2.Display();
    return(0);
}
```

### Stactic trong Class:

Khi dùng Static trong class thì nhớ gọi ra ngoài để khởi tạo nó tránh trường hợp mỗi lần gọi object thì máy lại cấp phát 1 vùng nhớ khác cho biến static này. Ví dụ ở dưới.

```c++
#include <iostream>
#include <string>
using namespace std;
class SinhVien{
    public:
        SinhVien(string name, string classroom);
        void Display(insurance insuaranceState); 
        static int VAR; // Nếu chỉ để như này thì mỗi lần gọi 1 Object thì máy sẽ cấp phát cho biến này 1 vùng địa chỉ mới vậy thì static vô nghĩa. Phải gọi ra ngoài như bên dưới.
    private:
        int ID; 
        string NAME;
        string CLASS;
};

int SinhVien::VAR = 0;  // Lúc gọi ra như này thì máy sẽ cấp 1 địa chỉ cho dù có gọi bao nhiêu object
```

# 14. OBJECT-ORIENTED PROGRAMMING

- Hướng đối tượng có 4 tính chất: Tính đóng gói (Encapsulation), tính trừu tượng (Abstraction), tính kế thừa (Inheritance), tính đa hình (Polymorphism).

## Tính Kế Thừa (Inheritance)

- Inheritance trong lập trình hướng đối tượng OOP là một cơ chế xây dựng class mới dựa trên các class đã có. Các class kế thừa sẽ bao gồm toàn bộ các attributes và methods từ base class (lớp cơ sở) hay parent class (lớp cha).

- Các lớp Con kế thừa toàn bộ thành phần của lớp Cha và không cần phải đinh nghĩa lại. Lớp có có thể mở rộng các thành phần kế thừa hoặc bổ sung những thanh phần mới. Tránh được sự trùng lặp không cần thiết.

__Lưu ý 1: Muốn class sau kế thừa được các protective thì không được để trong private mà phải để trong protected.__

__Lưu ý 2: Khi tạo 1 con trỏ của class parent trỏ tới địa chỉ của class child thì nó sẽ trỏ tới class Parent.__


```c++
#include<iostream>
#include<string>

using namespace std;

class DoiTuong{
    protected:
        int ID;
        string TEN;
    public:
        DoiTuong();                 // Constructor
        void input(string ten);
        void Display();
};

DoiTuong::DoiTuong(){
    static int id = 100;
    ID = id;
    id++;
}

void DoiTuong:: input(string name){
    TEN = name;
}

void DoiTuong::Display(){
    cout << "ID: " << ID << endl;
    cout << "Name: " << TEN << endl;
}

class SinhVien : public DoiTuong{
    private:
        string LOP;
        string HOCKY;
    public:
        void input(string ten, string lop, string hocky);   // Override
        void Display();
};

void SinhVien::input(string ten, string lop, string hocky){
    TEN = ten;
    LOP = lop;
    HOCKY = hocky;
}

void SinhVien::Display(){
    cout << "ID: " << ID << endl;
    cout << "Name: " << TEN << endl;
    cout << "Class: " << LOP << endl;
    cout << "Semester: " << HOCKY << endl;
}

int main(int argc, char const *argv[]){
    DoiTuong td;
    td.input("Hung");
    td.Display();
    cout << "---------------------------" << endl;
    SinhVien sv;
    sv.input("Minh", "IOT17", "HKI");
    sv.Display();
    return 0;
}
```
### Kế thừa Public

Nếu class parent là Public thì con là Public. Nếu class parent là protected thì child là protected.

### Kế thừa Protected

Nếu class parent là Public thì con là protected. Nếu class parent là protected thì child là Public.

### Kế thừa Private

Nếu class parent là Public hay protected thì qua child class đều là private.

### Vitrual Function
Khi muốn ưu tiên sử dụng các protective ở class child thì dùng vitrual function.

```c++

#include<iostream>
#include<string>
using namespace std;

class Parent{
    public:
        virtual char* word(){       // vitrual function: giúp ưu tiên sử dụng hàm word của các child class .
            return (char*) "Parent Class\n";
        }
        void display(){
            cout << "Display: " << word() << endl;
        }
};

class Child : public Parent{
    public:
        char* word(){                        //Override
            return (char*) "Child Class\n";
        }
};

int main(int argc, char const *argv[]){
    Parent p;
    p.display();

    Child c;
    c.display();
    return 0;
}

```


## Tính Đóng gói (Encapsulation)

Khi khởi tạo 1 class không được cách truy cập các Protective một cách trực tiếp mà phải thông qua các method.

## Tính trừu tượng (Abstraction)

Những quá trình thược hiện tính toán cần được ẩn đi chỉ được return result cuối cùng.

```c++
#include<iostream>
#include<string>
#include<cmath>
using namespace std;

class GiaiPhuongTrinh
{
    private:
        double a, b, c, x1, x2, delta;
        void tinhNghiem();
    public:
        void enterNumber(double num_a, double num_b, double num_c);
        void printResult();
};
void GiaiPhuongTrinh::tinhNghiem()
{
    delta = b*b - 4*a*c;
    if (delta < 0){
        delta = -1;
    }  
    else if (delta == 0){
        x1 = x2 = -b/ (2*a);
    }
    else if (delta > 0){
        x1 = (-b + sqrt(delta))/(2*a);
        x2 = (-b - sqrt(delta))/(2*a);
    }
}
void GiaiPhuongTrinh::enterNumber(double num_a, double num_b, double num_c){
    a = num_a;
    b = num_b;
    c = num_c;
}
void GiaiPhuongTrinh::printResult()
{
    tinhNghiem();
    if (delta == -1){
        cout << "PT vo nghiem" << endl;
    }
    else if (delta == 0){
        cout << "PT co nghiem chung: " << x1 << endl;
    }
    else if (delta > 0){
        cout << "PT co 2 nghiem: \n";
        cout << "x1: " << x1 << endl;
        cout << "x2: " << x2 << endl;
    }    
}
int main(int argc, char const *argv[]){
    GiaiPhuongTrinh pt1;
    pt1.enterNumber(1,5,4);
    pt1.printResult();
    return 0;
}
```
## Tính đa hình (Polymorphism)
Polymorphism được định nghĩa là một Method có nhiều parameter khác nhau.

```c++
#include<iostream>
#include<string>
using namespace std;

class caculate{
    private:
        int a,b;
    public:
        void sum(int a, int b);         //cùng một method có nhiều parameter.
        void sum(int a, int b, int c);
        double sum(int a, double b);
};

void caculate::sum(int a, int b){
    cout << "Sum 2 number: " << a + b << endl;
}
void caculate::sum(int a, int b, int c){
    cout << "Sum 3 number: " << a + b + c << endl;
}
double caculate::sum(int a, double b){
    return a + b;
}

int main(int argc, char const *argv[]){
    caculate s;
    s.sum(10,10);
    s.sum(10,10,10);
    cout << "sum with double: "<< s.sum(10, 1.1);
    return 0;
}
```

# 15. VECTOR - LIST

## Vector

```c++
#include<iostream>
#include<string>
#include<vector>
using namespace std;

int main(int argc, char const* argv[]){
    vector<int> arrVt;
    arrVt.push_back(11);
    arrVt.push_back(22);
    arrVt.push_back(33);
    arrVt.push_back(44);

    for (int i =0; i< arrVt.size(); i++){
        cout <<"with posision is: "<< i << " value in array vector is: "<< arrVt[i] << endl;
    }  
    cout << "---------------------------" << endl;

    // Insert any position
    arrVt.insert(arrVt.end() - 3, 120);
    for (int i =0; i< arrVt.size(); i++){
        cout <<"with posision is: "<< i << "value in array vector is: "<< arrVt[i] << endl;
    }  
    cout << "---------------------------" << endl;

    // Delete any postion
    arrVt.erase(arrVt.begin() + 2);
        for (int i =0; i< arrVt.size(); i++){
        cout <<"with posision is: "<< i << "value in array vector is: "<< arrVt[i] << endl;
    } 
    return 0;
}
```

## List


```c++
#include<iostream>
#include<string>
#include<list>
using namespace std;

int main(int argc, char const* argv[]){
    list<int> arrList;

    arrList.push_back(10);
    arrList.push_back(20);
    arrList.push_back(30);
    arrList.push_back(40);
    arrList.push_back(50);
    arrList.push_back(60);
    arrList.push_back(70);
    arrList.push_back(70);

    // Acess List
    for(int i : arrList){
        cout << "Method 1: Value in list is: " << i << endl;
    }
    
    for(auto i : arrList){
        cout << "Method 2: Value in list is: " << i << endl;
    }
    cout << "--------------------------------------" << endl;
    // Delete any postion 
    list<int>::iterator postion = arrList.begin();  //  Initial poiter posion acess arrlist

    postion++;// Increment pointer position by 1 to access the 2nd element

    arrList.erase(postion); //Addition: we can delete data area with 2 pointer start-end ex: list.erase(iterator first, iterator last); 

    for(auto i : arrList){
        cout << "Value in list is: " << i << endl;
    }
    cout << "--------------------------------------" << endl;

    // Delete with value
    arrList.remove(70);
    for(auto i : arrList){
        cout << "Value in list is: " << i << endl;
    }
    cout << "--------------------------------------" << endl;
    
    // Insert value with any position
    list<int>::iterator postionAdd = arrList.begin();  //  Initial poiter posion acess arrlist

    postionAdd++;// Increment pointer position by 1 to access the 2nd element

    arrList.insert(postionAdd, 20);
    postionAdd++;
    postionAdd++;
    postionAdd++;
    postionAdd++;
    arrList.insert(postionAdd, 70);
    arrList.insert(postionAdd, 80);

    for(auto i : arrList){
        cout << "Value in list is: " << i << endl;
    }
    cout << "--------------------------------------" << endl;
    return 0;
}
```

## Vitrual Function & Pure Vitrual Function

Vitrual Function là Method được khai báo khi dùng lại cần định nghĩa lại (override)

Pure Vitrual Function là method thuần ảo không có phần thân và được gắn cho 0.
```c++
class Car{
public:
    const char* Display() { // a normal non-virtual function
        return "Hello world!"; 
    } 
    virtual const char* Display_Any() { // a normal virtual function
        return "This is a __Normal virtual function.__"; 
    }
    virtual int Display_With() = 0; // a pure virtual function
};
```

# 16. TEMPLATE

## Template
- Template cho phép tự chọn kiểu dữ liệu.

```c++
template <typename var, typename var1>
var sum(var a, var1 b){
    return (var) (a+b)
}

int main(int argc, char const *argv[]){
    print("sum a and b is %f \n", sum(1, 3.5));
    return 0; 
}
```

```c++
#include<iostream>
using namespace std;
template <typename type>
class SensorData{
    private:
        type data;
        int a;
    public:
        SensorData(type initData) : data(initData) {}
        void updateData(type newData){
            data = newData;
        }
        type getData() const{
            return data;
        }
};

int main(){
    SensorData<double> temperatureSensor(36.5);
    cout << "Temperature: " << temperatureSensor.getData() << endl;
    temperatureSensor.updateData(39.60);
    cout << "Temperature: " << temperatureSensor.getData() << endl;
    return 0;
}
```