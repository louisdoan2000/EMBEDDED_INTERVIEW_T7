#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

void test1(){
    uint8_t array[5];
    printf("Dia chi: %p\n",array);
  
}

void test2(){
    uint8_t *array = (uint8_t*)malloc(sizeof(uint8_t)*5);
    printf("Dia chi: %p\n", array);
    free(array); //thu hồi địa chỉ 
}

int main(int argc, char const *argv[])
{
    test1();
    test1();




    test2();
    test2();
    return 0;
}
