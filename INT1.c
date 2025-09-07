#include<p18f4580.h>

#define LED PORTCbits.RC0

void EXT1(void);

void main()
{
TRISCbits.RC0=0;  // led as output
ADCON1=0x0f;   /// port b and a as digital 
RCONbits.IPEN=1; // inerupt priority enable
INTCON=0x80; // global interrupt enable
INTCON2bits.INTEDG1=1; // rising edge select for int1
INTCON3bits.INT1IE=1;
LED=0;

	while(1)
	{
		EXT1();
	}
}

#pragma code EXT1=0x08
#pragma interrupt EXT1

void EXT1(void)
{
	while(INTCON3bits.INT1IF == 1)
	{
		LED = ~LED;
		INTCON3bits.INT1IF=0;
	}
}