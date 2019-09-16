#ifndef I_FUNCS_H
#define I_FUNCS_H

#include "instruction.hpp"
#include "regFile.hpp"
#include "memory.hpp"
#include "utility.hpp"

uint8_t ADDI (Instruction, Memory&, regFile&);      // 0x08
uint8_t ADDIU(Instruction, Memory&, regFile&);      // 0x09
uint8_t ANDI (Instruction, Memory&, regFile&);      // 0x0C
uint8_t ORI  (Instruction, Memory&, regFile&);      // 0x0D
uint8_t XORI (Instruction, Memory&, regFile&);      // 0x0E
uint8_t BEQ  (Instruction, Memory&, regFile&);      // 0x04
uint8_t BGEZ (Instruction, Memory&, regFile&);      // 0x01, rt = $1
uint8_t BGTZ (Instruction, Memory&, regFile&);      // 0x07, rt = $0
uint8_t BLEZ (Instruction, Memory&, regFile&);      // 0x06, rt = $0
uint8_t BLTZ (Instruction, Memory&, regFile&);      // 0x01, rt = $0
uint8_t BNE  (Instruction, Memory&, regFile&);      // 0x05
uint8_t SLTI (Instruction, Memory&, regFile&);      // 0x0A
uint8_t SLTIU(Instruction, Memory&, regFile&);      // 0x0B
uint8_t LB   (Instruction, Memory&, regFile&);      // 0x20
uint8_t LBU  (Instruction, Memory&, regFile&);      // 0x24
uint8_t LH   (Instruction, Memory&, regFile&);      // 0x21
uint8_t LHU  (Instruction, Memory&, regFile&);      // 0x25
uint8_t LUI  (Instruction, Memory&, regFile&);      // 0x0F
uint8_t LW   (Instruction, Memory&, regFile&);      // 0x23
uint8_t SB   (Instruction, Memory&, regFile&);      // 0x28
uint8_t SH   (Instruction, Memory&, regFile&);      // 0x29
uint8_t SW   (Instruction, Memory&, regFile&);      // 0x2B

#endif
