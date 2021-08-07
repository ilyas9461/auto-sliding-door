
#include <stdio.h>               // Including Standard Input / Outputlibrary
#include <stdlib.h>              // Including Standard library function
#include <xc.h>                  // Including XC8 compiler library

#ifndef   _XTAL_FREQ
    #define _XTAL_FREQ 4000000
#endif

#define TMR2PRESCALE 4

int PWM_Max_Duty();
PWM1_Init(long fre);
PWM1_Duty(unsigned int duty);
PWM1_Start();
PWM1_Stop();
