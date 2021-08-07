/* 
 * File:   timer.h
 * Author: ilyas
 *
 * Created on 27 Ocak 2018 Cumartesi, 09:48
 */

#ifndef TIMER_H
#define	TIMER_H

#ifdef	__cplusplus
extern "C" {
#endif

    #include <stdio.h>               // Including Standard Input / Outputlibrary
    #include <stdlib.h>              // Including Standard library function
    #include <xc.h>                  // Including XC8 compiler library

   char t_y=0;                  //extern değişkenler tekrar tanımlanıyor extern tanımlandıkları yerden erişilebilmek için.
   int t_m=0;
   char t_k=0;
   unsigned int timer=0;

    void TMR0_init();
    void interrupt TMR0_int();

#ifdef	__cplusplus
}
#endif

#endif	/* TIMER_H */

