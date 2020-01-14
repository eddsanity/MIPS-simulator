#ifndef FUNC_TABLE_H
#define FUNC_TABLE_H

#include <functional>

#include "utility.hpp"
#include "regFile.hpp"
#include "memory.hpp"
#include "instruction.hpp"

#include "r_functions.hpp"
#include "i_functions.hpp"

typedef std::function<uint32_t(Instruction, Memory&, regFile&)> MIPSFunc;
const uint8_t R_OFFSET = 0x40;

class FunctionTable
{
public:
    FunctionTable()
    {
        // R Type functions are offset by 0x40 (0x40 + funct)
        // J Type 2 and 3
        // I Type 1, 4 - 62

        // R Type initialization
        functionTable[R_OFFSET + 0x20] = ADD;
        functionTable[R_OFFSET + 0x21] = ADDU;
        functionTable[R_OFFSET + 0x22] = SUB;
        functionTable[R_OFFSET + 0x23] = SUBU;
        functionTable[R_OFFSET + 0x1A] = DIV;
        functionTable[R_OFFSET + 0x1B] = DIVU;
        functionTable[R_OFFSET + 0x18] = MULT;
        functionTable[R_OFFSET + 0x19] = MULTU;
        functionTable[R_OFFSET + 0x24] = AND;
        functionTable[R_OFFSET + 0x25] = OR;
        functionTable[R_OFFSET + 0x26] = XOR;
        functionTable[R_OFFSET + 0x27] = NOR;
        functionTable[R_OFFSET + 0x00] = SLL;
        functionTable[R_OFFSET + 0x02] = SRL;
        functionTable[R_OFFSET + 0x2A] = SLT;
        functionTable[R_OFFSET + 0x2B] = SLTU;
        functionTable[R_OFFSET + 0x10] = MFHI;
        functionTable[R_OFFSET + 0x12] = MFLO;
        functionTable[R_OFFSET + 0x0C] = SYSCALL;
        // I Type initialization
        functionTable[0x08] = ADDI;
	    functionTable[0x09] = ADDIU;
	    functionTable[0x0C] = ANDI;
	    functionTable[0x0D] = ORI;
	    functionTable[0x0E] = XORI;
	    functionTable[0x04] = BEQ;
	    functionTable[0x01] = BZ;
	    functionTable[0x07] = BGTZ;
	    functionTable[0x06] = BLEZ;
	    functionTable[0x05] = BNE;
	    functionTable[0x0A] = SLTI;
	    functionTable[0x0B] = SLTIU;
	    functionTable[0x20] = LB;
	    functionTable[0x24] = LBU;
	    functionTable[0x21] = LH;
	    functionTable[0x25] = LHU;
	    functionTable[0x0F] = LUI;
	    functionTable[0x23] = LW;
	    functionTable[0x28] = SB;
	    functionTable[0x29] = SH;
	    functionTable[0x2B] = SW;
        // J Type initialization
        // TODO
    }
    MIPSFunc getFunc(Instruction instr)
    {
        if(instr.m_instrFormat == INSTRFORMAT::RTYPE)
            return functionTable[R_OFFSET + instr.m_funct];
        return functionTable[instr.m_opcode];
    }
private:
    MIPSFunc functionTable[128];
};

#endif
