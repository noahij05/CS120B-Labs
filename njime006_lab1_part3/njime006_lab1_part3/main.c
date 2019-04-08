/*
 * njime006_lab1_part3.c
 *
 * Created: 4/7/2019 4:36:33 PM
 * Author : Noah Jimenez
 */ 

#include <avr/io.h>


int main(void)
{
    DDRA = 0x00; PORTA = 0xFF; // Configure port A's 8 pins as inputs
    DDRC = 0xFF; PORTC = 0x00; // Configure port C's 8 pins as outputs, initialize to 0s
    unsigned char cntAvail = 0x00; // Temporary variable to hold the value of C
    unsigned char tmpA = 0x00; // Temporary variable to hold the value of A
    while (1)
    {
        // 1) Read input
        tmpA = PINA & 0x0F;
        // 2) Perform computation
        // if PA3PA0 is 1, set PC3PC0 = 0000, else = 1111
        if (tmpA == 0x0F) { // True if PA0 is 1
            cntAvail = (cntAvail & 0xF0) | 0x80; // Sets tmpB to bbbb0000
            // (clear rightmost 4 bits, then set to 0000)
        }
        else
        {
            if (tmpA == 0x07 || tmpA == 0x0B || tmpA == 0x0D || tmpA == 0x0E)
            {
                cntAvail = (cntAvail & 0xF0) | 0x01;
            }
            else
            {
                if (tmpA == 0x03 || tmpA == 0x05 || tmpA == 0x06 || tmpA == 0x09 || tmpA == 0x0A)
                {
                    cntAvail = (cntAvail & 0xF0) | 0x02;
                }
                else
                {
                    if (tmpA == 0x01 || tmpA == 0x02 || tmpA == 0x04 || tmpA == 0x08)
                    {
                        cntAvail = (cntAvail & 0xF0) | 0x03;
                    }
                    else
                    {
                        cntAvail = (cntAvail & 0xF0) | 0x04;
                    }
                }
            }
        }
        // 3) Write output
        PORTC = cntAvail;
    }
}

