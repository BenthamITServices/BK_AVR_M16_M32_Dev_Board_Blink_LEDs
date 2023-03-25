/*
 * BK_AVR_M16_M32_Dev_Board_Blink_LEDs.cpp
 * Created: 25/03/2023 12:36:26
 * Author : Steven
 */ 

#ifndef F_CPU
#define F_CPU 8000000UL // Specify actual clock speed of target CPU so any delay macros have accurate timings.  Here 8 MHz clock speed.
#endif

#include <avr/io.h> //I/O definitions including the particular device we use e.g ATmega328P, which is specified in PROJECT > "Project Name" > Device
#include <util/delay.h> //Convenience functions for busy-wait delay loops
#include <avr/cpufunc.h> //This header file contains macros (e.g. _NOP(); that access special functions of the AVR CPU which do not fit into any of the other header files.

int x = 0;

int main(void)
{
	DDRB = DDRB | 0b11111111; //All PORTB pins to be outputs = 0xFF
	PORTB = 0b11111111; //All PORTB pins set to logic 1 (turn off LEDs) = 0xFF
	
	DDRA = DDRA | 0b11011100; //PORTA set PA2, PA3, PA4, PA6 & PA7 as outputs = 0xDC
	PORTA = 0b01100000; // PORTA set PA5 & PA6 to logic 1 = 0x60
	
	while(1) //infinite loop
	{
		_NOP();
		x++; //Increment variable x
		_NOP();
		PORTA = PORTA | 0x04; //Set 8 LEDS latch U4 to transparent mode to reflect state of PORTB
		_NOP();
		
		PORTB = PINB | 0b00000001; //Set PB0 to 1 to turn off LED D1
		_NOP();
		_delay_ms(100);

		PORTB = PINB & 0b11111110; //Sets PB0 to logic 0 to turn on LED D1
		_NOP();
		_delay_ms(500);

		}
}