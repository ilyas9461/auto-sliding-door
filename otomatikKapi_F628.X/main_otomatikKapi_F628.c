// DEFINES
#define _XTAL_FREQ 4000000          // Telling the compiler, that we are using 4MHz

#include <stdio.h>               // Including Standard Input / Outputlibrary
#include <stdlib.h>              // Including Standard library function
#include <xc.h>                  // Including XC8 compiler library

// CONFIG
//#pragma config FOSC = XT
#pragma config FOSC = INTOSCIO  // Oscillator Selection bits (INTOSC oscillator: I/O function on RA6/OSC2/CLKOUT pin, I/O function on RA7/OSC1/CLKIN)
#pragma config WDTE = OFF        // Watchdog Timer Enable bit (WDT disabled)
#pragma config PWRTE = ON        // Power-up Timer Enable bit (PWRT enabled)
#pragma config MCLRE =ON // OFF   // MCLR deevresinin ON olması ile PIC reset olmaktan kurtuldu MCLR-->> 10K bağlandı
                                  //Entegrenin altına 100nF konuldu seramik
#pragma config BOREN = OFF //ON   //OFF       // Brown-out Reset Enable bit (BOD Reset enabled)
#pragma config LVP = OFF             // Low-Voltage Programming Enable bit (RB4/PGM pin has PGM function, low-voltage programming enabled)
#pragma config CPD = ON             // Data Code Protection bit (Data memory code protection on)
#pragma config CP = ON                // Code Protection bits (Program memory code protection on)

#include "main.h"
#include "pwm.h"
#include "test.h"
#include "timer.h"

#define KAPALI 0
#define ACIK 1
#define ACILIYOR 2
#define KAPANIYOR 3
#define ACILStop 4


#define kapiAc() m_geri()
#define kapiKapat() m_ileri()

extern char  t_y;          //Global değişken oldu her fonksiyondan  erişilebilir durumda,
                                      //o fonksiyonda extern olmadan tekar tanımlanmalı..
extern int t_m;
extern char t_k;
extern unsigned int timer;;// 16bit sayi
int duty=0;
char kapi_durum=KAPALI;     // Başlangıçta kapı kapalı....
//char ir_ee_durum=0;

void main()  {
    CMCON=7;                //komparator module off :Turn comparators off and  enable pins for I/O
                             //functions                
    TRISA=0b00000010; PORTA=0;
    TRISB=0b00110111; PORTB=0;

    TMR0_init();

    PWM1_Init(1000);
    PWM1_Duty(0);
    PWM1_Start();
    
    PWM1_Duty(0);
    led_k=0;led_y=0;
    m_dur();
    
    led=1;      //led yanık 
    bekle(250);
    led=0;
    bekle(250);
    //ir_ee_durum=eeprom_read(0x00);
    if(SA1==0)         //kapı kapalı SA, kapı kapandığında dokunur
    {
        //led_toggle();
        bekle(50);
        kapi_durum=KAPALI;
    }else if(SA2==0)         //Kapı açıldı SA, kapı açıldığında dokunur
    {
        //led_toggle();
        bekle(50);
        kapi_durum=ACIK;
    }
    
   if(irSens1==0){
        led_toggle();
        bekle(10);
        kapiAc();
        kapi_durum=ACILIYOR;
        bekle(100)
    }//else m_dur();
    
//    if(ir_ee_durum==ACILIYOR){
//        
//        kapiAc();
//        kapi_durum=ACILIYOR;
//        bekle(1000);
//        
//    }

    while(1)    {
        // Başlangıçta kapı kapalı....
        
        if(btn_start==0 && irSens1!=0)  //Normal çalışma
        {
            bekle(500);
            if(kapi_durum==KAPALI){
                 m_dur();  bekle(100);
                 kapiAc();                  // m_geri();
                 bekle(1000);            // Kapının sınır anahtarından kurtulması için beekleme süresi...
                 kapi_durum=ACILIYOR;      //Kapi Açiliyor
                 goto sensor_oku;
            }
            if(kapi_durum==ACILIYOR){  
                 m_dur(); bekle(100);
                 kapiKapat();       //m_ileri();
                 bekle(1000);            // Kapının sınır anahtarından kurtulması için beekleme süresi...
                 kapi_durum=KAPANIYOR;
                 goto sensor_oku;
            }

             if(kapi_durum==ACIK){
                 m_dur(); bekle(100);
                 kapiKapat();       //m_ileri();
                 bekle(1000);            // Kapının sınır anahtarından kurtulması için beekleme süresi...
                 kapi_durum=KAPANIYOR;
                 goto sensor_oku;
             } 
            if(kapi_durum==KAPANIYOR ){
                 m_dur();  bekle(100);
                 kapiAc();                  // m_geri();
                 bekle(1000);            // Kapının sınır anahtarından kurtulması için beekleme süresi...
                 kapi_durum=ACILIYOR;      //Kapi Açiliyor...
                 goto sensor_oku;
            }
        }
        if(btn_start==0 && irSens1==0)  //Test çalışma
        {
            bekle(300);
            if(kapi_durum==KAPALI){
                 m_dur();  bekle(100);
                 kapiAc();                  // m_geri();
                 bekle(1000);            // Kapının sınır anahtarından kurtulması için beekleme süresi...
                 kapi_durum=ACILIYOR;      //Kapi Açiliyor
                 goto sensor_oku;
             }
   
             if(kapi_durum==ACIK){
                 m_dur(); bekle(100);
                 kapiKapat();       //m_ileri();
                 bekle(1000);            // Kapının sınır anahtarından kurtulması için beekleme süresi...
                 kapi_durum=KAPANIYOR;
                 goto sensor_oku;
             } 
 
        }// if btn_start
        sensor_oku:

//        if(irSens1==0) {   //Sensor bağlanacaksa
//             //eeprom_write(0x00,ACILIYOR);
//             if(kapi_durum==KAPANIYOR){             //Kapıyı sıkışmaya karşı aç
//               // eeprom_write(0x00,ACILIYOR);
//               
//                //bekle(1000);
//                m_dur();
//                bekle(250);
//                kapiAc();
//                kapi_durum=ACILIYOR;
//             }
//         }

         if(SA1==0)         //kapı kapalı SA, kapı kapandığında dokunur
         {
             //Kapının Sınır anahtarından kurtulma süresini ortadan kaldırdı...
             if(kapi_durum==KAPANIYOR){
               m_dur(); 
               bekle(1000);
               kapi_durum=KAPALI;
               //eeprom_write(0x00,KAPALI);
             } 
             led_toggle(); 
             bekle(50);
         }
         
         if(SA2==0)         //Kapı açıldı SA, kapı açıldığında dokunur
         {
              //Kapının Sınır anahtarından kurtulma süresini ortadan kaldırdı...
              if(kapi_durum==ACILIYOR){
                m_dur(); 
                bekle(1000);
                kapi_durum=ACIK;
               // eeprom_write(0x00,ACIK);
             }
             led_toggle();
             bekle(50);
             timer=0;   
        }
        
//        if(timer>1000)          //10saniye =~10000mS/10.2mS=1000
//        {
//            timer=0;
//            if((kapi_durum==ACIK)&&(irSens1==1)){
//                 kapiKapat();       //m_ileri();
//                 bekle(1000);            // Kapının sınır anahtarından kurtulması için beekleme süresi...
//                 kapi_durum=KAPANIYOR;
//            }
//        }
        
        switch(kapi_durum){
             case KAPALI:                                    //Kapı kapalı
                    duty=t_m*3;
                    if(t_m>345)t_m=0;
                    if(duty>1023) duty=1023;
                    PWM1_Duty(duty);
                    led_k=0;
                    led_y=0;
                 break;
             case ACIK:                                    ////Kapı açık
                    PWM1_Duty(0);
                    led_k=0;
                    led_y=0;
                 break;
             case ACILIYOR:                                    // Kapı açiliyor
                 PWM1_Duty(0);
                 led_k=0;
                 if(t_y>10){
                     led_y^=1;                  //toogle
                     t_y=0;
                 }
                 break;
            case KAPANIYOR:                                     // Kapı kapanıyor.
                    PWM1_Duty(0);
                    led_y=0;
                    if(t_k>10) {
                          led_k^=1;
                           t_k=0;
                    }
                  
                 break;
              case ACILStop:
              break;
         }

     
    }// while(1)
}//main

