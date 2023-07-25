#include <stdio.h>

void test(){
    static int a =10;  // giả sử có địa chỉ là 0xc1
    printf("a = %d\n", a);
    a++;
}

int *ptr(){
   // int a = 10; // sẽ được lưu ở phân vùng stack cho nên sau khi kết thúc câu lệnh thì đã thu hồi địa chỉ nên khi trả về &a sẽ báo lỗi
      static int a = 10; // địa chỉ này sẽ tồn tại sẽ không bị thu hồi --> không báo lỗi
    return &a;
}

int main(int argc, char const *argv[])
{
    printf("test: %d\n", *ptr());
    return 0;
}
