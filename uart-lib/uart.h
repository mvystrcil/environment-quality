#include "../common/types.h"
#include "../common/rc-codes.h"
#include "../common/common.h"

#define FOSC 800000 // Clock Speed
#define BAUD 9600
#define MYUBRR FOSC/16/BAUD-1

#define INIT_NOK 0
#define INIT_OK 1

uint8_t uart_init_peripheral(uint8_t baudrate);
uint8_t uart_send_byte(uint8_t byte);
uint8_t uart_read_byte(uint8_t *byte);

uint8_t uart_send_word(uint16_t word);
uint16_t uart_read_word(uint16_t *word);
uint8_t uart_send_string(char *str);
