#include <avr/io.h>
#include "../common/rc-codes.h"

#define LOW 0
#define HIGH 1

uint8_t setOutputState(uint8_t pin, uint8_t port, uint8_t state);

/* setPinDirection (PB7, PORTB, DDRB, 0/1) */
uint8_t setPinDirection(uint8_t pin, uint8_t ddr, uint8_t direction)
{
	if(direction)
	{
		ddr |= (1 << pin);
	} else {
		ddr &= ~(1 << pin);
	}

	return IO_OK;
}

uint8_t setOutpuHigh(uint8_t pin, uint8_t port)
{
	setOutputState(pin, port, HIGH);
	return IO_OK;
}

uint8_t setOutputLow(uint8_t pin, uint8_t port)
{
	setOutputState(pin, port, LOW);
	return IO_OK;
}

uint8_t readInputLevel(uint8_t pin, uint8_t port, uint8_t *result)
{
	return IO_OK;
}
/*
* Private functions
*/
uint8_t inline setOutputState(uint8_t pin, uint8_t port, uint8_t state)
{
	if(state)
	{
		port |= (1 << pin);
	} else {
		port &= ~(1 << pin);
	}

	return IO_OK;
}
