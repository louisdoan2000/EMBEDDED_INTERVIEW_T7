#include <stdio.h>
#include <stdint.h>

int main(int argc, char const *argv[])
{
    int diem = 7;
    if (diem >=8) 
    {
    printf("hoc sinh gioi");}
    else if (diem >=7){
    printf("Hoc sinh kha\n");
    }else{
    printf("Hoc sinh trung binh");
    } 
    return 0;
}

// int diem = 8;
//     if (diem >=8) 
//     {
//     printf("hoc sinh gioi");}
//     if (diem >=7){
//     printf("Hoc sinh kha\n");
//     }if{
//     printf("Hoc sinh trung binh");
//     } 
// ra kết quả giống như sử dụng else if nhưng sẽ tốn nhiều thời gian hơn. Vì nó sẽ kiểm tra lại qua các hàng khác. if Esle khi đúng thì nó sẽ không kiểm tra lại. 