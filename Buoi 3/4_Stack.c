#include <stdio.h>

void tong(int a, int b){
    int c;
    c = a + b;

    printf("dia cho a: %p\n", &a);
    printf("dia cho b: %p\n", &b);
    printf("dia cho c: %p\n", &c);

}
// những input parameter, local được lưu ở Stack 
int main(int argc, char const *argv[])
{
    tong(6,9); // khởi tạo int a = 6
              // khởi tạo int b = 9
              // int c 
// Khi gọi hàm tong  thì nó sẽ khởi tạo và lưu ở những địa chỉ. 
// Khi chạy hết chương trình thoát ra khỏi hàm tong thì những địa chỉ đó bị thu hồi  
    printf("--------\n");

    tong(2,7); 

    return 0;
}
