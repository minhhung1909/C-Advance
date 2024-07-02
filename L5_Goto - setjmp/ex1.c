#include"stdio.h"
#include"setjmp.h"

jmp_buf buf;
int exception_code;
char error_codep[100];
#define TRY if ((exception_code = setjmp(buf)) == 0) 
#define THROW(x, tmp)   longjmp(buf, (x)); 

#define CATCH(x) else if (exception_code == (x))



double divide(int a, int b) {
   if (b == 0) {
       THROW(1, "Lỗi: Phép chia cho 0!"); // Sử dụng mã lỗi 1 cho lỗi chia cho 0
   }
   return (double)a / b;
}

int main() {
    int a = 10;
    int b = 0;
    double result = 0.0;
    

    TRY {
        result = divide(a, b);
        printf("Result: %f\n", result);
    } CATCH(1){
        printf("%s\n", error_code);
    }
    return 0;
}