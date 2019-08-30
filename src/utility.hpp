#ifndef UTILITY_H
#define UTILITY_H

#include <cstdint>

enum INSTRFORMAT { RTYPE, ITYPE, JTYPE };
enum INSTRTOKEN  { ADD, ADDI, ADDIU, ADDU, SUB, SUBU, DIV, DIVU, MULT, MULTU,
                   LB, LW, LUI, SB, SW,
	               AND, ANDI, OR, ORI, XOR, XORI, SLL, SRL,
	               SLT, SLTI,
                   MFLO, MFHI, NOOP, SYSCALL };

uint32_t subword(uint32_t, uint8_t, uint8_t);
uint32_t signExtend8bit(uint8_t);
uint32_t signExtend16bit(uint16_t);

#endif