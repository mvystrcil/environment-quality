#include <avr/io.h>

//#include "../bt-lib/bt.h"
#include "../uart-lib/uart.h"
#include "../io-lib/io.h"
#include "../sw-uart/sw_uart.h"

#define BAUDRATE 9600
#define LED_PIN 13

void wait(int time)
{
	int i,j;
	for(j = 0; j < time; j++)
	{
		for(i = 0; i < time; i++)
		{
		}
	}
}

int main(void)
{
	setPinDirection(2, OUTPUT);
	setPinDirection(LED_PIN, OUTPUT);
	//DDRD |= (1 << 2);

	uart_init_peripheral(BAUDRATE);
	uint16_t inc = 0;

	initializeSWUART(2, 3, 9600);

	while(1)
	{
		uart_send_string("Welcome to command line of environment meter\n\r");
		uart_send_string("Num of iterations: ");
		uart_send_number(inc++);
		uart_send_string("\n\r");

		setOutputHigh(LED_PIN);
		//PORTD |= (1 << 2);
		wait(600);
		setOutputLow(LED_PIN);
		wait(600);
		// Do something useful
		
	}
}
