#ifndef UTILITY_H
#define UTILITY_H

#include <cstdint>

enum INSTRFORMAT { RTYPE, ITYPE, JTYPE };

uint32_t subword(uint32_t, uint8_t, uint8_t);
uint32_t subword64(uint64_t, uint8_t, uint8_t);
uint32_t signExtend8bit(uint8_t);
uint32_t signExtend16bit(uint16_t);

#endif