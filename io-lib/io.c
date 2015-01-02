#include <avr/io.h>
#include "../common/rc-codes.h"
#include "io.h"

#define LOW 0
#define HIGH 1

#define TO_PORTD 7
#define TO_PORTB 13
#define TO_PORTC 17

uint8_t inline setOutputState(uint8_t pin, uint8_t state);

void inline processPORTDDirection(uint8_t pin, uint8_t direction);
void inline processPORTBDirection(uint8_t pin, uint8_t direction);
void inline processPORTCDirection(uint8_t pin, uint8_t direction);

void inline processPORTDState(uint8_t pin, uint8_t state);
void inline processPORTBState(uint8_t pin, uint8_t state);
void inline processPORTCState(uint8_t pin, uint8_t state);

uint8_t pin_mapping[] = {PD2, PD3, PD4, PD5, PD6, PD7, PB0, PB1, PB2, PB3, PB4, PB5, PC0, PC1, PC2, PC3};

/* setPinDirection (PB7, PORTB, DDRB, 0/1) */
uint8_t setPinDirection(uint8_t pin, uint8_t direction)
{
	if(pin <= TO_PORTD)
	{
		processPORTDDirection(pin_mapping[pin-2], direction);
	} else if (pin <= TO_PORTB) {
		processPORTBDirection(pin_mapping[pin-2], direction);
	} else if (pin <= TO_PORTC){
		processPORTCDirection(pin_mapping[pin-2], direction);
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
	if(pin <= TO_PORTD)
        {
                processPORTDState(pin_mapping[pin-2], state);
        } else if (pin <= TO_PORTB) {
                processPORTBState(pin_mapping[pin-2], state);
        } else if (pin <= TO_PORTC){
                processPORTCState(pin_mapping[pin-2], state);
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
