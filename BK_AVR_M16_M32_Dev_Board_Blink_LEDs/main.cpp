/*
 * BK_AVR_M16_M32_Dev_Board_Blink_LEDs.cpp
 *
 * Created: 25/03/2023 12:36:26
 * Author : Steven
 */ 

#ifndef F_CPU
#define F_CPU 16000000UL // Specify actual clock speed of target CPU so any delay macros have accurate timings.  Here 16 MHz clock speed.
#endif

#include <avr/io.h> //I/O definitions including the particular device we use e.g ATmega328P, which is specified in PROJECT > "Project Name" > Device
#include <util/delay.h> //Convenience functions for busy-wait delay loops
#include <avr/cpufunc.h> //This header file contains macros (e.g. _NOP(); that access special functions of the AVR CPU which do not fit into any of the other header files.

int x = 0;

int main(void)
{

	//DDRC |= 1 << PINC0; //
	//DDRC |= 1 << PORTC0;
	//DDRC |= 1 << DDC0;
	//DDRC = DDRC | 0x01;
	//DDRC = DDRC | 0b00000001;
	
	//DDRB = DDRB | 0b00000010;
	DDRB = DDRB | 0b11111111; //All PORTB pins to be outputs
	PORTB = 0b11111111; //All PORTB pins set to logic 1 (turn off LEDs)
	
	DDRA = DDRA | 0b11011100; //PORTA set PA2, PA3, PA4, PA6 & PA7 as outputs
	PORTA = 0b01100000; // PORTA set PA5 & PA6 to logic 1
	
	while(1) //infinite loop
	{

		//PORTB ^= 1 << PINB1; //Toggle Pin C0 on Port C, known as Analog A0 on an Arduino Pro Mini.  Can't use on-board LED as connected to PB5 which is used as SCK form the connection to the USBASP programmer
		//		PINB |= (1<<PINB1);
		_NOP();
		_NOP();
		x++;
		_NOP();
		PORTA = PORTA | 0x04; //Set 8 LEDS latch to transparent mode to reflect state of PORTB
		_NOP();
		//		_delay_ms(507);
		
		//PORTB |= 1 << PINB01;
		//		PORTB = PORTB | 0x01;
		PORTB = 0x00; //Turn on LEDs
		//PORTB = PINB | 0x02;
		_delay_ms(100);
		//		PORTB &= ~(1 << PINB1);
		PORTB = 0xFF; //Turn off LEDs
		_delay_ms(1000);

		
		
	}



}