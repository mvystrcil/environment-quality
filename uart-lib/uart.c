#include "uart.h"
#include <avr/io.h>

state initialized  = INIT_NOK;

void itoa(uint16_t i, char array[]);

uint8_t uart_init_peripheral(uint16_t baudrate)
{
	uint16_t ubrr = F_CPU / 16 / baudrate - 1;
	/*Set baud rate */
	UBRR0H = (unsigned char)(ubrr >> 8);
	UBRR0L = (unsigned char)ubrr;
	/* Enable receiver and transmitter */
	UCSR0B = (1 << RXEN0)|(1 << TXEN0);
	/* Set frame format: 8data, 1stop bit */
	UCSR0C = (1 << UCSZ00)|(1 << UCSZ01);
	
	//UCSR0A |= (1 << U2X0);

	initialized = INIT_OK;

	return UART_INIT_OK;
}

uint8_t uart_send_char(uint8_t byte)
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
	UDR0 = (unsigned char) byte;

	return UART_SEND_OK;
}

uint8_t uart_read_byte(uint8_t *byte)
{
	return UART_READ_OK;
}

uint8_t uart_send_word(uint16_t word)
{
	uart_send_char(word >> 8);
	return uart_send_char(word);
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

	while(*str)
	{
		if(uart_send_char(*(str++)) != UART_SEND_OK)
		{
			return UART_SEND_STRING_ERROR;
		}
	}

	return UART_SEND_OK;
}

uint8_t uart_send_number(uint16_t number)
{
	char array[4];
	
	itoa(number, array);

	uart_send_string(array);

	return UART_SEND_OK;
}

/*
* Private functions
*/
void itoa(uint16_t i, char array[])
{
	char const digits[] = "0123456789";
	uint8_t shift = i;
	char *p = array;

	/* Find the length of number */
	do {
		p++;
		shift = shift / 10;
	} while(shift);

	*p = 0;

	do {
		*(--p) = digits[i % 10];
		i = i / 10;
	} while (i);
}
