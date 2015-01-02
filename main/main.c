#include <avr/io.h>

//#include "../bt-lib/bt.h"
//#include "../uart-lib/uart.h"
#include "../io-lib/io.h"

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
	setPinDirection(2, 1);
	//DDRD |= (1 << 2);

	//uart_init_peripheral(BAUDRATE);	

	while(1)
	{
		//uart_send_byte('a');
		setOutputHigh(2);
		//PORTD |= (1 << 2);
		wait(600);
		setOutputLow(2);
		wait(600);
		// Do something useful
		
	}
}
