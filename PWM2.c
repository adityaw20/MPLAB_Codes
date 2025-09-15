#include<p18f4580.h>
#define led PORTCbits.RC2


void delay(int a);

void main()
{
TRISCbits.RC2=0;
CCP1CON=0x0c;  // 1 0 for 0.50 
T2CON=0x02;
PR2=1023;
//CCPR1L=5; //50%  duty cycle
T2CONbits.TMR2ON=1;

while(1)
{
	int i;
	for(i=0;i<255;i++)
	{
		CCPR1L=i;
		delay(50);
	}

	for(i=255;i>=0;i--)
	{
		CCPR1L=i;
		delay(50);
	}

}
}

void delay(int a)
{
int i,j;
for(i=0;i<a;i++)
{
for(j=0;j<a;j++)
{}
}
}