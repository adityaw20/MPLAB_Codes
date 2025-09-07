#include<p18f4580.h>

#define LED PORTCbits.RC0

void EXT2(void);

void main()
{
TRISCbits.RC0 = 0; // LED OP

ADCON1=0x0f ;// port a b as digital

INTCONbits.GIE = 1;
INTCON2bits.INTEDG2 =1;
RCONbits.IPEN=1; // interrupt priority enable
INTCON3bits.INT2IE=1;  //INT2 is enable

LED=0;

while(1)
{
EXT2();
}
}


#pragma code EXT2=0x08
#pragma interrupt EXT2
void EXT2(void)
{
while(INTCON3bits.INT2IE == 1)
{
LED =  ~LED;
INTCON3bits.INT2IE=0;  // interrupt reset 
}
}
