#include <stdio.h>
#include <stdint.h>

#define STM32   0
#define PIC16F  1
#define ATMEGA  2

typedef enum{
    LOW,
    HIGH,
}Status;

typedef enum{
    PIN0 <<0,
    PIN1<<1
}Pins;

#if MCU == STM32

void digitalwrite(Pins pin, Status status){
    DAC| pin ~status;
}

#elif MCU == PIC16F

void digitalwrite(Pins pin, Status status){
    CTP| pin ~ASC ~status;
}

#define MCU PIC16F
#include "config.h"

int main(int argc, char const *argv[])
{
    while (1)
    {
        digitalwrite(PIN0, HIGH);
    }
    
    return 0;
}
