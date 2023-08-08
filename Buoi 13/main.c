#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <stdbool.h>




typedef struct {
    char *ptr;
    int length;
} words;

char String[] = "Housing supply in Ho Chi Minh City has recovered after a sharp dip in the first half of the year";

//char output[];
int size(char string[]){
    char *ptr = String;
    int size = 1;
    while (*ptr !='\0')
    {
        if (*ptr == ' ') size++;
        ptr++;
    }
    
    return size;
}

//Hàm tách các từ 
words *splitwords(char String[]){
    int a = size(String);
    words *array = (words*)malloc(sizeof(words)*a);
    int index = 0;
    int count = 1;
    array[index].ptr = String;

    while(*String != '\0')
    {
        if(*String == ' ')
    {
        array[index].length = count;
        count = 1;
        String++;
        array[++index].ptr = String;
    }
    
        else{
        count++;
        String++;    
        
    }  
    }
    array[index].length = count;

    return array;
}



void printwords(words print){
    for(int i = 0; i < print.length; i++ ){
        printf("%c",print.ptr[i]);
    } 
}

int main(int argc, char const *argv[])
{
    words *ptr = splitwords(String);
    printf(" Chuoi nghich dao: ");
    int a = size(String);
    printwords(ptr[a-1]);
    printf(" ");            // Vì chữ cuối cùng không có khoảng trắng nên gán thêm khoảng trắng
    for (int i = a-2; i>=0; i--)
    {
        printwords(ptr[i]);
    }
    
    return 0;
}
