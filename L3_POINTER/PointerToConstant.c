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