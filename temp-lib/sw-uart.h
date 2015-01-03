#ifndef SW_UART
#define SW_UART

uint8_t initializeSWUART(uint8_t txd, uint8_t rxd, uint16_t baudrate);
uint8_t sw_uart_send_string(char *str);
#endif
