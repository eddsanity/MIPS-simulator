#include <assert.h>
#include <stdio.h>

#include "func_table.h"

void test_func_table()
{
    init_func_table();
    Memory *mem;
    // add instruction
    Instruction instr1 = parse_instr(0x014b4020);
    mips_func func1 = get_func(instr1);
    assert(func1(instr1, mem) == 1);
    // addi instruction
    Instruction instr2 = parse_instr(0x20080014);
    mips_func func2 = get_func(instr2);
    assert(func2(instr2, mem) == 2);
    // j instruction
    Instruction instr3 = parse_instr(0x08100000);
    mips_func func3 = get_func(instr3);
    assert(func3(instr2, mem) == 3);

    return;
}