// chương trình có tính lặp đi lặp lại nên ta sử dụng hàm 
// hàm có tham số đầu vào gọi là input parameter 
// chỉ hàm void không có kiểu trả về còn các hàm khác đều có 

// int tong(int a, int b){
//   printf("Tong %d va %d = %d", a, b, a + b);
// return a +b;
// }
//int main(){
//    printf("Tong cua hai so a va b: %d\n, tong(6,7));
//    return 0;
//}


#include <stdio.h>
#include <stdint.h>

void tong(int a, int b){
    printf("Tong %d va %d = %d", a, b, a + b);
}

int main(){
    tong(10,7);

    tong(6,5);
    return 0;
}
