#include<p18f4580.h>

#define led PORTCbits.RC0
void delay(int a);

int main()
{

TRISCbits.RC0=0;

while(1)
{
led=1;
delay(300);
led=0;
delay(300);
}

}

void delay(int a)
{
int i,j;
for(i=0;i<a;i++)
{
for(j=0;j<a;j++)
{
}
}
}
