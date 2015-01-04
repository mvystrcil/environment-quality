#ifndef MQ135
#define MQ135
#include "../common/types.h"
uint8_t mq135_initialize(uint8_t analog_pin);
uint8_t mq135_read_co2(uint16_t *val);
#endif
