#ifndef FUNC_TABLE_H
#define FUNC_TABLE_H

#include <stdint.h>

#include "instruction.h"
#include "memory.h"

#define R_OFFSET 0x40

typedef uint8_t (*mips_func)(Instruction, Memory *);

static mips_func func_table[128];

void init_func_table();
mips_func get_func(Instruction);

#endif