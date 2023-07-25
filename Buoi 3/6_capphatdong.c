#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    uint8_t *ptr = (uint8_t *)malloc(5); // tạo 5 byte kiểu uint8
 // hàm malloc là hàm trả về cho mình một địa chỉ và địa chỉ này là kiểu void nên không biết giá trị của địa chỉ này là kiểu gì cho nên ta cần phải ép kiểu

  // tạo 5 ô nhớ cho kiểu uint16
 // C1: uint16_t *ptr = (uint16_t *)malloc(2*5)
    uint16_t *ptr2 = (uint16_t *)malloc(sizeof(uint16_t)*5);

    for (int i = 0; i < 5; i++)
    {
        ptr[i] = 2*i;
    }
    for (int i = 0; i < 5; i++)
    {
        printf("i = %d\n", ptr[i]); 
    }

    
    //thay đổi size lên 7 ô nhớ
    ptr2 = (uint16_t *)realloc(ptr2, sizeof(uint16_t)*7);
// malloc, realloc được lưu ở Heap 
    free(ptr); // Thu hồi vùng nhớ 
    return 0;
}
