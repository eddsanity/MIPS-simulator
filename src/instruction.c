#include <stdint.h>
#include <assert.h>

#include "instruction.h"
#include "utility.h"

Instruction parse_instr(uint32_t instr)
{
    uint8_t opcode = subword(instr, 31, 26);
    enum INSTRFORMAT instr_format = deduce_format(opcode);
    switch (instr_format)
	{
	case RTYPE:
        return fill_Rtype(instr);

	case ITYPE:
		return fill_Itype(instr);

	case JTYPE:
		return fill_Jtype(instr);
    default:
        assert(0);
    }
}

enum INSTRFORMAT deduce_format(uint8_t opcode)
{
    switch (opcode)
    {
    case 0:
        return RTYPE;
    case 2:
    case 3:
        return JTYPE;
    default:
        return ITYPE;
    }
}

Instruction fill_Rtype(uint32_t instr)
{
    return (Instruction) {
        .opcode         = subword(instr, 31, 26),
        .reg_src        = subword(instr, 25, 21),
        .reg_tgt        = subword(instr, 20, 16),
        .reg_dst        = subword(instr, 15, 11),
        .shamt          = subword(instr, 10, 6),
        .funct          = subword(instr, 5, 0),
        .immed          = 0,
        .addr_tgt       = 0,
        .instr_format   = RTYPE
    };
}

Instruction fill_Itype(uint32_t instr)
{
    return (Instruction) {
        .opcode         = subword(instr, 31, 26),
        .reg_src        = subword(instr, 25, 21),
        .reg_tgt        = subword(instr, 20, 16),
        .reg_dst        = 0,
        .shamt          = 0,
        .funct          = 0,
        .immed          = subword(instr, 15, 0),
        .addr_tgt       = 0,
        .instr_format   = ITYPE
    };
}

Instruction fill_Jtype(uint32_t instr)
{
    return (Instruction) {
        .opcode         = subword(instr, 31, 26),
        .reg_src        = 0,
        .reg_tgt        = 0,
        .reg_dst        = 0,
        .shamt          = 0,
        .funct          = 0,
        .immed          = 0,
        .addr_tgt       = subword(instr, 25, 0),
        .instr_format   = ITYPE
    };
}