#include <assert.h>
#include <stdio.h>

#include "instruction.h"

void test_instruction()
{
    // addi 8, 0, 20
    Instruction instr = parse_instr(0x20080014);
    assert(instr.opcode == 0b001000);
    assert(instr.reg_src == 0);
    assert(instr.reg_tgt == 8);
    assert(instr.immed == 20);
    
    return;
}