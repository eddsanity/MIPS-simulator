#include "r_functions.hpp"

uint32_t ADD (Instruction instr, Memory& mem, regFile& reg)
{
    return 0;
}

uint32_t ADDU (Instruction instr, Memory& mem, regFile& reg)
{
	int32_t regSrcVal = reg.getReg(instr.m_regSrc);
	int32_t regTgtVal = reg.getReg(instr.m_regTgt);
	reg.setReg(instr.m_regDst, regSrcVal + regTgtVal);
    return 1;
}

uint32_t SUB (Instruction instr, Memory& mem, regFile& reg)
{
    return 0;
}

uint32_t SUBU (Instruction instr, Memory& mem, regFile& reg)
{
	uint32_t regSrcVal = reg.getReg(instr.m_regSrc);
	uint32_t regTgtVal = reg.getReg(instr.m_regTgt);
	reg.setReg(instr.m_regDst, regSrcVal - regTgtVal);
    return 1;
}

uint32_t DIV (Instruction instr, Memory& mem, regFile& reg)
{
	int32_t regSrcVal = reg.getReg(instr.m_regSrc);
	int32_t regTgtVal = reg.getReg(instr.m_regTgt);
	reg.setLO(regSrcVal / regTgtVal);
	// TODO: research more to figure out how negative values are handled in MIPS for modulo
	reg.setHI(regSrcVal % regTgtVal);
    return 1;
}

uint32_t DIVU (Instruction instr, Memory& mem, regFile& reg)
{
	uint32_t regSrcVal = reg.getReg(instr.m_regSrc);
	uint32_t regTgtVal = reg.getReg(instr.m_regTgt);
	reg.setLO(regSrcVal / regTgtVal);
	reg.setHI(regSrcVal % regTgtVal);
    return 1;
}

uint32_t MULT (Instruction instr, Memory& mem, regFile& reg)
{
	int32_t regSrcVal = reg.getReg(instr.m_regSrc);
	int32_t regTgtVal = reg.getReg(instr.m_regTgt);
	int64_t multResult = regSrcVal * regTgtVal;
	reg.setHI(subword64(multResult, 63, 32));
	reg.setLO(subword64(multResult, 31, 0));
    return 1;
}

uint32_t MULTU (Instruction instr, Memory& mem, regFile& reg)
{
	uint32_t regSrcVal = reg.getReg(instr.m_regSrc);
	uint32_t regTgtVal = reg.getReg(instr.m_regTgt);
	uint64_t multResult = regSrcVal * regTgtVal;
	reg.setHI(subword64(multResult, 63, 32));
	reg.setLO(subword64(multResult, 31, 0));
    return 1;
}

uint32_t AND (Instruction instr, Memory& mem, regFile& reg)
{
	int32_t regSrcVal = reg.getReg(instr.m_regSrc);
	int32_t regTgtVal = reg.getReg(instr.m_regTgt);
	reg.setReg(instr.m_regDst, regSrcVal & regTgtVal);
    return 1;
}

uint32_t OR (Instruction instr, Memory& mem, regFile& reg)
{
	int32_t regSrcVal = reg.getReg(instr.m_regSrc);
	int32_t regTgtVal = reg.getReg(instr.m_regTgt);
	reg.setReg(instr.m_regDst, regSrcVal | regTgtVal);
    return 1;
}

uint32_t XOR (Instruction instr, Memory& mem, regFile& reg)
{
	int32_t regSrcVal = reg.getReg(instr.m_regSrc);
	int32_t regTgtVal = reg.getReg(instr.m_regTgt);
	reg.setReg(instr.m_regDst, regSrcVal ^ regTgtVal);
    return 1;
}

uint32_t NOR (Instruction instr, Memory& mem, regFile& reg)
{
	int32_t regSrcVal = reg.getReg(instr.m_regSrc);
	int32_t regTgtVal = reg.getReg(instr.m_regTgt);
	reg.setReg(instr.m_regDst, ~regSrcVal & ~regTgtVal);
    return 1;
}

uint32_t SLL (Instruction instr, Memory& mem, regFile& reg)
{
	int32_t regTgtVal = reg.getReg(instr.m_regTgt);
	reg.setReg(instr.m_regDst, regTgtVal << instr.m_shamt);
    return 1;
}

uint32_t SRL (Instruction instr, Memory& mem, regFile& reg)
{
	int32_t regTgtVal = reg.getReg(instr.m_regTgt);
	reg.setReg(instr.m_regDst, regTgtVal >> instr.m_shamt);
    return 1;
}

uint32_t SLT (Instruction instr, Memory& mem, regFile& reg)
{
	int32_t regSrcVal = reg.getReg(instr.m_regSrc);
	int32_t regTgtVal = reg.getReg(instr.m_regTgt);
	bool flag = ((regSrcVal < regTgtVal) ? 1 : 0);
	reg.setReg(instr.m_regDst, flag);
    return 1;
}

uint32_t SLTU (Instruction instr, Memory& mem, regFile& reg)
{
	uint32_t regSrcVal = reg.getReg(instr.m_regSrc);
	uint32_t regTgtVal = reg.getReg(instr.m_regTgt);
	bool flag = ((regSrcVal < regTgtVal) ? 1 : 0);
	reg.setReg(instr.m_regDst, flag);
    return 1;
}

uint32_t MFHI (Instruction instr, Memory& mem, regFile& reg)
{
	reg.setReg(instr.m_regDst, reg.getHI());
    return 1;
}

//uint32_t MTHI (Instruction instr, Memory& mem, regFile& reg)
//{
//	
//    return 1;
//}

uint32_t MFLO (Instruction instr, Memory& mem, regFile& reg)
{
	reg.setReg(instr.m_regDst, reg.getLO());
    return 1;
}

//uint32_t MTLO (Instruction instr, Memory& mem, regFile& reg)
//{
//    return 0;
//}

uint32_t SYSCALL (Instruction instr, Memory& mem, regFile& reg)
{
    return 0;
}