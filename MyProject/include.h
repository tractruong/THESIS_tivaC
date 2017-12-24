/*
 * include.h
 *
 *  Created on: Mar 12, 2016
 *      Author: Satu
 */

#ifndef INCLUDE_H_
#define INCLUDE_H_

//thu vien ho tro ve bool, int, string va toan hoc math
#include <stdbool.h>
#include <stdint.h>
#include <string.h>
#include <math.h>
#include <stdio.h>
//#include <conio.h>
#include <stdlib.h>
//thu vien driver API

#include "driverlib/gpio.h"
#include "driverlib/can.h"
#include "driverlib/eeprom.h"
#include "driverlib/i2c.h"
#include "driverlib/lcd.h"
//#include "driverlib/lcd16x2.h"
#include "driverlib/mpu.h"
#include "driverlib/pwm.h"
#include "driverlib/sysctl.h"
#include "driverlib/pin_map.h"
#include "driverlib/timer.h"
#include "driverlib/adc.h"
#include "driverlib/interrupt.h"
#include "driverlib/qei.h"
#include "driverlib/fpu.h"
#include "driverlib/uart.h"
#include "driverlib/rom.h"
#include "driverlib/systick.h"
//thu vien ho tro phan cung
#include "inc/hw_ints.h"
#include "inc/hw_gpio.h"
#include "inc/hw_memmap.h"
#include "inc/hw_types.h"

//thu vien khai bao them (dua vao cac module minh tao ra)
#include "INVERSE/INVERSE.h"
#include "PWM/PWM.h"
//#include "GPIO/GPIO.h"
#include "UART/UART.h"
#include "UART/uartstdio.h"
#include "UART/ustdlib.h"
#include "SYSTICK/SYSTICK.h"
#include "eFLL/fuzzy_ball_and_plate.h"

#endif /* INCLUDE_H_ */
