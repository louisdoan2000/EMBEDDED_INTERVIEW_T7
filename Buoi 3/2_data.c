#include <stdio.h>
//Static toàn cục và cục bộ sẽ được lưu ở phân vùng data
static i = 10; //toàn cục

void test(){
    static n = 6; // cục bộ
}

//Nó được giải phóng khi kết thúc chương trình 

int main(int argc, char const *argv[])
{
    i = 20;
    return 0;
}
