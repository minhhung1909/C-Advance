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