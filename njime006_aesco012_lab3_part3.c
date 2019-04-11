/*	Noah Jimenez & njime006@ucr.edu:
 *	Alex Escobar & aesco012@ucr.edu:
 *	Lab Section: 023
 *	Assignment: Lab 3  Exercise 3 
 *	Exercise Description: 
 In addition to part 2, PA4 is 1 if a key is in the ignition, PA5 is 1 if a driver is seated, and PA6 is 1 if the driver's seatbelt is fastened. 
 PC7 should light a "Fasten seatbelt" icon if a key is in the ignition, the driver is seated, but the belt is not fastened.
 *	
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 */
 

#include <avr/io.h>

unsigned char GetBit(unsigned char x, unsigned char k) 
{
	return ((x & (0x01 << k)) != 0);
}


int main(void)
{
	DDRA = 0x00; PORTA = 0xFF;
	DDRC = 0xFF; PORTC = 0x00;
	unsigned char tmpA = 0x00;
	unsigned char tmpC;
	unsigned char lights = 0x00;
	unsigned char belt = 0x00;
	unsigned char ignition = 0x00;
	unsigned char seat = 0x00;
	while (1)
	{
		tmpC = 0x00;
		tmpA = PINA & 0x0F;
		
		
		if(tmpA > 0) 
		{
			switch (tmpA)
			{
				case 1:
					tmpC = tmpC | 0x20;
					tmpC = tmpC | 0x40;
					break;
				
				case 2:
					tmpC = tmpC | 0x20;
					tmpC = tmpC | 0x40;
					break;
				
				case 3:
					tmpC = tmpC | 0x20;
					tmpC = tmpC | 0x40;
					break;
				
				case 4:
					tmpC = tmpC | 0x30;
					tmpC = tmpC | 0x40;
					break;
				
				case 5:
					tmpC = tmpC | 0x38;
					break;
				
				case 6:
					tmpC = tmpC | 0x38;
					break;
				
				case 7:
					tmpC = tmpC | 0x3C;
					break;
				
				case 8:
					tmpC = tmpC | 0x3C;
					break;
				
				case 9:
					tmpC = tmpC | 0x3C;
					break;
				
				case 10:
					tmpC = tmpC | 0x3E;
					break;
				
				case 11:
					tmpC = tmpC | 0x3E;
					break;
					
				case 12:
					tmpC = tmpC | 0x3E;
					break;
				
				case 13:
					tmpC = tmpC | 0x3F;
					break;
				
				case 14:
					tmpC = tmpC | 0x3F;
					break;
					
				case 15:
					tmpC = tmpC | 0x3F;
					break;
			}
					
		}
		
		lights = PINA;
		ignition = GetBit(lights,4);
		seat = GetBit(lights,5);
		belt = GetBit(lights,6);
		
		if(seat && ignition) 
		{
			if(!belt) 
			{
				tmpC = tmpC | 0x80;
			}
		}
		
		PORTC = tmpC;
	}
}

