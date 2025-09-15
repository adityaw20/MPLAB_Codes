#include<p18f4580.h>
#define led PORTCbits.RC2


void delay(int a);

void main()
{
TRISCbits.RC2=0;
CCP1CON=0x2c;  // 1 0 for 0.50 
T2CON=0x02;
PR2=11;
CCPR1L=5; //50%  duty cycle
T2CONbits.TMR2ON=1;

while(1)
{

}
}

void delay(int a)
{
int i,j;

}