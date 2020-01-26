#ifndef INSTRUCTION_H
#define INSTRUCTION_H

#include <stdint.h>

enum INSTRFORMAT { RTYPE, ITYPE, JTYPE };

typedef struct Instruction
{ 
	uint8_t     opcode;
	uint8_t     reg_src;
	uint8_t     reg_tgt;
	uint8_t     reg_dst;
	uint8_t     shamt;
	uint8_t     funct;
	uint16_t    immed;
	uint32_t    addr_tgt;

	enum INSTRFORMAT instr_format;
} Instruction;

Instruction parse_instr(uint32_t instr);

enum INSTRFORMAT deduce_format(uint8_t opcode);

Instruction fill_Rtype(uint32_t instr);
Instruction fill_Jtype(uint32_t instr);
Instruction fill_Itype(uint32_t instr);

#endif