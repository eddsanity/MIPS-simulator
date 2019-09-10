#ifndef R_FUNCS_H
#define R_FUNCS_H

#include "instruction.hpp"
#include "regFile.hpp"
#include "memory.hpp"
#include "utility.hpp"

uint32_t ADD(Instruction instr, Memory& mem, regFile& reg);      // 0x20
uint32_t ADDU(Instruction instr, Memory& mem, regFile& reg);     // 0x21
uint32_t SUB(Instruction instr, Memory& mem, regFile& reg);      // 0x22
uint32_t SUBU(Instruction instr, Memory& mem, regFile& reg);     // 0x23
uint32_t DIV(Instruction instr, Memory& mem, regFile& reg);      // 0x1A
uint32_t DIVU(Instruction instr, Memory& mem, regFile& reg);     // 0x1B
uint32_t MULT(Instruction instr, Memory& mem, regFile& reg);     // 0x18
uint32_t MULTU(Instruction instr, Memory& mem, regFile& reg);    // 0x19
uint32_t AND(Instruction instr, Memory& mem, regFile& reg);      // 0x24
uint32_t OR(Instruction instr, Memory& mem, regFile& reg);       // 0x25
uint32_t XOR(Instruction instr, Memory& mem, regFile& reg);      // 0x26
uint32_t NOR(Instruction instr, Memory& mem, regFile& reg);      // 0x27
uint32_t SLL(Instruction instr, Memory& mem, regFile& reg);      // 0x00
uint32_t SRL(Instruction instr, Memory& mem, regFile& reg);      // 0x02
uint32_t SLT(Instruction instr, Memory& mem, regFile& reg);      // 0x2A
uint32_t SLTU(Instruction instr, Memory& mem, regFile& reg);     // 0x2B
uint32_t MFHI(Instruction instr, Memory& mem, regFile& reg);     // 0x10
uint32_t MTHI(Instruction instr, Memory& mem, regFile& reg);     // 0x11
uint32_t MFLO(Instruction instr, Memory& mem, regFile& reg);     // 0x12
uint32_t MTLO(Instruction instr, Memory& mem, regFile& reg);     // 0x13
uint32_t SYSCALL(Instruction instr, Memory& mem, regFile& reg);  // 0x0C

#endif