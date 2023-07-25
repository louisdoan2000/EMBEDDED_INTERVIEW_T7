#include <stdio.h>
#include <stdint.h>
struct hocsinh{
uint8_t x; // 1 byte
uint16_t y; // 2 byte
uint32_t z;  // 4 byte
}toaDo;

int main(int argc, char const *argv[])
{
    printf("size: %d\n", sizeof( struct hocsinh));
    return 0;
}



