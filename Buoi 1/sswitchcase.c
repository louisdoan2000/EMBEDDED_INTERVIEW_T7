#include <stdio.h>
#include <stdint.h>


int main(int argc, char const *argv[])
{
   Thu thu = Thu2;
    switch (thu)
    {
    case 2: 
        printf("Thu 2\n");
        break;
    case 3: 
        printf("Thu 3\n");
        break;
    case 4: 
        printf("Thu 4\n");
        break;
    case 5: 
        printf("Thu 5\n");
        break;
    case 6: 
        printf("Thu 6\n");
        break;
    case 7: 
        printf("Thu 7\n");
        break;
    case 8: 
        printf("CN\n");
        break;
    default:
        printf("Thu khong hop le\n");
        break;
    }
  return 0;
}
