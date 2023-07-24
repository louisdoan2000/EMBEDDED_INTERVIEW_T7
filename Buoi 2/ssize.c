#include <stdio.h>
void tong(int a, int b){
    printf("tong %d va %d = %d\n", a, b, a+b);
}

void hieu(int a, int b){
    printf("hieu %d va %d = %d\n", a, b, a-b);
}

void tich(int a, int b){
    printf("tich %d va %d = %d\n", a, b, a*b);
}

void tinhtoan(void(*func)(int, int), int a, int b ){
    printf("Tinh toan\n");

    func(a,b);
}
int main(int argc, char const *argv[])
{
//int *ptr // nó sẽ trỏ đến địa chỉ rác, gây ngủy hiểm lúc lập trình

//void *ptr = NULL;
//printf("size: %lu byte\n", sizeof(ptr));


void *ptr= &tong;
printf("size: %p\n", ptr);
// biến con trỏ phụ thuộc vào kiến trúc của vi xử lí
//64 /8bit = 8 byte
//32/8 = 4

return 0;
}
