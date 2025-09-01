#include<p18f4580.h>

#define LED PORTCbits.RC0
#define dir_LED TRISCbits.RC0


void delay(void);

void main()
{
dir_LED =0;   // led is output

T1CON = 0xf0; // prescalr 8 , and timer 1 off

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
TMR1H = 0x85;  // 100 ms delay //for 250 ms delay :0x85ED
TMR1L = 0xED;

PIR1bits.TMR1IF = 0;  //INterupt flag reset
T1CONbits.TMR1ON = 1;  //TIMER 0 on

while(PIR1bits.TMR1IF !=1);  //wait until the overflow
T1CONbits.TMR1ON = 0;  //TIMER 0 off
PIR1bits.TMR1IF = 0;  //INterupt flag reset
}