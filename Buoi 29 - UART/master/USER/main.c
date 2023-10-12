	#include "stm32f10x.h"                  // Device header
	#include "stm32f10x_gpio.h"             // Keil::Device:StdPeriph Drivers:GPIO
	#include "stm32f10x_rcc.h"              // Keil::Device:StdPeriph Drivers:RCC

	#define		TX			GPIO_Pin_8
	#define		GPIOx		GPIOB

	void config();
	void start_Condition();
	void end_Condition();
	void stop_bit();
	void transmit(uint8_t data);
//uint8_t count_Bit1(uint8_t data);
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
	TIM_TimeBaseInitStruct.TIM_Prescaler = 3600;
	TIM_TimeBaseInitStruct.TIM_Period = 19;
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

	

	void config() {
	GPIO_InitTypeDef gpio;
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);
	
	gpio.GPIO_Pin = TX;
	gpio.GPIO_Mode = GPIO_Mode_Out_PP;  // Che do co the keo len muc 1 hoac keo xuong muc 0
	gpio.GPIO_Speed = GPIO_Speed_2MHz;
	GPIO_Init(GPIOx, &gpio);   
	
}

	void start_Condition () {
		GPIO_ResetBits(GPIOx, TX);
		delay(200);
}

void stop_bit() {
	GPIO_SetBits(GPIOB, TX); 
	delay(200); // 1 bit start

}

void transmit (uint8_t data) {
		uint8_t count = 0;
		
		for (uint8_t i = 0; i < 8; i++) {
			if (data &(1 << i)){ 
			count++;
			GPIO_SetBits(GPIOB, TX);
			}
			else GPIO_ResetBits(GPIOB, TX); 
			delay(200); // bit time. Gia su la 10ms
		}
		if (count %2 == 0) GPIO_ResetBits(GPIOB, TX); //bit parity
		else GPIO_SetBits(GPIOB, TX);
		delay(200); // bit time cuoi cung
		
}



int main() {
	uint8_t data = 12; //170 - 10101010
	config();
	GPIO_SetBits(GPIOx, TX); //set trang thai ban dau cho TX 
	delay(1000);
	while (1) {
	
		start_Condition();
		
		transmit(data);
		
		stop_bit();
	
	}
	return 0;
}