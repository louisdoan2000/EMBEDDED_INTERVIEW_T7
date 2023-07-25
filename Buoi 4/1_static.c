#include <stdio.h>

void test(){
    static int a =10;  // giả sử có địa chỉ là 0xc1
    printf("a = %d\n", a);
    a++;
}

int main(int argc, char const *argv[])
{
    test(); // nó sẽ được lưu ở phân vùng nhớ đó 
    test(); // khi chạy lần 2 thì sẽ không khởi tạo lại mà tiếp tục thực hiện tức là a + 1 
    test(); // tương tự

    return 0;
}
