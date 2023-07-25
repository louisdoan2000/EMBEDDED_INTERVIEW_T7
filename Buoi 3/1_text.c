#include <stdio.h>
const int i = 10;

int main(int argc, char const *argv[])
{
    i = 20; // báo lỗi
   printf("i = %d\n", i);
    return 0;
}
// Được lưu ở phân vùng text, chỉ đọc mà không ghi được