#ifndef I_FUNCS_H
#define I_FUN_OFFSETCS_H

#include "instruction.h"
#include "memory.h"

#define ADDI_OFFSET     0x08
#define ADDIU_OFFSET    0x09
#define ANDI_OFFSET     0x0C
#define ORI_OFFSET      0x0D
#define XORI_OFFSET     0x0E
#define BEQ_OFFSET      0x04
#define BGTZ_OFFSET     0x07
#define BLEZ_OFFSET     0x06
#define BZ_OFFSET       0x01
#define BNE_OFFSET      0x05
#define SLTI_OFFSET     0x0A
#define SLTIU_OFFSET    0x0B
#define LB_OFFSET       0x20
#define LBU_OFFSET      0x24
#define LH_OFFSET       0x21
#define LHU_OFFSET      0x25
#define LUI_OFFSET      0x0F
#define LW_OFFSET       0x23
#define SB_OFFSET       0x28
#define SH_OFFSET       0x29
#define SW_OFFSET       0x2B

uint8_t ADDI (Instruction, Memory*);      // 0x08
uint8_t ADDIU(Instruction, Memory*);      // 0x09
uint8_t ANDI (Instruction, Memory*);      // 0x0C
uint8_t ORI  (Instruction, Memory*);      // 0x0D
uint8_t XORI (Instruction, Memory*);      // 0x0E
uint8_t BEQ  (Instruction, Memory*);      // 0x04
uint8_t BGTZ (Instruction, Memory*);      // 0x07, rt = $0
uint8_t BLEZ (Instruction, Memory*);      // 0x06, rt = $0
uint8_t BZ   (Instruction, Memory*);      // 0x01, rt = $0 or rt = $1
uint8_t BNE  (Instruction, Memory*);      // 0x05
uint8_t SLTI (Instruction, Memory*);      // 0x0A
uint8_t SLTIU(Instruction, Memory*);      // 0x0B
uint8_t LB   (Instruction, Memory*);      // 0x20
uint8_t LBU  (Instruction, Memory*);      // 0x24
uint8_t LH   (Instruction, Memory*);      // 0x21
uint8_t LHU  (Instruction, Memory*);      // 0x25
uint8_t LUI  (Instruction, Memory*);      // 0x0F
uint8_t LW   (Instruction, Memory*);      // 0x23
uint8_t SB   (Instruction, Memory*);      // 0x28
uint8_t SH   (Instruction, Memory*);      // 0x29
uint8_t SW   (Instruction, Memory*);      // 0x2B


#endif
