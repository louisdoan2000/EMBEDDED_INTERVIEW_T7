#include "stm32f10x.h"                  // Device header
#include "stm32f10x_gpio.h"             // Keil::Device:StdPeriph Drivers:GPIO
#include "stm32f10x_rcc.h"              // Keil::Device:StdPeriph Drivers:RCC


#define RX			GPIO_Pin_8
#define GPIOx		GPIOB

void config();
void wait_Start();
void wait_End();
uint8_t receive();
void delayMs (uint32_t ms);

void delay(int ms){
	for(int i=0; i<ms; i++)
		for(int j=0; j<4500; j++);
}


void TIM2_INT_Init()
{
  
	/* Init struct */
	TIM_TimeBaseInitTypeDef TIM_TimeBaseInitStruct;
	
	/* Enable clock for TIM2 */
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2, ENABLE);
  
	/* 
	 * TIM2 initialization for overflow every 1ms
   * Update Event (Hz) = timer_clock / (TIM_Prescaler * Time_unit)
	 * Update Event (Hz) = 72MHz / (3600 * 1000) = 20Hz (1ms)
   */
	TIM_TimeBaseInitStruct.TIM_Prescaler = 1000;
	TIM_TimeBaseInitStruct.TIM_Period = 31;
	TIM_TimeBaseInitStruct.TIM_ClockDivision = TIM_CKD_DIV1;
	TIM_TimeBaseInitStruct.TIM_CounterMode = TIM_CounterMode_Up;
	TIM_TimeBaseInit(TIM2, &TIM_TimeBaseInitStruct);
	
	/* Enable TIM2 interrupt */
	TIM_ITConfig(TIM2, TIM_IT_Update, ENABLE);
	
	/* Start TIM2 */
	TIM_Cmd(TIM2, ENABLE);

	NVIC_InitTypeDef NVIC_InitStruct;

	NVIC_InitStruct.NVIC_IRQChannel = TIM2_IRQn;
	NVIC_InitStruct.NVIC_IRQChannelPreemptionPriority = 0x00;
	NVIC_InitStruct.NVIC_IRQChannelSubPriority = 0x00;
	NVIC_InitStruct.NVIC_IRQChannelCmd = ENABLE;
	NVIC_Init(&NVIC_InitStruct);
	
}

uint32_t milliSec = 0; // có th? d? static d? file khác không truy c?p du?c

void TIM2_IRQHandler () { 
	
		milliSec++;

		TIM_ClearITPendingBit(TIM2, TIM_IT_Update);

}

void delayMs (uint32_t ms) {
	
	milliSec = 0;
	
	while (milliSec < ms) {};
}

int main() {
	
	uint8_t data = 0x00;
	config();
	GPIO_SetBits(GPIOx, RX);
	delay(1000);
	while(1){
	
		
		//wait_Start();
		data = receive();	
		wait_End ();
	}
	return 0;
}

void wait_Start() {
	while(GPIO_ReadInputDataBit(GPIOx, RX)== 1);
	delay(15);

}
	
void wait_End() {
	while(GPIO_ReadInputDataBit(GPIOx, RX) == 0);
	delay(200);
} 

void config_LED() {
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC, ENABLE);
	GPIO_InitTypeDef gpioc;
	gpioc.GPIO_Mode = GPIO_Mode_Out_PP;
	gpioc.GPIO_Pin = GPIO_Pin_13;
	gpioc.GPIO_Speed = GPIO_Speed_50MHz;
	
	GPIO_Init(GPIOC, &gpioc );
}



void config() {

	GPIO_InitTypeDef gpio;
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);
	
	gpio.GPIO_Pin = RX;
	gpio.GPIO_Mode = GPIO_Mode_IPU;  
	gpio.GPIO_Speed = GPIO_Speed_2MHz;
	
	GPIO_Init(GPIOx, &gpio);   // kiem tra lai
}

uint8_t receive() {
	uint8_t data = 0x00;
	uint8_t count = 0;
	while(GPIO_ReadInputDataBit(GPIOB, RX) == 1);
	
	
	delay(300); // bit start + 1/2 bittime de slave nhan bit dau tien
	
	for(uint8_t i = 0; i< 9; i++) { // 8 bit va 1 bit P(bit de kiem tra)
		if (GPIO_ReadInputDataBit(GPIOB,RX)== 1) {
			count ++;
			if(i < 8)	data = data | (1<<i); // Nhan 8 bit 
		}
		delay(200); //delay 1 khoang thoi gian bit time
	}
	if(count %2 != 0) { // thong bao loi: cho chuong trinh thoat ra hoac blink LED
		config_LED();
		while(1) {
		GPIO_SetBits(GPIOC, GPIO_Pin_13);
		delay(500);
		GPIO_ResetBits(GPIOC, GPIO_Pin_13);
		delay(500);
		}
	}
	
	return data;
}

