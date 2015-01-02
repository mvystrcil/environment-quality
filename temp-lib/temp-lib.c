#include "../io-lib/io.h"
#include "../common/common.h"
#include "../common/rc-codes.h"
#include "../uart-lib/uart.h"
#include "sw-uart.h"

#define TXD 3
#define RXD 4
#define DHT_BAUDRATE 9600

uint8_t initializeDHT()
{
	initializeSWUART(TXD, RXD, DHT_BAUDRATE);
	uart_send_string("DHT peripheral is ready to use\n\r");
	return DHT_OK;
}

uint8_t readData()
{
	
}
