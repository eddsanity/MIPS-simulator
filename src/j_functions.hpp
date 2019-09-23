#ifndef J_FUNCS_H
#define J_FUNCS_H

#include "instruction.hpp"
#include "regFile.hpp"
#include "memory.hpp"
#include "utility.hpp"

uint8_t J  (Instruction, Memory&, regFile&);      // 0x02
uint8_t JAL(Instruction, Memory&, regFile&);      // 0x03

#endif
