#include "instruction.hpp"

Instruction::Instruction(uint32_t _mcode)
{
	m_instr = _mcode;           
	m_opcode = subword(_mcode, 31, 26);
	deduceFormat();
	switch (m_instrFormat)
	{
	case RTYPE:
		m_regSrc = subword(_mcode, 25, 21);
		m_regTgt = subword(_mcode, 20, 16);
		m_regDst = subword(_mcode, 15, 11);
		m_shamt = subword(_mcode, 10, 6);
		m_funct = subword(_mcode, 5, 0);

		m_immed = 0;
		m_adrsTgt = 0;
		break;

	case ITYPE:
		m_regSrc = subword(_mcode, 25, 21);
		m_regTgt = subword(_mcode, 20, 16);
		m_immed = subword(_mcode, 15, 0);

		m_regDst = 0;
		m_shamt = 0;
		m_funct = 0;
		m_adrsTgt = 0;
		break;

	case JTYPE:
		m_adrsTgt = subword(_mcode, 25, 0);

		m_regSrc = 0;
		m_regTgt = 0;
		m_regDst = 0;
		m_shamt = 0;
		m_funct = 0;
		m_immed = 0;
		break;
	}
}


void Instruction::deduceFormat()
{
	if (m_opcode == 0)
		m_instrFormat = RTYPE;
	else if (m_opcode == 2 || m_opcode == 3)
		m_instrFormat = JTYPE;
	else
		m_instrFormat = ITYPE;
}
