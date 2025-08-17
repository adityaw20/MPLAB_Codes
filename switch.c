#include<p18f4580.h>

#define led PORTCbits.RC0
#define sw PORTCbits.RC1
#define ON 1
#define OFF 0

void delay(int a);

int main()
{
TRISCbits.RC0=0;
TRISCbits.RC1=1;

while(1)
{
if(sw == 0)
{
led=ON;
}
else
{
led = OFF;
}

}
}

void delay(int a)
{
int i,j; // do not write int in for loop

for(i=0;i<a;i++)
{
for(j=0;j<a;j++)
{
}
}
}