#include "i_functions.hpp"

uint8_t ADDI (Instruction instr, Memory& mem, regFile& reg)
{
  int32_t regSrcVal = reg.getReg(instr.m_regSrc);
  reg.setReg(instr.m_regTgt, regSrcVal + instr.m_immed);

  return 1;
}

uint8_t ADDIU (Instruction instr, Memory& mem, regFile& reg)
{
  return 0;
}

uint8_t ANDI (Instruction instr, Memory& mem, regFile& reg)
{
  int32_t regSrcVal = reg.getReg(instr.m_regSrc);
  reg.setReg(instr.m_regTgt, regSrcVal & (int32_t)instr.m_immed);

  return 1;
}

uint8_t ORI (Instruction instr, Memory& mem, regFile& reg)
{
  int32_t regSrcVal = reg.getReg(instr.m_regSrc);
  reg.setReg(instr.m_regTgt, regSrcVal | (int32_t)instr.m_immed);

  return 1;
}

uint8_t XORI (Instruction instr, Memory& mem, regFile& reg)
{
  int32_t regSrcVal = reg.getReg(instr.m_regSrc);
  reg.setReg(instr.m_regTgt, ~regSrcVal & ~instr.m_immed);

  return 1;
}

uint8_t BEQ (Instruction instr, Memory& mem, regFile& reg)
{
  int32_t regSrcVal = reg.getReg(instr.m_regSrc);
  int32_t regTgtVal = reg.getReg(instr.m_regTgt);
  if(regSrcVal == regTgtVal)
    {
      uint32_t tPC = reg.getPC();
      reg.setPC(tPC + instr.m_immed * 4);
    }

  return 1;
}

uint8_t BGTZ (Instruction instr, Memory& mem, regFile& reg)
{
  int32_t regSrcVal = reg.getReg(instr.m_regSrc);
  if(regSrcVal > 0)
    {
      uint32_t tPC = reg.getPC();
      reg.setPC(tPC + instr.m_immed * 4);
    }

  return 1;
}

uint8_t BLEZ (Instruction instr, Memory& mem, regFile& reg)
{
  int32_t regSrcVal = reg.getReg(instr.m_regSrc);
  if(regSrcVal <= 0)
    {
      uint32_t tPC = reg.getPC();
      reg.setPC(tPC + instr.m_immed * 4);
    }

  return 1;
}

uint8_t BZ (Instruction instr, Memory& mem, regFile& reg)
{
  int32_t regSrcVal = reg.getReg(instr.m_regSrc);
  if(instr.m_regTgt == 0)      // BLTZ
    {
      if(regSrcVal < 0)
	{
	  uint32_t tPC = reg.getPC();
	  reg.setPC(tPC + instr.m_immed * 4);
	}
    }
  else if(instr.m_regTgt == 1) // BGEZ
    {
      if(regSrcVal >= 0)
	{
	  uint32_t tPC = reg.getPC();
	  reg.setPC(tPC + instr.m_immed * 4);
	}
    }

  return 1;
}

uint8_t BNE (Instruction instr, Memory& mem, regFile& reg)
{
  int32_t regSrcVal = reg.getReg(instr.m_regSrc);
  int32_t regTgtVal = reg.getReg(instr.m_regTgt);
  if(regSrcVal != regTgtVal)
    {
      uint32_t tPC = reg.getPC();
      reg.setPC(tPC + instr.m_immed * 4);
    }

  return 1;
}

uint8_t SLTI (Instruction instr, Memory& mem, regFile& reg)
{
  int32_t regSrcVal = reg.getReg(instr.m_regSrc);
  if(regSrcVal < (int32_t)instr.m_immed)
    reg.setReg(instr.m_regTgt, 1);

  return 1;
}

uint8_t SLTIU (Instruction instr, Memory& mem, regFile& reg)
{
  int32_t regSrcVal = reg.getReg(instr.m_regSrc);
  if(regSrcVal < instr.m_immed)
    reg.setReg(instr.m_regTgt, 1);

  return 1;
}

uint8_t LB (Instruction instr, Memory& mem, regFile& reg)
{
  return 0;
}

uint8_t LBU (Instruction instr, Memory& mem, regFile& reg)
{
  return 0;
}

uint8_t LH (Instruction instr, Memory& mem, regFile& reg)
{
  return 0;
}

uint8_t LHU (Instruction instr, Memory& mem, regFile& reg)
{
  return 0;
}

uint8_t LUI (Instruction instr, Memory& mem, regFile& reg)
{
  return 0;
}

uint8_t LW (Instruction instr, Memory& mem, regFile& reg)
{
  return 0;
}

uint8_t SB (Instruction instr, Memory& mem, regFile& reg)
{
  return 0;
}

uint8_t SH (Instruction instr, Memory& mem, regFile& reg)
{
  return 0;
}

uint8_t SW (Instruction instr, Memory& mem, regFile& reg)
{
  return 0;
}
