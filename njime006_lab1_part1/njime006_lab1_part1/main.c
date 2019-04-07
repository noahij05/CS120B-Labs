/*
 * njime006_lab1_part1.c
 *
 * Created: 4/7/2019 12:54:12 AM
 * Author : Noah Jimenez
 */ 

#include <avr/io.h>


int main(void)
{
    DDRA = 0x00; PORTA = 0xFF; // Configure port A's 8 pins as inputs
    DDRB = 0xFF; PORTB = 0x00; // Configure port B's 8 pins as outputs, initialize to 0s
    unsigned char tmpB = 0x00; // Temporary variable to hold the value of B
    unsigned char tmpA = 0x00; // Temporary variable to hold the value of A
    while (1) 
    {
		tmpA = PINA &  0x01;
		if(tmpA == 0x01)
		{
			tmpB = (tmpB & 0xFE) | 0x01;
		}
		else
		{
			tmpB = (tmpB & 0xFE) | 0x00;
		}
		PORTB = tmpB;
    }
	return 0;
}

