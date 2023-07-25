#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

//malloc: 

int main(int argc, char const *argv[])
{
    uint8_t *ptr = (uint8_t *)malloc(5);
    for (int i = 0; i<5; i++)
    {ptr[i] = 2*i;}
    for (int i = 0; i < 5; i++)
    {
        printf(" i =: %d\n", ptr[i]);
    }
    ptr = (uint16_t *)realloc(ptr, sizeof(uint16_t)*7);
    for (int i = 0; i<7; i++){
    ptr[i] = 2*i;}
    for (int i = 0; i < 7; i++)
    {
        printf(" i =: %d\n", ptr[i]);

    }
   return 0;
}
 