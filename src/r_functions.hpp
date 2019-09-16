#ifndef R_FUNCS_H
#define R_FUNCS_H

#include "instruction.hpp"
#include "regFile.hpp"
#include "memory.hpp"
#include "utility.hpp"

uint32_t ADD(Instruction, Memory&, regFile&);      // 0x20
uint32_t ADDU(Instruction, Memory&, regFile&);     // 0x21
uint32_t SUB(Instruction, Memory&, regFile&);      // 0x22
uint32_t SUBU(Instruction, Memory&, regFile&);     // 0x23
uint32_t DIV(Instruction, Memory&, regFile&);      // 0x1A
uint32_t DIVU(Instruction, Memory&, regFile&);     // 0x1B
uint32_t MULT(Instruction, Memory&, regFile&);     // 0x18
uint32_t MULTU(Instruction, Memory&, regFile&);    // 0x19
uint32_t AND(Instruction, Memory&, regFile&);      // 0x24
uint32_t OR(Instruction, Memory&, regFile&);       // 0x25
uint32_t XOR(Instruction, Memory&, regFile&);      // 0x26
uint32_t NOR(Instruction, Memory&, regFile&);      // 0x27
uint32_t SLL(Instruction, Memory&, regFile&);      // 0x00
uint32_t SRL(Instruction, Memory&, regFile&);      // 0x02
uint32_t SLT(Instruction, Memory&, regFile&);      // 0x2A
uint32_t SLTU(Instruction, Memory&, regFile&);     // 0x2B
uint32_t MFHI(Instruction, Memory&, regFile&);     // 0x10
uint32_t MFLO(Instruction, Memory&, regFile&);     // 0x12
uint32_t SYSCALL(Instruction, Memory&, regFile&);  // 0x0C

#endif