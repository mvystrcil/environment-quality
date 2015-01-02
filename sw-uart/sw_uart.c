#include "../common/types.h"
#include "../io-lib/io.h"
#include "../uart-lib/uart.h"

uint8_t initializeSWUART(uint8_t txd, uint8_t rxd, uint16_t baudrate)
{
	uart_send_string("Initializing SW UART: txd\t rxd\t baudrate");
	uart_send_string("\r\n\t\t\t");
	uart_send_number(txd);
	uart_send_char(' ');
	uart_send_number(rxd);
	uart_send_char(' ');
	uart_send_number(baudrate);
	uart_send_string("\r\n");
}
