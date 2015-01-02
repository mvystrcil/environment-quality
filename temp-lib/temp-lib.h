#include "../common/common.h"
#include "../common/rc-codes.h"
#include "../common/types.h"

#define SIZE_OF_BUFFER 40 // 40 bits are sent

/* All time values in us */
#define START_SIGNAL 1800
#define START_WAIT_FOR_RESPONSE 40
#define START_RESPONSE_SIGNAL_LOW 80
#define START_RESPONSE_SIGNAL_HIGH 80

#define DATA_TRANSMIT_START 50
#define DATA_TRANSMIT_LOW 30
#define DATA_TRANSMIT_HIGH 70

#define LAST_BIT_SENT 50

/* Data description */
#define INTEGRAL_RH_DATA 0
#define DECIMAL_RH_DATA 8
#define INTEGRAL_T_DATA 16
#define DECIMAL_T_DATA 24
#define CHECKSUM_DATA 32

uint8_t readData();
uint8_t getTemperature();
uint8_t getHumidity();

uint8_t initializeDHT();
