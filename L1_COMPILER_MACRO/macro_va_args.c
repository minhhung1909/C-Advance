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

    PRINT_MENU("Option 1", "Option 2", "Option 3","Option4", "Exit","Option4","Option4","Option4","Option4");

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