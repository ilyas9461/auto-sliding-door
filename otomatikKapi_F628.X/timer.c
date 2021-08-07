#include "timer.h"


void TMR0_init(){

    //Timer0 Registers Prescaler= 1, TMR0 Preset = 61,  Freq = 5128.21 Hz, Period = 0.000195 seconds
    //Timer0 Registers Prescaler= 256, 195uS*256=49920uS=~50mS yani saniye yaklaşık 20 defa kesme oluşur.
    OPTION_REGbits.T0CS=0;          // bit 5  TMR0 Clock Source Select bit...0 = Internal Clock (CLKO) 1 = Transition on T0CKI pin
    OPTION_REGbits.T0SE=0;           // bit 4 TMR0 Source Edge Select bit 0 = low/high 1 = high/low
    OPTION_REGbits.PSA=0 ;            // bit 3  Prescaler Assignment bit 0 = Prescaler is assigned to the TIMER0
    OPTION_REGbits.PS2=1;             //OPTION_REG.PS2 = 0;   // bits 2-0  PS2:PS0: Prescaler Rate Select bits
    OPTION_REGbits.PS1=1;
    OPTION_REGbits.PS0=1;               //111, Prescaler 256
   // TMR0 = 61;             // preset for timer register  50mS
    TMR0=216;               //10,2 mS

    // Interrupt Registers
     INTCON = 0;           // clear the interrpt control register
     INTCONbits.TMR0IE=1;         // INTCON.TMR0IE = 1;        // bit5 TMR0 Overflow Interrupt Enable bit...1 = Enables the TMR0 interrupt
     INTCONbits.TMR0IF=0;         //INTCON.TMR0IF = 0;        // bit2 clear timer 0 interrupt flag
     INTCONbits.GIE=1;               //INTCON.GIE = 1;           // bit7 global interrupt enable
}

// Interrupt Handler
void interrupt TMR0_int()
{
  // Timer0 Interrupt - Freq = 5128.21 Hz - Period = 0.000195
   
      if (INTCONbits.TMR0IF ==1) // timer 0 interrupt flag
      {
              t_y++;
              t_m++;
              t_k++;
              timer++;

            INTCONbits.TMR0IF = 0;         // clear the flag
            INTCONbits.TMR0IE= 1;         // reenable the interrupt
            //TMR0 = 61;           // reset the timer preset count
            TMR0 =216;                  //10.2 mS
      }

}
