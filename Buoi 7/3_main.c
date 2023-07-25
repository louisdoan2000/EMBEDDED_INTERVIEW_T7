#include <stdio.h>
#include <stdint.h>

#define CREATE_FUNC(func_name, cmd) \
void func_name(){                   \
    printf(#cmd);                   \
}

CREATE_FUNC(funcA, This is function A);
CREATE_FUNC(funcB, "This is function B\n");

int main(int argc, char const *argv[])
{
    funcA();

    funcB();
    return 0;
}
