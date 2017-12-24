/*
 * UART.c
 *
 *  Created on: Nov 11, 2017
 *      Author: tungduongbk
 */
#include "../include.h"
#include "UART.h"
static char Buff[100];
//static char sep[] = "@:$";


static void Reset_Buffer(char *pBuff)
{
    while(*pBuff!=0x24)
    {
        *pBuff=0;
        pBuff++;
    }
}
void UARTGetBuffer(char *pBuff)
{
    static uint8_t i=0;
    char c;
    if(i==0)
        Reset_Buffer(pBuff);
    while(UARTCharsAvail(UART0_BASE))
    {
        c=UARTCharGet(UART0_BASE);
        *(pBuff+i)=c;
        i++;
    }
    if(c==0x24) // kiem tra ki tu $
    {
        i=0;
        check_Uart = 1;
    }
}
void SEP_UART(void)
{
    int Sign_X = 1;
    int Sign_Y = 1;
    int i = 0;
    int j = 0;
    res_X = 0;
    res_Y = 0;
  if (Buff[0] == 0x40){
        if (Buff[1] == 0x2D) {
            Sign_X = -1;
            i = 1;
        }
        while (Buff[++i] != 0x3A) { //iterate until the array end
            res_X = res_X*10 + (Buff[i] - '0'); //generating the integer according to read parsed numbers.
        }
        j=i;
        if (Buff[j+1] == 0x2D) {
            Sign_Y = -1;
            j++;
        }
        while (Buff[++j] != 0x24) { //iterate until the array end
            res_Y = res_Y*10 + (Buff[j] - '0'); //generating the integer according to read parsed numbers.
        }
        res_X = res_X*Sign_X;
        res_Y = res_Y*Sign_Y;
  }
}
static void UART_ISR(void)
{
    check_Uart = 0;
    UARTIntClear(UART0_BASE,UARTIntStatus(UART0_BASE,true));
    UARTGetBuffer(&Buff[0]);
}
/*
void UARTPutBuffer(void)
{
    uint16_t i=0;
    while(Buff[i]!=0x24)
    {
        UARTCharPut(UART0_BASE,Buff[i]);
        i++;
    }
}
*/
void Config_UART(void)
{
    SysCtlPeripheralEnable(SYSCTL_PERIPH_UART0);
    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOA);
    GPIOPinConfigure(GPIO_PA0_U0RX);
    GPIOPinConfigure(GPIO_PA1_U0TX);
    GPIOPinTypeUART(GPIO_PORTA_BASE, GPIO_PIN_0 | GPIO_PIN_1);
    UARTClockSourceSet(UART0_BASE, UART_CLOCK_SYSTEM);

    UARTConfigSetExpClk(UART0_BASE, SysCtlClockGet(), 115200,UART_CONFIG_WLEN_8 | UART_CONFIG_STOP_ONE |UART_CONFIG_PAR_NONE);
    UARTIntRegister(UART0_BASE,&UART_ISR);
    IntEnable(INT_UART0);
    UARTIntEnable(UART0_BASE, UART_INT_RX | UART_INT_RT);
}
