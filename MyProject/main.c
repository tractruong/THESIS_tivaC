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
    //res_X = 0;
    //res_Y = 0;
   // Inverse(0,0,0);
    IntMasterEnable();
    while(1)
    {
        if(check_Uart == 1)
        {

              SEP_UART();
              if(res_X >= -10 && res_X <= 10 && res_Y >= -10 && res_Y <= 10)
              {
                            j=0;
                           Inverse(res_X,res_Y,0);
                           PWMPulseWidthSet(PWM0_BASE,PWM_OUT_1,1272-GetAlpha(0)*469/60); //servo2--PB7
                           PWMPulseWidthSet(PWM0_BASE,PWM_OUT_0,1272+GetAlpha(1)*469/60); //servo1--PB6
                           PWMPulseWidthSet(PWM0_BASE,PWM_OUT_2,1290-GetAlpha(2)*469/60); //servo3--PB4
                           PWMPulseWidthSet(PWM0_BASE,PWM_OUT_3,1272+GetAlpha(3)*469/60); //servo4--PB5
                           PWMPulseWidthSet(PWM0_BASE,PWM_OUT_4,1272-GetAlpha(4)*469/60); //servo5--PE4
                           PWMPulseWidthSet(PWM0_BASE,PWM_OUT_5,1272+GetAlpha(5)*469/60); //servo6--PE5
                           sprintf(s,"@%d:%d:%d:%d:%d:%d$",(int)GetAlpha(0),(int)GetAlpha(1),(int)GetAlpha(2),(int)GetAlpha(3),(int)GetAlpha(4),(int)GetAlpha(5));
                           while(s[j]!= 0x00)
                           {
                               UARTCharPut(UART0_BASE,s[j]);
                               j++;
                           }

                 }
              check_Uart = 0;
            }

    }
}
