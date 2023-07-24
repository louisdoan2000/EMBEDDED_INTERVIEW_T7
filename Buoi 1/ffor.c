#include <stdio.h>
#include <stdint.h>

int main()
{ 
    

    for(int i=0;i<10;i++)
    {
        if(i ==5) continue; // 1 thằng duy nhất nằm trong ngoặc. Khác với break, khi gặp countinue thì sẽ dừng ngay bước này và thực hiện tiếp tục
        printf("i = %d\n",i);
    }

    return 0;


}