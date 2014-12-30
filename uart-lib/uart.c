#include "uart.h"
#include <avr/io.h>

state initialized  = INIT_NOK;

uint8_t uart_init_peripheral(uint8_t baudrate)
{
	uint8_t ubrr = F_CPU / 16 / baudrate - 1;
	/*Set baud rate */
	UBRR0H = (unsigned char)(ubrr>>8);
	UBRR0L = (unsigned char)ubrr;
	/* Enable receiver and transmitter */
	UCSR0B = (1<<RXEN0)|(1<<TXEN0);
	/* Set frame format: 8data, 1stop bit */
	UCSR0C = (3<<UCSZ00);

	initialized = INIT_OK;

	return UART_INIT_OK;
}

uint8_t uart_send_byte(uint8_t byte)
{
	if(initialized == INIT_NOK)
	{
		return UART_NOT_INITIALIZED;
	}
	/* Wait for empty transmit buffer */
	while ( !( UCSR0A & (1<<UDRE0)) )
	{

	}

	/* Put data into buffer, sends the data */
	UDR0 = byte;

	return UART_SEND_OK;
}

uint8_t uart_read_byte(uint8_t *byte)
{
	return UART_READ_OK;
}

uint8_t uart_send_word(uint16_t word)
{
	uart_send_byte(word >> 8);
	return uart_send_byte(word);
}

uint16_t uart_read_word(uint16_t *word)
{
	return UART_READ_OK;
}

uint8_t uart_send_string(char *str)
{
	if(initialized == INIT_NOK)
	{
		return UART_NOT_INITIALIZED;
	}

	while(str)
	{
		if(uart_send_byte(*(str++)) != UART_SEND_OK)
		{
			return UART_SEND_STRING_ERROR;
		}
	}

	return UART_SEND_OK;
}
