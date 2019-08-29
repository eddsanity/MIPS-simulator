#ifndef REGFILE_H
#define REGFILE_H

#include <cstdint>
#include <cassert>

class regFile
{
public:
	regFile();

	void setReg(uint8_t, int32_t);
	int32_t getReg(uint8_t) const;

	int32_t getHI() const;
	int32_t getLO() const;
	uint32_t getPC() const;

	void setHI(int32_t);
	void setLO(int32_t);
	void setPC(uint32_t);

private:
	// special purpose
	int32_t m_HI;
	int32_t m_LO;
	uint32_t m_PC;

	// general purpose
	uint8_t m_zero = 0x00;
	int32_t m_reg[31];
	/*	
		$1      = $at           $2,$3   = $v0,$v1
		$4-$7   = $a0-$a3       $8-$15  = $t0-$t7
		$16-$23 = $s0-$s7       $24,$25 = $t8,$t9
		$26,$27 = $k0,$k1       $28     = $gp
		$29     = $sp           $30     = $fp
		$31     = $ra
	*/
};


#endif