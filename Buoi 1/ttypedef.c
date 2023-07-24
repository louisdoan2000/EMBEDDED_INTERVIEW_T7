// Dùng typedef để đặt tên


#include <stdio.h>
#include <stdint.h>

typedef int typeInt;

int main()
{
    typeInt var = 10;
    printf("test: %d\n", var);
    return 0;
}
