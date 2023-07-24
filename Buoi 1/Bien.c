#include <stdio.h>
#include <stdint.h>

uint8_t var; // 
uint32_t var2; // 0-(2^32-1)
int16_t var3; // -(2^16)/2 - (2^16)/2-1

int main()
{
    var = 255;
    printf("test: %d", var);
    return 0;
}