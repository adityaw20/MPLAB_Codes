#include<p18f4580.h>

#define IN1 PORTCbits.RC0
#define IN2 PORTCbits.RC1
#define EN1 PORTCbits.RC2
#define sw  PORTDbits.RD0
#define sw1 PORTDbits.RD1

#define EN2 PORTCbits.RC3
#define IN3 PORTCbits.RC4
#define IN4 PORTCbits.RC5

int main()
{

TRISC=0x00;
TRISDbits.RD0=1;
TRISDbits.RD1=1;
while(1)
{
if(sw == 1)
{
EN1=1;
IN1=1;
IN2=0;
}
else
{
EN1=0;
}

//switch 2
if(sw1 == 1)
{
EN2=1;
IN3=1;
IN4=0;
}
else
{
EN2=0;
}
}
}