/*
 * PWM.c
 *
 *  Created on: Nov 11, 2017
 *      Author: tungduongbk
 */

#include "../include.h"
#include "PWM.h"

#define PWM_FREQUENCY 55 //Dinh nghia gia tri tan so pwm la 55

    volatile uint32_t ui32Load;
    volatile uint32_t ui32PWMClock;
   // volatile uint32_t ui8Adjust;

    void Config_PWM(void)
    {
    // Cau hinh tan so PWM
     SysCtlPWMClockSet(SYSCTL_PWMDIV_64);
    // Kich hoat chan PW0, port B va E
     SysCtlPeripheralEnable(SYSCTL_PERIPH_PWM0);
     SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOB);
     SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOE);
     SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOF);
    // Cau hinh chan PB4, PB5, PB6, PB7 la cac chan PWM
     GPIOPinTypePWM(GPIO_PORTB_BASE, GPIO_PIN_4|GPIO_PIN_5|GPIO_PIN_6|GPIO_PIN_7);
     GPIOPinConfigure(GPIO_PB4_M0PWM2);
     GPIOPinConfigure(GPIO_PB5_M0PWM3);
     GPIOPinConfigure(GPIO_PB6_M0PWM0);
     GPIOPinConfigure(GPIO_PB7_M0PWM1);
    // Cau hinh chan PE4, PE5 la cac chan PWM
     GPIOPinTypePWM(GPIO_PORTE_BASE, GPIO_PIN_4|GPIO_PIN_5);
     GPIOPinConfigure(GPIO_PE4_M0PWM4);
     GPIOPinConfigure(GPIO_PE5_M0PWM5);
    //Tinh clock PWM
    ui32PWMClock = SysCtlClockGet() /64;
    ui32Load = (ui32PWMClock / PWM_FREQUENCY) - 1;
    //Cau hinh PWM, Dem xuong, dong bo all
    PWMGenConfigure(PWM0_BASE, PWM_GEN_0, PWM_GEN_MODE_DOWN | PWM_GEN_MODE_NO_SYNC);
    PWMGenConfigure(PWM0_BASE, PWM_GEN_1, PWM_GEN_MODE_DOWN | PWM_GEN_MODE_NO_SYNC);
    PWMGenConfigure(PWM0_BASE, PWM_GEN_2, PWM_GEN_MODE_DOWN | PWM_GEN_MODE_NO_SYNC);
     //Set the Period
    PWMGenPeriodSet(PWM0_BASE, PWM_GEN_0, ui32Load);
    PWMGenPeriodSet(PWM0_BASE, PWM_GEN_1, ui32Load);
    PWMGenPeriodSet(PWM0_BASE, PWM_GEN_2, ui32Load);
    // set width pwm -- 90 degree
    PWMPulseWidthSet(PWM0_BASE,PWM_OUT_0,1272);
    PWMPulseWidthSet(PWM0_BASE,PWM_OUT_1,1272);
    PWMPulseWidthSet(PWM0_BASE,PWM_OUT_2,1290);
    PWMPulseWidthSet(PWM0_BASE,PWM_OUT_3,1272);
    PWMPulseWidthSet(PWM0_BASE,PWM_OUT_4,1272);
    PWMPulseWidthSet(PWM0_BASE,PWM_OUT_5,1272);

    PWMOutputState(PWM0_BASE,PWM_OUT_0_BIT, true);
    PWMOutputState(PWM0_BASE,PWM_OUT_1_BIT, true);
    PWMOutputState(PWM0_BASE,PWM_OUT_2_BIT, true);
    PWMOutputState(PWM0_BASE,PWM_OUT_3_BIT, true);
    PWMOutputState(PWM0_BASE,PWM_OUT_4_BIT, true);
    PWMOutputState(PWM0_BASE,PWM_OUT_5_BIT, true);
    // Enable the PWM generator
    PWMGenEnable(PWM0_BASE, PWM_GEN_0);
    PWMGenEnable(PWM0_BASE, PWM_GEN_1);
    PWMGenEnable(PWM0_BASE, PWM_GEN_2);
}
