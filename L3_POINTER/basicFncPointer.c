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