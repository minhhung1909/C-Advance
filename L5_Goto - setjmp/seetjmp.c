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