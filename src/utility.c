#include <assert.h>
#include <stdint.h>

#include "utility.h"

uint32_t subword(uint32_t word, uint8_t left_boundry, uint8_t right_boundry)
{
	assert(left_boundry <= 31);
	assert(right_boundry >= 0);
	assert(left_boundry > right_boundry);

	uint32_t result = word;
	uint8_t left_offset = 31 - left_boundry;
	uint8_t rihgt_offset = left_offset + right_boundry;
	result <<= left_offset;
	result >>= rihgt_offset;

	return result;
}

uint32_t subword64(uint64_t word, uint8_t left_boundry, uint8_t right_boundry)
{
	assert(left_boundry <= 63);
	assert(right_boundry >= 0);
	assert(left_boundry > right_boundry);

	uint64_t result = word;
	uint8_t left_offset = 63 - left_boundry;
	uint8_t rihgt_offset = left_offset + right_boundry;
	result <<= left_offset;
	result >>= rihgt_offset;

	return result;
}

uint32_t signExtend8bit(uint8_t w_input)
{
	char MSB = w_input >> 7;
	if (MSB)
	{
		uint32_t ext_mask = 0xFFFFFF00;
		return w_input | ext_mask;
	}
	else return w_input;
}

uint32_t signExtend16bit(uint16_t w_input)
{
	char MSB = w_input >> 15;
	if (MSB)
	{
		uint32_t ext_mask = 0xFFFF0000;
		return w_input | ext_mask;
	}
	else return w_input;
}