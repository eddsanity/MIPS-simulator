#include "instruction.hpp"
#include <iostream>

Instruction::Instruction(uint32_t _mcode)
{
	instr = _mcode;            // raw 32-bit instruction
	opcode = subword(31, 26);  // extract opcode from instruction
	//deduceFormat();            // deduce instruction format
	switch (instrFormat)
	{
	case RTYPE:

		break;

	case ITYPE:

		break;

	case JTYPE:

		break;
	}
}

uint32_t Instruction::subword(uint8_t leftBoundary, uint8_t rightBoundary) const
{
	assert(leftBoundary <= 31);
	assert(rightBoundary >= 0);
	assert(leftBoundary > rightBoundary);

	uint32_t result = instr;
	uint8_t leftOffset = 31 - leftBoundary;
	uint8_t rightOffset = leftOffset + rightBoundary;
	result <<= leftOffset;
	result >>= rightOffset;
	
	std::cout << result << "\n";
	return result;
}