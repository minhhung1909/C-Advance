#include<stdio.h>
#include"stdarg.h"

int display(int count, ...){
    va_list args;   
    va_start(args, count);
    
    // for(int i; i < count; i++){
    //     printf("index %d, value %d \n",i, va_arg(args,int));
    // }
    printf("value: %d \n", va_arg(args,int));
    printf("value: %.1f \n", va_arg(args,double));
    va_end(args);
}

int sum(int volume, ... ){
    va_list nums;
    va_start(nums, volume);
    int result = 0;
    for(int i = 0; i < volume; i++){
        // va_arg(nums, int);
        result += va_arg(nums, int);
    }
    printf("Sum value is: %d \n", result);
    va_end(nums);
}

int main(int argc, char const *argv[]){
    display(3,1,5.5,10);
    sum(3,1,2,3);
    return 0;
}