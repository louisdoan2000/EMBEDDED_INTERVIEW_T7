#include <stdio.h>
#include <stdint.h>
//enum: trong enum số đầu tiên bằng 0
typedef enum Thu{
    Thu2,
    Thu3,
    Thu4,
    Thu5,
    Thu6,
    Thu7,
    CN
} Thu;
int main(int argc, char const *argv[])
{
   Thu thu = Thu2; // đặt tên biến và khai báo 
    switch (thu)
    {
    case Thu2: 
        printf("Thu 2\n");
        break;
    case Thu3: 
        printf("Thu 3\n");
        break;
    case Thu4: 
        printf("Thu 4\n");
        break;
    case Thu5: 
        printf("Thu 5\n");
        break;
    case Thu6: 
        printf("Thu 6\n");
        break;
    case Thu7: 
        printf("Thu 7\n");
        break;
    case CN: 
        printf("CN\n");
        break;
    default:
        printf("Thu khong hop le\n");
        break;
    }
  return 0;
}