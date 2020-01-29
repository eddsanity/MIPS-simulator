#ifndef J_FUNCS_H
#define J_FUNCS_H

#include "instruction.h"
#include "memory.h"

#define J_OFFSET    0x02
#define JAL_OFFSET  0x03

uint8_t J  (Instruction, Memory*);      // 0x02
uint8_t JAL(Instruction, Memory*);      // 0x03

#endif