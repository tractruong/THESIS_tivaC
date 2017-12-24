/*
 * GPIO.c
 *
 *  Created on: Mar 12, 2016
 *      Author: Satu
 */

#include "../include.h"
#include "GPIO.h"

static void SWITCH_ISR(void);
//static uint8_t num_red=5, num_blue=5;

void Config_SWITCH(void) //PF4, PF0 INPUT
{
	SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOF);
	//unclock PF0
	HWREG(GPIO_PORTF_BASE + GPIO_O_LOCK) = GPIO_LOCK_KEY;
	HWREG(GPIO_PORTF_BASE + GPIO_O_CR) = 0x01;
	HWREG(GPIO_PORTF_BASE + GPIO_O_AFSEL) &= ~0x01;

	GPIOPinTypeGPIOInput(SWITCH_PORT, SWITCH_LEFT|SWITCH_RIGHT);
	GPIOPadConfigSet(SWITCH_PORT, SWITCH_LEFT|SWITCH_RIGHT, GPIO_STRENGTH_8MA, GPIO_PIN_TYPE_STD_WPU);
	GPIOIntRegister(SWITCH_PORT,&SWITCH_ISR);
	GPIOIntEnable(SWITCH_PORT,GPIO_INT_PIN_4);
	GPIOIntEnable(SWITCH_PORT,GPIO_INT_PIN_0);
	IntEnable(INT_GPIOF);
}

static void SWITCH_ISR(void)
{
	/*if(GPIOIntStatus(GPIO_PORTF_BASE, true)==SWITCH_LEFT)
	{
		//LED RED
		num_red++;
		num_red%=10;
	}
	if(GPIOIntStatus(GPIO_PORTF_BASE, true)==SWITCH_RIGHT)
	{
		//LED BLUE
		num_blue++;
		num_blue%=10;
	}
	Update_PWM(&num_red,&num_blue);
	//UARTCharPut(UART0_BASE,'E');*/
	GPIOIntClear(GPIO_PORTF_BASE,GPIOIntStatus(GPIO_PORTF_BASE, true));
	UARTPutBuffer();
}
