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
void *ptr = &tong;
((void(*)(int,int))ptr)(7,5);



return 0;

}
