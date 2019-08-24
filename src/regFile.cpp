#include "regFile.hpp"

regFile::regFile()
{
	for (auto i : m_reg)
		m_reg[i] = 0;
	m_HI = 0x00000000;
	m_LO = 0x00000000;
	m_PC = 0x00000000;
}

void regFile::setReg(uint8_t idx, int32_t val)
{
	assert(idx <= 31);
	assert(idx > 0);
	m_reg[idx] = val;
}

int32_t regFile::getReg(uint8_t idx) const
{
	assert(idx <= 31);
	assert(idx > 0);
	return m_reg[idx];
}

int32_t regFile::getHI() const
{
	return m_HI;
}

int32_t regFile::getLO() const
{
	return m_LO;
}

uint32_t regFile::getPC() const
{
	return m_PC;
}

void regFile::setHI(int32_t val)
{
	m_HI = val;
}

void regFile::setLO(int32_t val)
{
	m_LO = val;
}

void regFile::setPC(uint32_t val)
{
	m_PC = val;
}