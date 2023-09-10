#include <iostream>

template <typename var>

var tong(var a,var b){
    return var(a+b);
}

int main(){
    printf("tong a va b:%d\n",tong(4,5));
    
    printf("tong a va b: %f\n",tong(4.3,5.2));
    return 0;
}