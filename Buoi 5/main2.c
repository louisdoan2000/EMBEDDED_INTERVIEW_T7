#include <stdio.h>
#include <stdint.h>
#include <string.h>

typedef union{
    struct 
    {
        uint8_t id[2];
        uint8_t data[3];
        uint8_t checkSum[1];

    }object;
    uint8_t array[6];
    
}dataFrame;

int main(int argc, char const *argv[])
{
    //Gói data cần phải truyền: 1 byte ID
    //                          3 byte DATA
    //                          1 byte CS
    //                          0x01 0xC2 0xF8 
    dataFrame test;

    test.object.id[0] = 0x01;
    test.object.id[1] = 0x02;
   
    test.object.data[0] = 0xC8;
    test.object.data[1] = 0xF8;
    test.object.data[2] = 0xF2;

    test.object.checkSum[0] = 0xA7;
    return 0;
}
