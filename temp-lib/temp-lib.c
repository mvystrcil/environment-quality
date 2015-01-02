#include "../io/io-lib.h"
#include "../common/common.h"
#include "../common/rc-codes.h"
#include "../uart-lib/uart.h"

uint8_t initializeDHT()
{
	uart_send_string("DHT peripheral is ready to use\n\r");
	return DHT_OK;
}

uint8_t readData()
{
	
}
