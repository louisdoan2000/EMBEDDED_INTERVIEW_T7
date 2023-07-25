#include <stdio.h>
#include <stdint.h>

#define FUNC(...) __VA_ARGS__
int name;

int main(int argc, char const *argv[])
{
    FUNC(test,"Hello World", 15 ); //  __VA_ARGS__sẽ hiển thị ra ở phần FUNC    


    return 0;
}
