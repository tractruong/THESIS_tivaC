/*
 * Main.c
 *
 *  Created on: Nov 11, 2017
 *      Author: tungduongbk
 */
#include "include.h"

void delayMS(int ms) {
    SysCtlDelay( (SysCtlClockGet()/(3*1000))*ms ) ;
}

void main(void)
{   int j=0;
    char s[50] = {0};
    SysCtlClockSet(SYSCTL_SYSDIV_4 | SYSCTL_USE_PLL | SYSCTL_OSC_MAIN | SYSCTL_XTAL_16MHZ); //50Mhz
    Config_PWM();
    Config_UART();
    Config_Systick(SAMPLING_RATE);
    //res_X = 0;
    //res_Y = 0;
   // Inverse(0,0,0);
    IntMasterEnable();
    Init_Fuzzy();
    while(1)
    {

    }
}
