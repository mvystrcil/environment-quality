#include "../io-lib/io.h"
#include "../uart-lib/uart.h"
#include "../common/rc-codes.h"

#include "mq135-lib.h"

uint8_t rx;

uint8_t mq135_initialize(uint8_t analog_pin)
{
	// set pin as AD input with ability to read on demand
	// setPinAD(reference, prescaler)
	setPinAD(AVCC, PRESCALER_128);
	rx = analog_pin;

	return MQ135_OK;
}

uint8_t mq135_read_co2(uint16_t *val)
{
	val = 5000 * readADValue(rx) / 1023;
	uart_send_string("MQ135 read value: ");
	uart_send_number(val);
	uart_send_string("\r\n");

	return MQ135_OK;
}
