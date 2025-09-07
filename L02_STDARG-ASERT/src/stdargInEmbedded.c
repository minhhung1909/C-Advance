#include<stdio.h>
#include"stdarg.h"

typedef struct Data
{
    char RoomName[20];
    int ID;
    double Temp;    
}Data;
 
void display(int count, ...){
    va_list args;
    va_start(args, count);
    for(int i = 0; i < count; i++){
        Data tmp = va_arg(args, Data);
        printf("Room Name is: %s \n", tmp.RoomName);
        printf("ID room is: %d \n", tmp.ID);
        printf("Temp in Room is: %.1f\n", tmp.Temp);
    }
    va_end(args);
}

int main(int argc, char const *argv[]){
    display(3, (Data){"Sheldon", 1, 36.5},(Data){"Max Le", 2, 26.3},(Data){"John", 3, 10.4});
    return 0;
}