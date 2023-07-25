#include <stdio.h>

#define SIZE 10

#if SIZE >20

int a = 30;

#elif SIZE == 20

int a =20;

#else 

int a = 10;

#endif 




int main(int argc, char const *argv[])
{
    printf("tong a va b: %d\n", SUM(5,6));
    printf("tong a va b: %d\n", SUM(15,6));
   
    return 0;
}
