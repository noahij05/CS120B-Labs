    
/*	Noah Jimenez & njime006@ucr.edu:
 *	Alex Escobar & aesco012@ucr.edu:
 *	Lab Section: 023
 *	Assignment: Lab 4  Exercise 1 
 *	Exercise Description: 
 PB0 and PB1 each connect to an LED, and PB0's LED is initially on. 
 Pressing a button connected to PA0 turns off PB0's LED and turns on PB1's LED, staying that way after button release. 
 Pressing the button again turns off PB1's LED and turns on PB0's LED.
 *	
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 */

#include <avr/io.h>

enum LightStates { LED_PB0 , LED_PB1 } nextState;
	
void buttonPress()
{
	unsigned char button = PINA & 0x01;
	unsigned char LED = 0;
	
	switch (nextState)
	{
		case LED_PB0:
		{
			if(button == 1){
				nextState = LED_PB1;
			}
			else{
				nextState = LED_PB0;
			}
			break;
		}
		
		case LED_PB1:
		{
			if(button == 1){
				nextState = LED_PB0;
			}
			else{
				nextState = LED_PB1;
			}
			break;
		}
		
		default:
			nextState = LED_PB0;
			break;
	}
	
	switch (nextState)
	{
		case LED_PB0:
			LED = 1;
			break;
		
		case LED_PB1:
			LED = 2;
			break;
			
		default:
			LED = 0;
			break;
		
	}
	PORTB = LED;
}

int main(void)
{
    DDRA = 0x00; PORTA = 0xFF;
    DDRB = 0xFF; PORTB = 0x00;
	nextState = LED_PB0;
    
    while (1) 
    {
		buttonPress();
	}
}

