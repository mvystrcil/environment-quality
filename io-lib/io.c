#include <avr/io.h>
#include "../common/rc-codes.h"
#include "io.h"

#define LOW 0
#define HIGH 1

#define TO_PORTD A_PIN8
#define TO_PORTB A_A0
#define TO_PORTC A_A3

uint8_t inline setOutputState(uint8_t pin, uint8_t state);

void inline processPORTDDirection(uint8_t pin, uint8_t direction);
void inline processPORTBDirection(uint8_t pin, uint8_t direction);
void inline processPORTCDirection(uint8_t pin, uint8_t direction);

void inline processPORTDState(uint8_t pin, uint8_t state);
void inline processPORTBState(uint8_t pin, uint8_t state);
void inline processPORTCState(uint8_t pin, uint8_t state);

/* setPinDirection (PB7, PORTB, DDRB, 0/1) */
uint8_t setPinDirection(uint8_t pin, uint8_t direction)
{
	if(pin < TO_PORTD && pin >= PIN_MIN)
	{
		processPORTDDirection(pin, direction);
	} else if (pin < TO_PORTB) {
		processPORTBDirection(pin, direction);
	} else if (pin < TO_PORTC && pin <= PIN_MAX){
		processPORTCDirection(pin, direction);
	} else {
		return ILLEGAL_PIN_NUMBER;
	}

	return IO_OK;
}

uint8_t setOutputHigh(uint8_t pin)
{
	return setOutputState(pin, HIGH);
}

uint8_t setOutputLow(uint8_t pin)
{
	return setOutputState(pin, LOW);
}

uint8_t readInputLevel(uint8_t pin, uint8_t port, uint8_t *result)
{
	return IO_OK;
}

/*
* Private functions
*/

uint8_t inline setOutputState(uint8_t pin, uint8_t state)
{
	if(pin < TO_PORTD && pin >= PIN_MIN)
        {
                processPORTDState(pin, state);
        } else if (pin < TO_PORTB) {
                processPORTBState(pin, state);
        } else if (pin < TO_PORTC && pin <= PIN_MAX){
                processPORTCState(pin, state);
        } else {
                return ILLEGAL_PIN_NUMBER;
        }

        return IO_OK;
}

void inline processPORTDDirection(uint8_t pin, uint8_t direction)
{
	if(direction)
	{
		DDRD |= (1 << pin);
	} else {
		DDRD &= ~(1 << pin);
	}
}

void inline processPORTBDirection(uint8_t pin, uint8_t direction)
{
	if(direction)
	{
		DDRB |= (1 << pin);
	} else {
		DDRB &= ~(1 << pin);
	}
}

void inline processPORTCDirection(uint8_t pin, uint8_t direction)
{
	if(direction)
	{
		DDRC |= (1 << pin);
	} else {
		DDRC &= ~(1 << pin);
	}
}

void inline processPORTDState(uint8_t pin, uint8_t state)
{
        if(state)
        {
                PORTD |= (1 << pin);
        } else {
                PORTD &= ~(1 << pin);
        }
}

void inline processPORTBState(uint8_t pin, uint8_t state)
{
        if(state)
        {
                PORTB |= (1 << pin);
        } else {
                PORTB &= ~(1 << pin);
        }
}

void inline processPORTCState(uint8_t pin, uint8_t state)
{
        if(state)
        {
                PORTC |= (1 << pin);
        } else {
                PORTC &= ~(1 << pin);
        }
}
