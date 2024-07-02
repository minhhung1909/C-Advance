#include<stdio.h>

int main(){
    unsigned int a = 65536;
    unsigned short coercion = (unsigned int)a;
    printf("value is: %d \n",a );
    printf("coercion is: %d\n",coercion );
    return 0;
}