#include <stdio.h>
#include "test.c"

#define SIZE 20

#define SUM(a,b) a+b 

int var  = 10;

int main(int argc, char const *argv[])
{
    test();
    int array[SIZE];
    printf("Tong a va b = %d\n ", SUM(5,6));
    return 0;

}
