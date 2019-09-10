#ifndef INSTRUCTION_H
#define INSTRUCTION_H

#include <cstdint>
#include <cassert>

#include "utility.hpp"


struct Instruction
{ 
	uint32_t instr;       // raw instruction machine code
	uint8_t opcode;
	uint8_t regSrc;
	uint8_t regTgt;
	uint8_t regDst;
	uint8_t shamt;
	uint8_t funct;
	uint16_t immed;
	uint32_t adrsTgt;

	INSTRFORMAT instrFormat;

	Instruction(uint32_t);
	void deduceFormat();
};

#endif