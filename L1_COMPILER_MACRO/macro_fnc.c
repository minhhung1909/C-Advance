#include"stdio.h"
#define CREATE_FNC(name, cmd)       \
void name(){                        \
    printf(#cmd);              \
}

#define CREATE_VAR(name)    \
    int int_##name;         \
    float float_##name;     \
    char char_##name;       \

CREATE_FNC(fnc1, hello FNC 1 \n);
CREATE_FNC(fnc2, hello FNC 2 \n);

int main(int argc, char const *argv[]){
    fnc1();
    CREATE_VAR(temp)
    fnc2();
    return 0;
}