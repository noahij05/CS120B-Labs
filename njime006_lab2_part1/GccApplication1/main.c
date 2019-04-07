/*
 * GccApplication1.c
 *
 * Created: 4/4/2019 9:02:35 AM
 * Author : Noah Jimenez
 */ 

#include <avr/io.h>


int main(void)
{
	/*
    DDRB = 0xFF; // Configure port B's 8 pins as outputs
    PORTB = 0x00; // Initialize PORTB output to 0’s
    while(1)
    {
        PORTB = 0x0F; // Writes port B's 8 pins with 00001111
    }

	DDRA = 0x00; PORTA = 0xFF; // Configure port A's 8 pins as inputs
	DDRB = 0xFF; PORTB = 0x00; // Configure port B's 8 pins as outputs
	// Initialize output on PORTB to 0x00
	unsigned char temp_input = 0x00;
	while(1)
	{
    	temp_input = PINA;
    	PORTB = temp_input;	// Writes port B's 8 pins with the values
    	// on port A's 8 pins
	}*/

	DDRA = 0x00; PORTA = 0xFF; // Configure port A's 8 pins as inputs
	DDRB = 0xFF; PORTB = 0x00; // Configure port B's 8 pins as outputs, initialize to 0s
	unsigned char tmpB = 0x00; // Temporary variable to hold the value of B
	unsigned char tmpA = 0x00; // Temporary variable to hold the value of A
	while(1)
	{
    	// 1) Read input
    	tmpA = PINA & 0x01;
    	// 2) Perform computation
    	// if PA0 is 1, set PB1PB0 = 01, else = 10
    	if (tmpA == 0x01) { // True if PA0 is 1
        	tmpB = (tmpB & 0xFC) | 0x01; // Sets tmpB to bbbbbb01
        	// (clear rightmost 2 bits, then set to 01)
    	}
    	else {
        	tmpB = (tmpB & 0xFC) | 0x02; // Sets tmpB to bbbbbb10
        	// (clear rightmost 2 bits, then set to 10)
    	}
    	// 3) Write output
    	PORTB = tmpB;
	}
	return 0;

}

