/*
 * SYSTICK.c
 *
 *  Created on: Nov 14, 2017
 *      Author: tungduongbk
 */
#include "../include.h"
//#include "SYSTICK.h"

#define SAMPLING_RATE 10
int j=0;
    char s[50] = {0};

static double posX = 0;
static double posY = 0;
static double errX = 0;
static double errY = 0;
static double pre_errX = 0;
static double pre_errY = 0;
static double velX = 0;
static double velY = 0;
static double angleX = 0;
static double angleY = 0;
static double setpointX = 200;
static double setpointY = 200;
static double scale_errX = 0.005;
static double scale_errY = 0.005;
static double scale_velX = 0.0015;
static double scale_velY = 0.0015;
static double scale_outX = 10;
static double scale_outY = 10;



static void Systick_ISR(void);

void Config_Systick(uint32_t num_tick)
{
    SysTickPeriodSet(SysCtlClockGet()/1000*num_tick);
    SysTickIntRegister(&Systick_ISR);
    SysTickIntEnable();
    SysTickEnable();
}

static void Systick_ISR(void)
{
    if(check_Uart == 1)
    {
            SEP_UART();

            j=0;
            posX = res_X;
            posY = res_Y;

            errX = setpointX - posX;
            errY = setpointY - posY;

            velX = (errX - pre_errX) * 1000 / SAMPLING_RATE;
            velY = (errY - pre_errY) * 1000 / SAMPLING_RATE;

            pre_errX = errX;
            pre_errY = errY;

            angleX = Fuzzy_OutPut((float)errX, (float)velX, (float)scale_errX, (float)scale_velX, (float)scale_outX, -10, 10);
            angleY = (-Fuzzy_OutPut((float)errY, (float)velY, (float)scale_errY, (float)scale_velY, (float)scale_outY, -10, 10));

            Inverse(angleX,angleY,0);
            PWMPulseWidthSet(PWM0_BASE,PWM_OUT_1,1272-GetAlpha(0)*469/60); //servo2--PB7
            PWMPulseWidthSet(PWM0_BASE,PWM_OUT_0,1272+GetAlpha(1)*469/60); //servo1--PB6
            PWMPulseWidthSet(PWM0_BASE,PWM_OUT_2,1290-GetAlpha(2)*469/60); //servo3--PB4
            PWMPulseWidthSet(PWM0_BASE,PWM_OUT_3,1272+GetAlpha(3)*469/60); //servo4--PB5
            PWMPulseWidthSet(PWM0_BASE,PWM_OUT_4,1272-GetAlpha(4)*469/60); //servo5--PE4
            PWMPulseWidthSet(PWM0_BASE,PWM_OUT_5,1272+GetAlpha(5)*469/60); //servo6--PE5
            sprintf(s,"@%d:%d:%d:%d:%d:%d:%d:%d$",(int)angleX,(int)angleY,(int)GetAlpha(0),(int)GetAlpha(1),(int)GetAlpha(2),(int)GetAlpha(3),(int)GetAlpha(4),(int)GetAlpha(5));
            while(s[j]!= 0x00)
            {
               UARTCharPut(UART0_BASE,s[j]);
               j++;
            }
          check_Uart = 0;
        }
}
