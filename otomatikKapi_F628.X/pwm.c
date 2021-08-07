#include "pwm.h"

long freq;

int PWM_Max_Duty()
{
  return ((unsigned int) (_XTAL_FREQ/(freq*TMR2PRESCALE));
}
PWM1_Init(long fre)
{
  PR2=(unsigned int) (_XTAL_FREQ/(fre*4*TMR2PRESCALE)) - 1;
  freq = fre;
}
PWM1_Duty(unsigned int duty)
{
  if(duty<1024)
  {
    duty = (unsigned int)(((float)duty/1023)*PWM_Max_Duty());
    CCP1X = duty && 0b10;
    CCP1Y = duty && 0b01;
    CCPR1L = duty>>2;
  }
}
PWM1_Start()
{
  CCP1M3 = 1;
  CCP1M2 = 1;
  #if TMR2PRESCALAR == 1
    T2CKPS0 = 0;
    T2CKPS1 = 0;
  #elif TMR2PRESCALAR == 4
    T2CKPS0 = 1;
    T2CKPS1 = 0;
  #elif TMR2PRESCALAR == 16
    T2CKPS0 = 1;
    T2CKPS1 = 1;
  #endif
  TMR2ON = 1;
}

PWM1_Stop()
{
  CCP1M3 = 0;
  CCP1M2 = 0;
}

