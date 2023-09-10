#include <iostream>

template <typename var1,typename var2>

var1 tong(var1 a,var2 b){
    return var1(a+b);
}

int main(){
    printf("tong a va b:%d\n",tong(4,5));
// 4 là int=> var 1 là int , 5 là int => var2 là int
    printf("tong a va b: %f\n",tong(4.3,5));

//4.3 var 1 là double, var 2 là int . ép kiểu cho var 1 theo double

    return 0;
}
