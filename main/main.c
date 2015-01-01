#include <avr/io.h>

//#include "../bt-lib/bt.h"
//#include "../uart-lib/uart.h"
#include "../io-lib/io.h"

#define AA DDRD
#define BB PORTD

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
	setPinDirection(A_PIN2, OUTPUT);

	while(1)
	{
		setOutputHigh(A_PIN2);
		wait(600);
		setOutputLow(A_PIN2);
		wait(600);
		// Do something useful
		
	}
}
