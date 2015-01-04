#include <avr/io.h>

//#include "../bt-lib/bt.h"
#include "../uart-lib/uart.h"
#include "../io-lib/io.h"
#include "../temp-lib/temp-lib.h"
#include "../mq135-lib/mq135-lib.h"

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
	initializeDHT();
	float f = 0.0;

	mq135_initialize(0);
	mq135_read_co2(&f);

	while(1)
	{
		setOutputHigh(LED_PIN);
		//PORTD |= (1 << 2);
		wait(600);
		setOutputLow(LED_PIN);
		wait(600);
		// Do something useful
		
	}
}
