#include "i_functions.hpp"

uint8_t ADDI (Instruction instr, Memory& mem, regFile& reg)
{
  int32_t regSrcVal = reg.getReg(instr.m_regSrc);
  reg.setReg(instr.m_regTgt, regSrcVal + (int32_t)instr.m_immed);

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
      reg.setPC(tPC + (int32_t)instr.m_immed * 4);
    }

  return 1;
}

uint8_t BGTZ (Instruction instr, Memory& mem, regFile& reg)
{
  int32_t regSrcVal = reg.getReg(instr.m_regSrc);
  if(regSrcVal > 0)
    {
      uint32_t tPC = reg.getPC();
      reg.setPC(tPC + (int32_t)instr.m_immed * 4);
    }

  return 1;
}

uint8_t BLEZ (Instruction instr, Memory& mem, regFile& reg)
{
  int32_t regSrcVal = reg.getReg(instr.m_regSrc);
  if(regSrcVal <= 0)
    {
      uint32_t tPC = reg.getPC();
      reg.setPC(tPC + (int32_t)instr.m_immed * 4);
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
	  reg.setPC(tPC + (int32_t)instr.m_immed * 4);
	}
    }
  else if(instr.m_regTgt == 1) // BGEZ
    {
      if(regSrcVal >= 0)
	{
	  uint32_t tPC = reg.getPC();
	  reg.setPC(tPC + (int32_t)instr.m_immed * 4);
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
      reg.setPC(tPC + (int32_t)instr.m_immed * 4);
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
  int32_t regSrcVal = reg.getReg(instr.m_regSrc);
  uint32_t addr = regSrcVal + signExtend16bit(instr.m_immed);
  reg.setReg(instr.m_regTgt, signExtend8bit(mem.readb(addr)));
  
  return 1;
}

uint8_t LBU (Instruction instr, Memory& mem, regFile& reg)
{
  return 0;
}

uint8_t LH (Instruction instr, Memory& mem, regFile& reg)
{
  int32_t regSrcVal = reg.getReg(instr.m_regSrc);
  uint32_t addr = regSrcVal + signExtend16bit(instr.m_immed);
  if(addr % 2 == 0)
      reg.setReg(instr.m_regTgt, signExtend16bit(mem.readh(addr)));
  
  return 1;
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
  int32_t regSrcVal = reg.getReg(instr.m_regSrc);
  uint32_t addr = regSrcVal + signExtend16bit(instr.m_immed);
  if(addr % 4 == 0)
      reg.setReg(instr.m_regTgt, mem.readw(addr));
  return 1;
}

uint8_t SB (Instruction instr, Memory& mem, regFile& reg)
{
  int32_t regSrcVal = reg.getReg(instr.m_regSrc);
  int32_t regTgtVal = reg.getReg(instr.m_regTgt);
  uint32_t addr = regSrcVal + signExtend16bit(instr.m_immed);
  mem.writeb(addr, subword(regTgtVal, 7, 0));
  
  return 1;
}

uint8_t SH (Instruction instr, Memory& mem, regFile& reg)
{
  int32_t regSrcVal = reg.getReg(instr.m_regSrc);
  int32_t regTgtVal = reg.getReg(instr.m_regTgt);
  uint32_t addr = regSrcVal + signExtend16bit(instr.m_immed);
  if(addr % 2 == 0)
      mem.writeh(addr, subword(regTgtVal, 15, 0));
	     
  return 1;
}

uint8_t SW (Instruction instr, Memory& mem, regFile& reg)
{
  int32_t regSrcVal = reg.getReg(instr.m_regSrc);
  int32_t regTgtVal = reg.getReg(instr.m_regTgt);
  uint32_t addr = regSrcVal + signExtend16bit(instr.m_immed);
  if(addr % 4 == 0)
      mem.writew(addr, regTgtVal);
  
  return 1;
}
