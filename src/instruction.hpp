#ifndef INSTRUCTION_H
#define INSTRUCTION_H

#include <cstdint>
#include <cassert>

#include "utility.hpp"


struct Instruction
{ 
	uint32_t m_instr;       // raw instruction machine code
	uint8_t m_opcode;
	uint8_t m_regSrc;
	uint8_t m_regTgt;
	uint8_t m_regDst;
	uint8_t m_shamt;
	uint8_t m_funct;
	uint16_t m_immed;
	uint32_t m_adrsTgt;

	INSTRFORMAT m_instrFormat;

	Instruction(uint32_t);
	void deduceFormat();
};

#endif