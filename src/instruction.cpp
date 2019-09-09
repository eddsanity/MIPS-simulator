#include "instruction.hpp"

Instruction::Instruction(uint32_t _mcode)
{
	instr = _mcode;           
	opcode = subword(_mcode, 31, 26);
	deduceFormat();
	deduceInstr();
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
	else if (opcode == 2 || opcode == 3)
		instrFormat = JTYPE;
	else
		instrFormat = ITYPE;
}

void Instruction::deduceInstr()
{
	switch (instrFormat)
	{
	case RTYPE:
		switch (funct)
		{
		case 0x20:
			instrToken = ADD;
			break;
		case 0x21:
			instrToken = ADDU;
			break;
		case 0x22:
			instrToken = SUB;
			break;
		case 0x23:
			instrToken = SUBU;
			break;
		case 0x1A:
			instrToken = DIV;
			break;
		case 0x1B:
			instrToken = DIVU;
			break;
		case 0x18:
			instrToken = MULT;
			break;
		case 0x19:
			instrToken = MULTU;
			break;
		case 0x24:
			instrToken = AND;
			break;
		case 0x25:
			instrToken = OR;
			break;
		case 0x26:
			instrToken = XOR;
			break;
		case 0x27:
			instrToken = NOR;
			break;
		case 0x0:
			instrToken = SLL;
			break;
		case 0x2:
			instrToken = SRL;
			break;
		case 0x2A:
			instrToken = SLT;
			break;
		case 0x2B:
			instrToken = SLTU;
			break;
		case 0x10:
			instrToken = MFHI;
			break;
		case 0x11:
			instrToken = MTHI;
			break;
		case 0x12:
			instrToken = MFLO;
			break;
		case 0x13:
			instrToken = MTLO;
			break;
		case 0xC:
			instrToken = SYSCALL;
			break;
		}
		break;
	case ITYPE:
		break;
	case JTYPE:
		break;
	}
}