#include <stdio.h>
#include <stdint.h>

#define FUNC(type, name)     \
type var1##name;             \
type var2##name;             \
type var3##name;             
// ## dùng để nối chuỗi

int main(int argc, char const *argv[])
{
    FUNC(int, test);
    return 0;
}
