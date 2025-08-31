 
#include<p18f4580.h>
#define rs PORTCbits.RC0
#define rw PORTCbits.RC1
#define E PORTCbits.RC2

void cmd(char cm);
void data(char dt);
void delay(int a);
void string(const rom char* str);

int main()
{
int i;
int adc_value;
int arr[4];

TRISAbits.RA0=0x01;
TRISC=0x00;
TRISD=0x00;

ADCON0=0x03;   //adc nable and conversion is in process
ADCON1=0x0e;   //AN0 select
ADCON2=0x88;   //result format,clock time , freq selected

cmd(0x0f);  //corsor,dislpay on
cmd(0x38);  //matrix 5*7
cmd(0x01);  //clear screen 
cmd(0x80);  // dataa show at first line
cmd(0x06);  //increment cursor




while(1)
{
	//string("ADC ");
	string("Value is:");
	
	ADCON0bits.GO=1;   //conversion in progress
	while(ADCON0bits.GO==1) //wait until conver in process
	{
		adc_value=ADRESH;   // store higher byte
		adc_value=adc_value<<8;  //left shift by 8
		adc_value=adc_value+ADRESL;  // store lower byte
	}
	
	for(i=0;i<4;i++)
	{
		arr[i] = adc_value %10+ '0' ;  //take last bit  & convert in asci 
		adc_value = adc_value / 10; // remove last bit and store the all bits
	}
    
    for(i=3;i>=0;i--)
    {
         data(arr[i]);
    }

}
}

void cmd(char cm)
{
    PORTD=cm;
	rs=0;
	rw=0;
	E=1;
	delay(100);
	E=0;
}

void data(char dt)
{
    PORTD=dt;
	rs=1;
	rw=0;
	E=1;
	delay(100);
	E=0;
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

void string(const rom char* str)
{
while(*str != '\0')
{
data(*str);
str++;
}
}