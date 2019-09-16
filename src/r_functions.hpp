#ifndef R_FUNCS_H
#define R_FUNCS_H

#include "instruction.hpp"
#include "regFile.hpp"
#include "memory.hpp"
#include "utility.hpp"

uint8_t ADD    (Instruction, Memory&, regFile&);      // 0x20
uint8_t ADDU   (Instruction, Memory&, regFile&);      // 0x21
uint8_t SUB    (Instruction, Memory&, regFile&);      // 0x22
uint8_t SUBU   (Instruction, Memory&, regFile&);      // 0x23
uint8_t DIV    (Instruction, Memory&, regFile&);      // 0x1A
uint8_t DIVU   (Instruction, Memory&, regFile&);      // 0x1B
uint8_t MULT   (Instruction, Memory&, regFile&);      // 0x18
uint8_t MULTU  (Instruction, Memory&, regFile&);      // 0x19
uint8_t AND    (Instruction, Memory&, regFile&);      // 0x24
uint8_t OR     (Instruction, Memory&, regFile&);      // 0x25
uint8_t XOR    (Instruction, Memory&, regFile&);      // 0x26
uint8_t NOR    (Instruction, Memory&, regFile&);      // 0x27
uint8_t SLL    (Instruction, Memory&, regFile&);      // 0x00
uint8_t SRL    (Instruction, Memory&, regFile&);      // 0x02
uint8_t SLT    (Instruction, Memory&, regFile&);      // 0x2A
uint8_t SLTU   (Instruction, Memory&, regFile&);      // 0x2B
uint8_t MFHI   (Instruction, Memory&, regFile&);      // 0x10
uint8_t MFLO   (Instruction, Memory&, regFile&);      // 0x12
uint8_t SYSCALL(Instruction, Memory&, regFile&);   // 0x0C

#endif
