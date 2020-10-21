/*	Author: lab
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

int main(void) {
    /* Insert DDR and PORT initializations */

	DDRA = 0X00; PORTA = 0XFF;
	//DDRB = 0X00; PORTB = 0XFF;
	DDRC = 0XFF; PORTC = 0X00;


	//unsigned char count;
	unsigned char tempA;
	//unsigned char tempB;
	unsigned char tempC;
	unsigned char sbWarning;

	//unsigned char i;

    /* Insert your solution below */
    while (1) {

	    sbWarning = ((PINA & 0xF0) >> 4) ;	
	    tempA = PINA & 0x0F;
            tempC = 0x40;
	
	//Lvls 1-2
	if(tempA < 3){
		tempC = 0x60;	
	}
	//lvls 3-4
	else if(tempA < 5){
		tempC = 0x70;
	}
	//lvls 5-6
	else if(tempA < 7){
		tempC = 0x38;
	}
	//lvls 7-9
	else if(tempA < 10){
		tempC = 0x3C;
	}
	//lvls 10-12
	else if(tempA < 13){
		tempC = 0x3E;
	}	
	//lvls 13-15
	else{
		tempC = 0x3F;
	}

	if(sbWarning == 3){
		tempC = tempC | 0x80;
	}

	PORTC = tempC;

    }
    return 1;
}
