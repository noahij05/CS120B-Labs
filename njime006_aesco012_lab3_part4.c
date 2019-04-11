/*
 * aesco012_lab2_part4.c
 *
 * Created: 4/10/2019 7:33:14 PM
 * Author : Escob
 */ 

#include <avr/io.h>

// Bit-access function
unsigned char SetBit(unsigned char x, unsigned char k, unsigned char b) {
	return (b ? x | (0x01 << k) : x & ~(0x01 << k));
}
unsigned char GetBit(unsigned char x, unsigned char k) {
	return ((x & (0x01 << k)) != 0);
}


int main(void)
{
    /* Replace with your application code */
	DDRA = 0x00; PORTA = 0xFF; // Configure port A's 8 pins as inputs
	DDRB = 0xFF; PORTB = 0x00;
	DDRC = 0xFF; PORTC = 0x00; // Configure port C's 8 pins as outputs, initialize to 0s
	
	unsigned char tmpA = 0x00;
	unsigned char tmpB = 0x00;
	unsigned char tmpC = 0x00;
	unsigned char Bbit = 0x00;
	unsigned char Cbit = 0x00;
    while (1) 
    {
		tmpA = PINA & 0xFF;
		tmpB = 0x00;
		tmpC = 0x00;
		
		for(unsigned char i = 0; i < 4; i++)
		{
			Bbit = GetBit(tmpA, i+4);
			Cbit = GetBit(tmpA, i);
			tmpB= SetBit(tmpB, i+4, Bbit);
			tmpC = SetBit(tmpC, i, Cbit);
		}
    
		PORTB = tmpB;
		PORTC = tmpC;	
	}
	return 0;
}

