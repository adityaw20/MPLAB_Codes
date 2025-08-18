#include<p18f4580.h>

void delay(int a);
#define s1 PORTDbits.RD0
#define s2 PORTDbits.RD1

int main()
{
int i;
int temp;
int arr[10]={0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f};

TRISC=0x00;
TRISD=0x00;
while(1)
{
for(i=00;i<100;i++)
{
s1=0;s2=1;
temp=i/10;
PORTC=arr[temp];
delay(50);
s1=1;s2=0;
temp=i%10;
PORTC=arr[temp];
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
{
}
}

}