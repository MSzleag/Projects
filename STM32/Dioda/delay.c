#include "stm32f4xx_hal.h"
#include "delay.h"

static volatile int tick;

void SysTick_Handler(void)
{
	tick++;        
}

void delay(int time){
	int i = tick + time;
	
	while (i >= tick){}
}	
