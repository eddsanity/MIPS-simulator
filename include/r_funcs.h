#ifndef R_FUNCS_H
#define R_FUNCS_H

#include "instruction.h"
#include "memory.h"

#define ADD_OFFSET      0x20
#define ADDU_OFFSET     0x21
#define SUB_OFFSET      0x22
#define SUBU_OFFSET     0x23
#define DIV_OFFSET      0x1A
#define DIVU_OFFSET     0x1B
#define MULT_OFFSET     0x18
#define MULTU_OFFSET    0x19
#define AND_OFFSET      0x24
#define OR_OFFSET       0x25
#define XOR_OFFSET      0x26
#define NOR_OFFSET      0x27
#define SLL_OFFSET      0x00
#define SRL_OFFSET      0x02
#define SLT_OFFSET      0x2A
#define SLTU_OFFSET     0x2B
#define MFHI_OFFSET     0x10
#define MFLO_OFFSET     0x12
#define SYSCALL_OFFSET  0x0C

uint8_t ADD    (Instruction, Memory*);      // 0x20
uint8_t ADDU   (Instruction, Memory*);      // 0x21
uint8_t SUB    (Instruction, Memory*);      // 0x22
uint8_t SUBU   (Instruction, Memory*);      // 0x23
uint8_t DIV    (Instruction, Memory*);      // 0x1A
uint8_t DIVU   (Instruction, Memory*);      // 0x1B
uint8_t MULT   (Instruction, Memory*);      // 0x18
uint8_t MULTU  (Instruction, Memory*);      // 0x19
uint8_t AND    (Instruction, Memory*);      // 0x24
uint8_t OR     (Instruction, Memory*);      // 0x25
uint8_t XOR    (Instruction, Memory*);      // 0x26
uint8_t NOR    (Instruction, Memory*);      // 0x27
uint8_t SLL    (Instruction, Memory*);      // 0x00
uint8_t SRL    (Instruction, Memory*);      // 0x02
uint8_t SLT    (Instruction, Memory*);      // 0x2A
uint8_t SLTU   (Instruction, Memory*);      // 0x2B
uint8_t MFHI   (Instruction, Memory*);      // 0x10
uint8_t MFLO   (Instruction, Memory*);      // 0x12
uint8_t SYSCALL(Instruction, Memory*);      // 0x0C

#endif
