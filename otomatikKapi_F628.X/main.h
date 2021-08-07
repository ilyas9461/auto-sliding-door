/* 
 * File:   main.h
 * Author: ilyas
 *
 * Created on 27 Ocak 2018 Cumartesi, 09:39
 */

#ifndef MAIN_H
#define	MAIN_H

#ifdef	__cplusplus
extern "C" {
#endif
    
     #ifndef   _XTAL_FREQ
        #define _XTAL_FREQ 4000000
    #endif

    //#include <xc.h>

    #define btn_start  PORTBbits.RB0
    #define btn_acilStop  PORTBbits.RB1
    //#define btn_start  PORTBbits.RB1
    #define SA1  PORTBbits.RB2
    #define led_m PORTBbits.RB3     //PWM için
    #define irSens1  PORTBbits.RB4
    #define irSens2  PORTBbits.RB5
    #define led_y  PORTBbits.RB6

    #define led_k  PORTAbits.RA0
    #define SA2  PORTAbits.RA1
    #define m1  PORTAbits.RA2
    #define m2  PORTAbits.RA3
    #define led  PORTAbits.RA4
    #define led_toggle() led^= 1

    #define m_ileri() m1=1;m2=0
    #define m_geri() m1=0;m2=1
    #define m_dur() m1=0;m2=0
    #define bekle(m) __delay_ms(m);
    #define sol 0
    #define sag 1



#ifdef	__cplusplus
}
#endif

#endif	/* MAIN_H */

