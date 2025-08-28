#include <p18f4580.h>

// LCD control pins
#define RS PORTCbits.RC0
#define E  PORTCbits.RC1

// Function declarations
void cmd(int b);
void data(char x);
void delay(int a);
void initLCD();
void string(const rom char *str);

void main()
{
    // Configure ADC pins as digital
    ADCON1 = 0x0F;

    // Configure LCD control pins as output
    TRISCbits.RC0 = 0; // RS
    TRISCbits.RC1 = 0; // E

    // Configure PORTB and PORTD as output
    TRISB = 0x00; // keypad port (used as output for scanning)
    TRISD = 0x00; // LCD data port

    // Initialize LCD
    initLCD();
    string("Enter no.");  // Show initial message
    cmd(0xC0);           // Move to second line

    while (1)
    {
        // -----------------------
        // Row 1 = 0, others = 1
        // -----------------------
        PORTB = 0xFE;
        if (PORTB == 0xEE) { while(PORTB == 0xEE); data('7'); }
        if (PORTB == 0xDE) { while(PORTB == 0xDE); data('8'); }
        if (PORTB == 0xBE) { while(PORTB == 0xBE); data('9'); }
        if (PORTB == 0x7E) { while(PORTB == 0x7E); data('/'); }

        // -----------------------
        // Row 2 = 0, others = 1
        // -----------------------
        PORTB = 0xFD;
        if (PORTB == 0xED) { while(PORTB == 0xED); data('4'); }
        if (PORTB == 0xDD) { while(PORTB == 0xDD); data('5'); }
        if (PORTB == 0xBD) { while(PORTB == 0xBD); data('6'); }
        if (PORTB == 0x7D) { while(PORTB == 0x7D); data('*'); }

        // -----------------------
        // Row 3 = 0, others = 1
        // -----------------------
        PORTB = 0xFB;
        if (PORTB == 0xEB) { while(PORTB == 0xEB); data('1'); }
        if (PORTB == 0xDB) { while(PORTB == 0xDB); data('2'); }
        if (PORTB == 0xBB) { while(PORTB == 0xBB); data('3'); }
        if (PORTB == 0x7B) { while(PORTB == 0x7B); data('-'); }

        // -----------------------
        // Row 4 = 0, others = 1
        // -----------------------
        PORTB = 0xF7;
        if (PORTB == 0xE7)  // Clear button
        {
            while(PORTB == 0xE7);
            data('C');
            delay(300);
            cmd(0x01);       // Clear LCD
            cmd(0x80);       // Go to first line
            string("Enter no.");
            cmd(0xC0);       // Second line
        }
        if (PORTB == 0xD7) { while(PORTB == 0xD7); data('0'); }
        if (PORTB == 0xB7) { while(PORTB == 0xB7); data('='); }
        if (PORTB == 0x77) { while(PORTB == 0x77); data('+'); }
    }
}

// -----------------------
// Initialize LCD
// -----------------------
void initLCD()
{
    cmd(0x01);  // Clear display
    cmd(0x38);  // 8-bit, 2-line, 5x7 font
    cmd(0x0E);  // Display on, cursor on
    cmd(0x06);  // Increment cursor
    cmd(0x80);  // First line
}

// -----------------------
// Send command to LCD
// -----------------------
void cmd(int cd)
{
    PORTD = cd;
    RS = 0;   // Command mode
    E = 1;
    delay(100);
    E = 0;
}

// -----------------------
// Send data (character) to LCD
// -----------------------
void data(char x)
{
    PORTD = x;
    RS = 1;   // Data mode
    E = 1;
    delay(100);
    E = 0;
}

// -----------------------
// Simple delay function
// -----------------------
void delay(int a)
{
    int i, j;
    for(i = 0; i < a; i++)
        for(j = 0; j < i; j++);
}

// -----------------------
// Display string on LCD
// -----------------------
void string(const rom char *str)
{
    while(*str)
        data(*str++);
}
