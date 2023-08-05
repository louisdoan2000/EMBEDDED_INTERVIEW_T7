#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <stdlib.h>



typedef struct{
    char *ptr;       //địa chỉ đầu tiên của tên
    uint8_t length; //độ dài của tên
}words;


char string[] = "nhat hoang tuan nam nhat tuan hoang nhat nam bao quoc nam";

bool isEqual(const char arr1[], const char arr2[]){
    while(*arr1 == *arr2){
        if(*arr1 == '\0'){
            return true;
        }
        arr1++;
        arr2++;

    }
        if (*arr1 > *arr2){
            return true;
        }       
    return false;

}

bool sosanh(words arr1, words arr2){
    while(arr1.length == arr2.length){
        if(arr1.length == '\0'){
            return true;
        }
        arr1.length++;
        arr2.length++;
    }
    return false;
}

words *splitString(char string[]){
    uint8_t size = 1;
    char *ptr = string;
    while (*ptr != '\0')
    {
        if(*ptr == ' ') size++; // tính xem có bao nhiêu phần tử. Khi gặp khoảng trắng thì đếm 
        ptr++;
    }

    words *array = (words*)malloc(sizeof(words)*size); // tạo số ô nhớ lưu các tên trong chuỗi có kiểu dữ liệu words( 12 phần tử)
    uint8_t index = 0; // chỉ số của mảng
    uint8_t count = 1; //  
    array[index].ptr = string; // bằng địa chỉ đầu tiên của mảng 

    while(*string !=  '\0')
    {

        if (*string == ' '){
            array[index].length = count;
            count = 1;
            string++;
            array[++index].ptr = string;
        }else{
            count++;
            string++;
        }       
    }
    array[index].length = count;

    return array;
}

//đếm số lần xuất hiện 
void sortAlphabet(words array[], int size){
    for (int i = 0; i < size -1; i++)
    {
        words temp;
        for(int j = i +1; j < size; j ++){
            if (isEqual(array[i].ptr, array[j].ptr)){
            temp = array[i];
            array[i] = array[j];
            array[j] = temp;
            } 
        }
    }
}
void test(words test){
    for (int i = 0; i < test.length; i++)
    {
        printf("%c", test.ptr[i]);
    }
}

void occurence(words array[], int size){
    int count = 1;
    for (int i = 0; i < size-1; i++)
    {
        //for ( int j = 0; j < size; j++)
        //{
            
            if (sosanh(array[i], array[i+1]))
        {
            count++;
        }
        else{
            test(array[i]);
            printf("xuat hien: %d\n", count);
            count = 1;

        } 
        //} 
    }
}



int main(int argc, char const *argv[])
{
    words *ptr = splitString(string);
    sortAlphabet(ptr, 12);
    occurence(ptr,12);


    // for (int i = 0; i < 12; i++)
    // {
    //     test(ptr[i]);
    //     printf("\n");
    // }
    
    return 0;
}



