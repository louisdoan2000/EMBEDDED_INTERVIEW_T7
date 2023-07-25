#include <stdio.h>
#include <time.h>


int main(int argc, char const *argv[])
{
    clock_t start, end;

    double test;

     int i;

    start = clock();

    for ( i < 0xFFFFFFFF; i++);

    end = clock();

    test = ((double)(end - start))/CLOCKS_PER_SEC;

    printf("time: %f\n", test);
    
   


    return 0;
}