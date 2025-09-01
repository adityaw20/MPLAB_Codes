#include<p18f4580.h>

#define LED PORTCbits.RC0
#define dir_LED TRISCbits.RC0


void delay(void);

void main()
{
dir_LED =0;   // led is output

T2CON = 0x7b; // prescalr 8 , and timer 1 off


while(1)
{
LED=1;  //LED on
delay();
delay();
delay();
delay();



LED=0; //LED off
delay();
delay();

}
}

// Delay Function
void delay()
{
TMR2=0x00;
PR2=0x66;

PIR1bits.TMR2IF = 0;  //INterupt flag reset
T2CONbits.TMR2ON = 1;  //TIMER 0 on

while(PIR1bits.TMR2IF !=1);  //wait until the overflow
T2CONbits.TMR2ON = 0;  //TIMER 0 off
PIR1bits.TMR2IF = 0;  //INterupt flag reset
}