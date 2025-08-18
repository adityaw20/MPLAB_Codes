#include<p18f4580.h>
void delay(int a);
int main()
{
int i;
int arr[16]={0xC0,0xF9,0xA4,0xB0,0x99,0x92,0x82,0xF8,
             0x80,0x90,0x88,0x83,0xC6,0xA1,0x86,0x8E };
TRISC=0x00;
	while(1)
	{
	  for(i=0;i<16;i++)
	   {
	    PORTC=arr[i];
	    delay(100);
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