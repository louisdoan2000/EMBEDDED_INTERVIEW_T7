#include "stm32f10x.h"                  
#include "stm32f10x_gpio.h"             



void config(void)
{
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC, ENABLE);
	GPIO_InitTypeDef gpio;
	gpio.GPIO_Mode = GPIO_Mode_Out_PP;
	gpio.GPIO_Pin = GPIO_Pin_13;
	gpio.GPIO_Speed = GPIO_Speed_50MHz;
	
	GPIO_Init(GPIOC, &gpio );
}

void delay(unsigned int TIME)
{
	unsigned int i, j;
	for(i=0;i<TIME;i++)
		for(j=0;j<7998;j++);
	
}
int main(void)
{
	config();
	while(1)
	{
		GPIO_SetBits(GPIOC, GPIO_Pin_13);
		delay(500);
		GPIO_ResetBits(GPIOC, GPIO_Pin_13);
		delay(500);
	}
}