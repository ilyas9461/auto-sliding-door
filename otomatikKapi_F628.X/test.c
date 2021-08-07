
#include "test.h"
#include "pwm.h"
#include "timer.h"

void TMR0_test(){
      if(t_y>20){
            t_y=0;
            led_k^=1;
        }
}
void pwm_test(){

     for(int x=0;x<1024;x+=10){
            PWM1_Duty(x);
            bekle(20);
        }
       // PWM1_Duty(0);bekle(1000);
       for(int x=1023;x>0;x-=10){
           PWM1_Duty(x);
            bekle(20);
       }

 }
 void btn_sa_test(){

        if(btn_start==0){
            bekle(250);
            m_dur();bekle(500);
            led_k=1; led_m=0;led_y=0;
            m_ileri();
            bekle(500);
        }
//        if(btn_acilStop==0){
//                bekle(250);
//                led_k=0; led_m=1;led_y=0;
//               m_dur();
//               bekle(500);
//        }
        if(SA1==0){
            bekle(250);
            m_dur();bekle(500);
            m_geri();led_k=0; led_m=0;led_y=1;
            bekle(500);
        }
        if(SA2==0){
            bekle(250);
            m_dur();
            bekle(500);
        }
        if(irSens1==0)      //MZ80 ir sensmör NPN çıkış 5v besleme, NPN çıkış, normal de cisim yokken çış ucu 1,
                                       //   cisim geldiğinde 0 olur, yani sıfırı(GNd) anahtarlar, tersi PNP çıkış olsaydı 1(VCC) anhatarlardı.
        {
              bekle(100);
              m_dur(); led_k=1; led_m=0;led_y=0;
             bekle(500);
        }
        bekle(100);

 }
void  test() {
      led=0;

            //led_k=1; led_m=0;led_y=0;bekle(500);
            led_k=1;
            m_ileri();
            bekle(5000);

            // led_k=0; led_m=1;led_y=0;bekle(500);
            led_m=1;
            m_dur();
             bekle(3500);

            led=1;

            //led_k=0; led_m=0;led_y=1;bekle(500);
            led_y=1;
             m_geri();
             bekle(5000);

              led_k=0;led_y=0;led_m=0;bekle(500);
               m_dur();
               bekle(3500);
 }
 void rgbLed_test(){
     led_k=1;
    bekle(1000);
    led_y=1;
    bekle(1000);
    led_m=1;
    bekle(1000);
    led_k=0;led_y=0;led_m=0;
    bekle(1000);
 }



