/*	Noah Jimenez & njime006@ucr.edu:
 *	Alex Escobar & aesco012@ucr.edu:
 *	Lab Section: 023
 *	Assignment: Lab 3  Exercise 1 
 *	Exercise Description: 
 Count the number of 1's in Ports A and B and output it to port C
 *	
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 */


#include <avr/io.h>


unsigned char GetBit(unsigned char x, unsigned char k) {
	return((x & (0x01 << k)) != 0); 
}

int main(void)
{
	DDRA = 0x00; PORTA = 0xFF;
	DDRB = 0x00; PORTB = 0xFF;
	DDRC = 0xFF; PORTC = 0x00;
	unsigned char tmpA = 0x00;
	unsigned char tmpB = 0x00;
	
	while (1) 
    {
		unsigned char cnt = 0x00;
		tmpA = PINA;
		tmpB = PINB;
			
		for(int i = 0; i < 8; i++) 
		{
			if(GetBit(tmpA,i) != 0)
				{cnt++;}
					
			if(GetBit(tmpB, i) != 0)
				{cnt++;}
		}
		PORTC = cnt;
    }
}

