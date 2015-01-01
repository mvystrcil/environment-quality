// Analog port definition
#define A0 14
#define A1 15
#define A2 16
#define A3 17

#define PIN_MIN 2
#define PIN_MAX 17

#define INPUT 0
#define OUTPUT 1

#define A_PIN2 2
#define A_PIN3 3
#define A_PIN4 4
#define A_PIN5 5
#define A_PIN6 6
#define A_PIN7 7
#define A_PIN8 9
#define A_PIN9 9
#define A_PIN10 10
#define A_PIN11 11
#define A_PIN12 12
#define A_PIN13 13
#define A_A0 14
#define A_A1 15
#define A_A2 16
#define A_A3 17

uint8_t setPinDirection(uint8_t pin, uint8_t direction);

uint8_t setOutputHigh(uint8_t pin);
uint8_t setOutputLow(uint8_t pin);

uint8_t readInputLevel(uint8_t pin, uint8_t port, uint8_t *result);
