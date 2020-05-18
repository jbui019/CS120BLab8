/*	Author: jbui019
 *  Partner(s) Name: 
 *	Lab Section:
 *	Assignment: Lab #  Exercise #
 *	Exercise Description: [optional - include for your own benefit]
 *
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 */
#include <avr/io.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif
void ADC_init(){
	ADCSRA |= (1 << ADEN) | (1 << ADSC) | (1 << ADATE);
}
int main(void){
    /* Insert DDR and PORT initializations */
	DDRA = 0x00; PORTA = 0xFF;
	DDRB = 0xFF; PORTB = 0x00;
	DDRD = 0xFF; PORTD = 0x00;
	ADC_init();

	unsigned char tempB = 0x00;
	unsigned char tempD = 0x00;
	unsigned short  max = 0xC0;
	unsigned short threshold = (max/8);	

    /* Insert your solution below */
    while (1) {
	unsigned short x = ADC;
	tempB = (char)x;
	tempD = (char)(x >> 8);
	
	if((x > 0) && ( x < threshold)){
		PORTB = 0x01;
	}
	else if((x < 2*threshold) && (x >= threshold)){
		PORTB = 0x03;
	}
	else if((x < 3*threshold) && (x >= 2*threshold)){
		PORTB = 0x07;
	}
        else if((x < 4*threshold) && (x >= 3*threshold)){
		PORTB = 0x0F;
	}
        else if((x < 5*threshold) && (x >= 4*threshold)){
		PORTB = 0x1F;
	}
        else if((x < 6*threshold) && (x >= 5*threshold)){
		PORTB = 0x3F;
	}
        else if((x < 7*threshold) && (x >= 6*threshold)){
		PORTB = 0x7F;
	}
        else if((x >= 7*threshold)){
		PORTB = 0xFF;
	}
	else{
		PORTB = 0x00;
	}
    
    }
    return 1;
}
