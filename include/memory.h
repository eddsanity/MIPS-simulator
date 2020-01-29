#ifndef MEMORY_H
#define MEMORY_H

#include <stdint.h>

typedef struct Memory
{
	uint32_t mem_size;
	uint32_t* mem_buf;
} Memory;

Memory init_memory(uint32_t mem_size);

uint32_t readw(Memory *mem, uint32_t addr); 
uint16_t readh(Memory *mem, uint32_t addr);
uint8_t  readb(Memory *mem, uint32_t addr);

void writew(Memory *mem, uint32_t addr, uint32_t val);
void writeh(Memory *mem, uint32_t addr, uint16_t val);
void writeb(Memory *mem, uint32_t addr, uint8_t val);

#endif