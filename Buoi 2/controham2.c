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

//input là 1 hàm dùng 1 con trỏ hàm
// cú pháp: void tenham(void(*tencontro)(kieu dau vao, kieu dau vao), tham so dau vao, tham so dau vao)
void tinhtoan(void(*func)(int, int), int a, int b ){
    printf("Tinh toan\n");

    func(a,b);
}
int main(int argc, char const *argv[])
{
  tinhtoan(&tong, 4, 9);   
  tinhtoan(&hieu, 8, 2);
  tinhtoan(&tich, 2, 6);
    return 0;
}
