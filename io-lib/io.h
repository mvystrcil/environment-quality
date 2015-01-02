#ifndef IO_LIB
#define IO_LIB
#include "../common/types.h"
// Analog port definition
#define A0 14
#define A1 15
#define A2 16
#define A3 17

#define INPUT 0
#define OUTPUT 1

#define NC 0
#define A_PIN2 PD2
#define A_PIN3 PD3
#define A_PIN4 PD4
#define A_PIN5 PD5
#define A_PIN6 PD6
#define A_PIN7 PD7
#define A_PIN8 PB0
#define A_PIN9 PB1
#define A_PIN10 PB2
#define A_PIN11 PB3
#define A_PIN12 PB4
#define A_PIN13 PB5
#define A_A0 PC0
#define A_A1 PC1
#define A_A2 PC2
#define A_A3 PC3

#define PIN_MIN A_PIN2
#define PIN_MAX A_A3

uint8_t setPinDirection(uint8_t pin, uint8_t direction);

uint8_t setOutputHigh(uint8_t pin);
uint8_t setOutputLow(uint8_t pin);

uint8_t readInputLevel(uint8_t pin, uint8_t port, uint8_t *result);

#endif
