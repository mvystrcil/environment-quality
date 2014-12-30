#include "common.h"

void delay_ms(uint8_t ms)
{
	
}

void delay_us(uint8_t us)
{
	if(--us == 0)
		return;
	uint8_t i,j;
	for(i = 0; i < us; i++)
	{
		j++;
	}
}
