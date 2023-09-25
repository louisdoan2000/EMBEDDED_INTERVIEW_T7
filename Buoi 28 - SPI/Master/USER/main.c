#include "stm32f10x.h"                  // Device head
#include "stm32f10x_rcc.h"              // Keil::Device:StdPeriph Drivers:RCC
#include "stm32f10x_tim.h"
#include "stm32f10x_gpio.h"

#define SCK  GPIO_Pin_6
#define MOSI GPIO_Pin_7
#define SS   GPIO_Pin_8
#define PORT 		GPIOB



 void delay(int ms);
 void config(void);
 void spiInit(void);
 void clock(void);
 void transmit(uint8_t data);




int main () {

		config();

		spiInit();
	
		uint8_t data = 0xAA; //170
	
		delay(5000);
		transmit(data);
	
		return 0;
}


void delay (int ms) {
	for (int i = 0; i < ms; i++)
		for(int j=0; j<4500; j++);
}

void config() {
	
	GPIO_InitTypeDef gpio;
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);
	
	gpio.GPIO_Pin = SCK | MOSI | SS;
	gpio.GPIO_Mode = GPIO_Mode_Out_PP;
	gpio.GPIO_Speed = GPIO_Speed_2MHz;
	GPIO_Init(PORT, &gpio);
	
}
void spiInit () {
	
	GPIO_ResetBits(PORT, SCK);
	GPIO_ResetBits(PORT, MOSI);
	GPIO_SetBits(PORT, SS);
	
}

void clock () {
	
	GPIO_ResetBits(GPIOB, SCK);
	delay(50);
	GPIO_SetBits(GPIOB, SCK);
	delay(50);
	
	}

 void transmit(uint8_t data) {
	
		GPIO_ResetBits(GPIOB, SS);
	 
		for (uint8_t i = 0; i< 8; i++) {
			//1010 1010 & 0000 0001   (1 << 0)  // thao tac bit 1 dich 0
			//						0000 0010		(1 << 1)
			//						0000 0100		(1 << 2)	
				if ((data & (0x01 << i))) GPIO_SetBits(GPIOB, MOSI);
				else GPIO_ResetBits(GPIOB, MOSI); 
			// Cách thao tác bit và kiem tra dien ap cua chan MOSI tuong ung
				clock();
		}
		GPIO_ResetBits(PORT, SCK);
		GPIO_ResetBits(PORT, MOSI);
		GPIO_SetBits(GPIOB , SS);  // SS ve muc 1 de dung
		
 }
























