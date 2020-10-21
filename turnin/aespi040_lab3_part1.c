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
	DDRB = 0X00; PORTB = 0XFF;
	DDRC = 0XFF; PORTC = 0X00;


	unsigned char count;
	unsigned char tempA;
	unsigned char tempB;
	//unsigned char tempC;

	unsigned char i;

    /* Insert your solution below */
    while (1) {

	    count = 0x00;
	    tempA = PINA;
	    tempB = PINB;

	    for(i = 0; i < 8; i++) {
		    if( (tempA & (0x01 << i) ) != 0){
			    count++;
		    }
		    if( (tempB & (0x01 <<i)) != 0){
                            count++;
                    }
	    }

	    PORTC = count;

    }
    return 1;
}
