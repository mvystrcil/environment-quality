#include "common.h"
#include "types.h"

#define CYCLES_US 15
#define CYCLES_MS 16120

void delay_ms(uint8_t ms)
{
	uint8_t i;
	uint16_t j;
	for(i = 0; i < ms; i++)
	{
		for(j = 0; j < CYCLES_MS; j++)
		{}
	}
}

void delay_us(uint8_t us)
{
	uint8_t i,j;
	for(i = 0; i < us; i++)
	{
		for(j = 0; j < CYCLES_US; j++)
		{}
	}
}
