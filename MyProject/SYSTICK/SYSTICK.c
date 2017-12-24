/*
 * SYSTICK.c
 *
 *  Created on: Nov 14, 2017
 *      Author: tungduongbk
 */
#include "../include.h"
#include "SYSTICK.h"

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

}
