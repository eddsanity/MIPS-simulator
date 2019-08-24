#ifndef MEMORY_H
#define MEMORY_H

#include <cstdint>
#include <cassert>
#include <vector>

class Memory
{
public:
	Memory(uint32_t size);

	uint32_t readw(uint32_t addr); 
	uint16_t readh(uint32_t addr);
	uint8_t  readb(uint32_t addr);

	void writew(uint32_t addr, uint32_t val);
	void writeh(uint32_t addr, uint16_t val);
	void writeb(uint32_t addr, uint8_t val);

private:
	uint32_t m_memSize;
	std::vector<uint32_t> m_memBuf;
};

#endif