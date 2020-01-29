#ifndef UTILITY_H
#define UTILITY_H

#include <stdint.h>

uint32_t subword(uint32_t, uint8_t, uint8_t);
uint32_t subword64(uint64_t, uint8_t, uint8_t);
uint32_t sign_extend8bit(uint8_t);
uint32_t sign_extend16bit(uint16_t);

#endif