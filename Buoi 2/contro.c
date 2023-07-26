#include <stdio.h>

int a =10;

void test(){
    printf("this is test\n");
}


int main(int argc, char const *argv[])
{
    int *ptr = &a;
    printf("dia chi %p\n", &test);
    printf("dia chi a %p\n", &a );

    printf("gia tri ptr %p\n", ptr);

    printf("gia tri cua bien ma con tro dang quan li %d ", *ptr);
    
    return 0;
}

