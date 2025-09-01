#include<p18f4580.h>

#define LED PORTCbits.RC0
#define dir_LED TRISCbits.RC0

#define LED1 PORTCbits.RC1
#define dir_LED1 TRISCbits.RC1

#define LED2 PORTCbits.RC2
#define dir_LED2 TRISCbits.RC2

void delay(void);

void main()
{
dir_LED =0;   // led is output
dir_LED1 =0;
dir_LED2 =0;
T0CON = 0x07; // prescalr 256 , and timer 0 off

while(1)
{
LED=1;  //LED on
delay();
delay();

LED1=1;
delay();
delay();

LED2=1;
delay();
delay();

LED=0;  //LED off
delay();
delay();

LED1=0;  //LED off
delay();
delay();

LED2=0;  //LED off
delay();


}
}

// Delay Function
void delay()
{
TMR0H = 0xfe;  // 100 ms delay
TMR0L = 0x79;

INTCONbits.TMR0IF = 0;  //INterupt flag reset
T0CONbits.TMR0ON = 1;  //TIMER 0 on

while(INTCONbits.TMR0IF !=1);  //wait until the overflow
T0CONbits.TMR0ON = 0;  //TIMER 0 off
INTCONbits.TMR0IF = 0;  //INterupt flag reset
}