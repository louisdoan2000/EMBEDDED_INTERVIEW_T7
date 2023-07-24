#include <stdio.h>
// con trỏ hàm sẽ trỏ đến địa chỉ của hàm
void tong(int a, int b){
    printf("tong %d va %d = %d\n", a, b, a+b);
}

void hieu(int a, int b){
    printf("hieu %d va %d = %d\n", a, b, a-b);
}

int tich(int a, int b){
    return a*b;
}
int main(int argc, char const *argv[])
{
    void(*ptr)(int,int);

    ptr = &tong;
    ptr(8,7);
    ptr = &hieu;
    ptr(10,6);
    
    int (*ptrtich)(int,int) = &tich;
    printf("tich %d\n", ptrtich(6,5));
    return 0;
}
