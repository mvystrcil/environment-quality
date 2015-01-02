#include "../common/types.h"
#include "../io-lib/io.h"
#include "../uart-lib/uart.h"
#include "sw-uart.h"

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

	setPinDirection(txd, OUTPUT);
	setPinDirection(rxd, INPUT);
}
