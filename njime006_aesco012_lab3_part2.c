/*	Noah Jimenez & njime006@ucr.edu:
 *	Alex Escobar & aesco012@ucr.edu:
 *	Lab Section: 023
 *	Assignment: Lab 3  Exercise 2 
 *	Exercise Description: 
 A car has a fuel-level sensor that sets PA3..PA0 to a value between 0 (empty) and 15 (full). 
 A series of LEDs connected to PC5..PC0 should light to graphically indicate the fuel level. 
 If the fuel level is 1 or 2, PC5 lights. If the level is 3 or 4, PC5 and PC4 light. 
 Level 5-6 lights PC5..PC3. 7-9 lights PC5..PC2. 10-12 lights PC5..PC1. 13-15 lights PC5..PC0. 
 Also, PC6 connects to a "Low fuel" icon, which should light if the level is 4 or less.
 *	
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 */
 

#include <avr/io.h>


int main(void)
{
	DDRA = 0x00; PORTA = 0xFF;
	DDRC = 0xFF; PORTC = 0x00;
	unsigned char tmpA = 0x00;
	unsigned char tmpC;
	while (1)
	{
		tmpC = 0x00;
		tmpA = PINA & 0x0F;
		
		if(tmpA > 0) {
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
		PORTC = tmpC;
	}
}

