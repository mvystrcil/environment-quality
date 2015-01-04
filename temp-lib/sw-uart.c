#include "../common/types.h"
#include "../io-lib/io.h"
#include "../uart-lib/uart.h"
#include "../common/delay.h"

#include "sw-uart.h"


void sw_uart_send_byte(uint8_t byte);

uint8_t receive_buffer[124];
uint8_t tx, rx;
uint8_t _delay_us;

uint8_t initializeSWUART(uint8_t txd, uint8_t rxd, uint16_t baudrate)
{
	uart_send_string("Set txd on pin: ");
	uart_send_number(txd);
	uart_send_string(" rxd on pin: ");
	uart_send_number(rxd);
	uart_send_string("\r\n");
	uart_send_string("Baudrate: ");
	uart_send_number(baudrate);
	uart_send_string("\r\n");

	tx = txd;
	rx = rxd;
	_delay_us = 1000000 / baudrate;

	uart_send_string("Delay: ");
	uart_send_number(_delay_us);
	uart_send_string("\r\n");

	setPinDirection(tx, OUTPUT);
	setPinDirection(rx, INPUT);
	setOutputHigh(txd);
	delay_us(_delay_us);

	return IO_OK;
}

uint8_t sw_uart_send_string(char *str)
{
	while(*str)
	{
		sw_uart_send_byte(*(str++));
	}

	return IO_OK;
}

void sw_uart_send_byte(uint8_t byte)
{
	uint8_t mask;
	setOutputLow(tx);
	delay_us(_delay_us);

	for(mask = 0x1; mask; mask <<= 1)
	{
		if(byte & mask)
		{
			uart_send_number(1);
			setOutputHigh(tx);
		} else {
			uart_send_number(0);
			setOutputLow(tx);
		}

		delay_us(_delay_us);
	}

	setOutputHigh(tx);
}

uint8_t sw_uart_read_byte()
{
	return IO_OK;
}
