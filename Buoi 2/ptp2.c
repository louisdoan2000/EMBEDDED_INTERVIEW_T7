#include <stdio.h>

int main(int argc, char const *argv[])
{
    int a = 10;
    int *ptr1 = &a;
    int **ptr2 = &ptr1;

    printf("Dia chi cua a: %p\n", &a );  //qua a
    printf("Dia chi cua a: %p\n", ptr1 );// qua ptr 1
    printf("Gia tri cua a: %d\n", *ptr1 );
    printf("Gia tri cua ptr1: %d\n", *ptr1 );
    printf("Gia tri cua a: %d\n", **ptr2 ); // thông qua ptr2
    printf("Dia chi cua a: %p\n", ptr2 );  //thông qua ptr 2
    return 0;
}
