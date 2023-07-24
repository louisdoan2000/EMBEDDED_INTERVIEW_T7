#include <stdio.h>
#include <stdint.h>
//struct là kiểu dư liệu do người dùng tự định nghĩa
struct Toado
{
 uint8_t x;
 uint8_t y;
};
struct Ketqua{
    float x1;
    float x2;
};

typedef struct Ketqua Ketqua;

Ketqua Hephuongtrinh(int a, int b, int c){
   Ketqua dapan;

   return dapan;
}





int main(){
 //struct Toado diemM;
 //diemM.x = 10;
 //diemM.y = 20;
 
 //printf("Toa do diem M: M.x = %d, M.y = %d\n", diemM.x, diemM.y );

 //return 0;
 Ketqua dapAn = {.x1 = 20, .x2 = 10};
            // ={20,10};
 printf("result: %f - %f", dapAn.x1, dapAn.x2);
 return 0;
  
}

