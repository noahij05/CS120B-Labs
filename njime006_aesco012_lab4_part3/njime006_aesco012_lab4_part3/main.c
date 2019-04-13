/*	Noah Jimenez & njime006@ucr.edu:
 *	Alex Escobar & aesco012@ucr.edu:
 *	Lab Section: 023
 *	Assignment: Lab 4  Exercise 3 
 *	Exercise Description: 
A household has a digital combination deadbolt lock system on the doorway. The system has buttons on a keypad. 
Button 'X' connects to PA0, 'Y' to PA1, and '#' to PA2. Pressing and releasing '#', then pressing 'Y', should unlock the door by setting PB0 to 1.
Any other sequence fails to unlock. Pressing a button from inside the house (PA7) locks the door (PB0=0). 
For debugging purposes, give each state a number, and always write the current state to PORTC (consider using the enum state variable).
 Also, be sure to check that only one button is pressed at a time.

 *	
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 */

#include <avr/io.h>


enum lockState { state1, state2, state3, state4, state5 } lock ;

void unlock() 
{
	
	unsigned char X = PINA & 0x01;
	unsigned char Y = PINA & 0x02;
	unsigned char Pound = PINA & 0x04;
	unsigned char Lock = PINA & 0x80;
	unsigned char tmpB;
	unsigned char tmpC;
	
	switch(lock) 
	{
		case state1: 
			if( (!X && !Y) && (Pound && !Lock)) { 
				lock = state2;
			} 
			else { 
				lock = state1;
			}
			break;
		
		case state2: 
			if( (!X && !Y) && (Pound && !Lock)) { 
				lock = state2;
			}
			else { 
				if( (!X && !Y) && (!Pound && !Lock)) { 
					lock = state3;
				} 
				else { 
					lock = state1;
				}
			}
			break;
		
		case state3: 
			if( (!X && !Y) && (!Pound && !Lock)) { 
				lock = state3;
			} 
			else { 
				if( (!X && Y) && (!Pound && !Lock)) { 
					lock = state4;
				} 
				else { 
					lock = state1;
				}
			}
			break;
		
		case state4: 
			if( (!X && Y) && (!Pound && !Lock)) { 
				lock = state4;
			} 
			else { 
				if( (!X && !Y) && (!Pound && !Lock)) { 
					lock = state5;
				} 
				else { 
					lock = state1;
				}
			}
			break;
			
		case state5: 
			if(Lock) { 
				lock = state1;
			} 
			else { 
				lock = state5;
			}
			break;
	
		default:  
			lock = state1;
			break;
		
	} 
	
	switch(lock) 
	{
		case state1: 	
			tmpB = 0;
			tmpC = 1;
			break;
		
		case state2: 
			tmpB = 0;
			tmpC = 2;
			break;
		
		case state3:  
			tmpB = 0;
			tmpC = 3;
			break;
		
		case state4:  
			tmpB = 0;
			tmpC = 4;
			break;
		
		case state5:  
			tmpB = 1;
			tmpC = 5;
			break;
		
		default: 
			tmpB = 0;
			tmpC = 1;
			break;

	}
	 
	PORTB = tmpB;
	PORTC = tmpC;
	
}

int main(void)
{
	DDRA = 0x00; PORTA = 0xFF;
	DDRB = 0xFF; PORTB = 0x00;
	DDRC = 0xFF; PORTC = 0x00;
	lock = state1;
	
	while (1)
	{
		unlock();
	}
}
