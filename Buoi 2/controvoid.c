#include <stdio.h>
void test(){
    printf("this is test\n");
}


int main(int argc, char const *argv[])
{
    int i = 10;

    double d = 10.3;

    char c = 'A';

    //int *ptr = &d; : máy sẽ báo lỗi vì không cùng kiểu dữ liệu
    
    void *ptr; // là con trỏ đặc biệt, nó sẽ trỏ đến địa chỉ của mọi đối tượng không cần biết đó là kiểu dữ liệu gì
    

    ptr = &i; 
    // printf(" gia tri cua ptr %p\n", *ptr); : in ra lỗi vì nó chỉ biết địa chỉ của i chứ không biết nó mang kiểu dữ liệu gì nên ta phải ÉP KIỂU
    printf("test i = %d\n", *(int*)ptr ); // (int*)ptr: giá trị của địa chỉ này là kiểu integer
    
    ptr = &d;

    printf("test d = %f\n", *(double*)ptr);

    ptr = &c;
    printf("test c = %c\n", *(char*)ptr);
 return 0;
}

