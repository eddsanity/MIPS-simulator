#include "instruction.hpp"

Instruction::Instruction(uint32_t _mcode)
{
	instr = _mcode;           
	opcode = subword(_mcode, 31, 26);
	deduceFormat();           
	switch (instrFormat)
	{
	case RTYPE:
		regSrc = subword(_mcode, 25, 21);
		regTgt = subword(_mcode, 20, 16);
		regDst = subword(_mcode, 15, 11);
		shamt = subword(_mcode, 10, 6);
		funct = subword(_mcode, 5, 0);

		immed = 0;
		adrsTgt = 0;
		break;

	case ITYPE:
		regSrc = subword(_mcode, 25, 21);
		regTgt = subword(_mcode, 20, 16);
		immed = subword(_mcode, 15, 0);

		regDst = 0;
		shamt = 0;
		funct = 0;
		adrsTgt = 0;
		break;

	case JTYPE:
		adrsTgt = subword(_mcode, 25, 0);

		regSrc = 0;
		regTgt = 0;
		regDst = 0;
		shamt = 0;
		funct = 0;
		immed = 0;
		break;
	}
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