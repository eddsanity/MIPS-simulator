#include "utility.hpp"
#include <cassert>

uint32_t subword(uint32_t word, uint8_t leftBoundary, uint8_t rightBoundary)
{
	assert(leftBoundary <= 31);
	assert(rightBoundary >= 0);
	assert(leftBoundary > rightBoundary);

	uint32_t result = word;
	uint8_t leftOffset = 31 - leftBoundary;
	uint8_t rightOffset = leftOffset + rightBoundary;
	result <<= leftOffset;
	result >>= rightOffset;

	return result;
}

uint32_t subword64(uint64_t word, uint8_t leftBoundary, uint8_t rightBoundary)
{
	assert(leftBoundary <= 63);
	assert(rightBoundary >= 0);
	assert(leftBoundary > rightBoundary);

	uint64_t result = word;
	uint8_t leftOffset = 63 - leftBoundary;
	uint8_t rightOffset = leftOffset + rightBoundary;
	result <<= leftOffset;
	result >>= rightOffset;

	return result;
}

uint32_t signExtend8bit(uint8_t wInput)
{
	bool MSB = wInput >> 7;
	if (MSB)
	{
		uint32_t extMask = 0xFFFFFF00;
		return wInput | extMask;
	}
	else return wInput;
}

uint32_t signExtend16bit(uint16_t wInput)
{
	bool MSB = wInput >> 15;
	if (MSB)
	{
		uint32_t extMask = 0xFFFF0000;
		return wInput | extMask;
	}
	else return wInput;
}