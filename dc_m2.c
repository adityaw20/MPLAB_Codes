#include<p18f4580.h>

#define IN1 PORTCbits.RC0
#define IN2 PORTCbits.RC1
#define EN1 PORTCbits.RC2
#define SW  PORTDbits.RD0
int main()
{
TRISC=0x00;
TRISDbits.RD0=1;
while(1)
{
if(SW == 0)
{
 EN1=1;
 IN1=1;
 IN2=0;
}
else
{
EN1=0;
}
}
}