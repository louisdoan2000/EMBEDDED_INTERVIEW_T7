#include <stdio.h>
#include <stdint.h>

int main(int argc, char const *argv[])
{
    uint8_t array[] = {1, 7, 3, 5, 9}; // kiểu 8 bit nên ô nhớ của mảng này là 1byte
    //uint16_t thì là 2 byte


for (int i = 0; i < 5; i++)
{
    printf("dia chi: %p\n", array+i);

    
}   

// Mảng là những địa chỉ liền kề
uint32_t array1[]={2, 5, 7, 6, 8}; 

uint32_t *ptr = array1;

for (int i = 0; i <5; i++)
{
    printf("dia chi: %p\n",(ptr+i));
    printf("gia tri: %d\n",*(ptr+i));
}

return 0;


}
