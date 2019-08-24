#include "instruction.hpp"

Instruction::Instruction(uint32_t _mcode)
{
	instr = _mcode;           
	opcode = subword(31, 26);
	deduceFormat();           
	switch (instrFormat)
	{
	case RTYPE:
		regSrc = subword(25, 21);
		regTgt = subword(20, 16);
		regDst = subword(15, 11);
		shamt = subword(10, 6);
		funct = subword(5, 0);

		immed = 0;
		adrsTgt = 0;
		break;

	case ITYPE:
		regSrc = subword(25, 21);
		regTgt = subword(20, 16);
		immed = subword(15, 0);

		regDst = 0;
		shamt = 0;
		funct = 0;
		adrsTgt = 0;
		break;

	case JTYPE:
		adrsTgt = subword(25, 0);

		regSrc = 0;
		regTgt = 0;
		regDst = 0;
		shamt = 0;
		funct = 0;
		immed = 0;
		break;
	}
}


// returns bits in range [leftBoundary : rightBoundary]
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
	
	return result;
}

uint32_t Instruction::signExtend8bit(uint8_t arg) const
{
	bool MSB = arg >> 7;
	if (MSB)
	{
		uint32_t extMask = 0xFFFFFF00;
		return arg | extMask;
	}
	else return arg;
}

uint32_t Instruction::signExtend16bit(uint16_t arg) const
{
	bool MSB = arg >> 15;
	if (MSB)
	{
		uint32_t extMask = 0xFFFF0000;
		return arg | extMask;
	}
	else return arg;
}

void Instruction::deduceFormat()
{
	if (opcode == 0)
		instrFormat = RTYPE;
	else if (opcode == 2 || opcode == 3 || opcode == 26)
		instrFormat = JTYPE;
	else
		instrFormat = ITYPE;
}