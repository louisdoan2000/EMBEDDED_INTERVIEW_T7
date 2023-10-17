#include <iostream>

int main(int argc, char const *argv[])
{
    auto func = [](){
    printf("Hello world\n");};
    func();
    

    int x = 30; //chỉ được sử dụng cục bộ
    double z = 12.4;

    auto tong = [=](int a, int b){ // trên 2 biến sử dụng dấu bằng trong dấu []
        printf("Tong %d va %d: %d\n  ", a, b, a+b);
        printf("x = %d\n", x);
        printf("z = %f\n", z);
    };
    tong(7,9);
    return 0;

}
