#include<p18f4580.h>
#define led PORTCbits.RC0

void delay(int a);

void main()
{
int i,a;
//char arr[10]="ADITYA ";
TRISCbits.RC6=0; //TX pin -->OUTPUT
TRISCbits.RC7=1; //RX pin -->INPUT
TRISCbits.RC0=0; // led 

TXSTA=0x24;
RCSTA=0x90;
SPBRG=0x19;  //boud rate 25

//TXREG='a';

	while(1)
	{
		while (PIR1bits.RCIF == 0);
        a=RCREG;
		switch(a)
		{
			case '1':
			led=1;
			break;
	
			case '0':
			led=0;
			break;
	        PIR1bits.RCIF=0;
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