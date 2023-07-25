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

int *ptr = NULL;
printf("test: %p\n", ptr);

return 0;

}
