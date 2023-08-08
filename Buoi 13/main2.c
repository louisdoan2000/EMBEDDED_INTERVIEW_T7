#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <stdbool.h>

int a = 123456789;

int size(a){
    int size = 0;
    while(a>10){
        a = a/10;
        size++;
    }
    return size;
}

char unit[]={'mot','hai','ba','bon','nam','sau','bay','tam','chin'};



int main(int argc, char const *argv[])
{   
   
    return 0;
}
