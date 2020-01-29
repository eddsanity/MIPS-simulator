#include <stdint.h>
#include <stdlib.h>
#include <assert.h>

#include "memory.h"

Memory init_memory(uint32_t mem_size)
{
    uint32_t* mem_buf = (uint32_t*) malloc(mem_size * sizeof(uint32_t));
    Memory mem = {
        .mem_size = mem_size,
        .mem_buf  = mem_buf
    };
    return mem;
}

uint32_t readw(Memory* mem, uint32_t addr)
{
    uint32_t word_addr = addr >> 2;
    assert(word_addr < mem->mem_size);
    return mem->mem_buf[word_addr];
}

uint16_t readh(Memory *mem, uint32_t addr)
{
    uint32_t word_addr = addr >> 2;
    assert(word_addr < mem->mem_size);
    if(word_addr << 2 == addr)
        return mem->mem_buf[word_addr] >> 16;   // first halfword
    else
        return mem->mem_buf[word_addr];         // second halfword
}

uint8_t readb(Memory *mem, uint32_t addr)
{
    uint32_t word_addr = addr >> 2;
    assert(word_addr < mem->mem_size);
    if(word_addr << 2 == addr)
        return mem->mem_buf[word_addr] >> 24;   // first byte
    else if(word_addr << 2 == addr-1)
        return mem->mem_buf[word_addr] >> 16;   // second byte
    else if(word_addr << 2 == addr-2)
        return mem->mem_buf[word_addr] >> 8;    // third byte
    else
        return mem->mem_buf[word_addr];         // forth byte
}

void writew(Memory *mem, uint32_t addr, uint32_t val)
{
    uint32_t word_addr = addr >> 2;
    assert(word_addr < mem->mem_size);
    (mem->mem_buf[word_addr]) = val;
}

void writeh(Memory *mem, uint32_t addr, uint16_t val)
{
    uint32_t word_addr = addr >> 2;
    assert(word_addr < mem->mem_size);
    if(word_addr << 2 == addr)
    {                                       // first halfword
        (mem->mem_buf[word_addr]) &= (uint32_t)0x0000FFFF;
        (mem->mem_buf[word_addr]) |= ((uint32_t)val) << 16;
    }
    else
    {                                       // second halfword
        (mem->mem_buf[word_addr]) &= (uint32_t)0xFFFF0000;
        (mem->mem_buf[word_addr]) |= (uint32_t)val;
    }
}

void writeb(Memory *mem, uint32_t addr, uint8_t val)
{
    uint32_t word_addr = addr >> 2;
    assert(word_addr < mem->mem_size);
    if(word_addr << 2 == addr) {            // first byte
        (mem->mem_buf[word_addr]) &= (uint32_t)0x00FFFFFF;
        (mem->mem_buf[word_addr]) |= ((uint32_t)val) << 24;
    } else if(word_addr << 2 == addr-1) {   // second byte
        (mem->mem_buf[word_addr]) &= (uint32_t)0xFF00FFFF;
        (mem->mem_buf[word_addr]) |= ((uint32_t)val) << 16;
    } else if(word_addr << 2 == addr-2) {   // third byte
        (mem->mem_buf[word_addr]) &= (uint32_t)0xFFFF00FF;
        (mem->mem_buf[word_addr]) |= ((uint32_t)val) << 8;
    } else {                                // forth byte
        (mem->mem_buf[word_addr]) &= (uint32_t)0xFFFFFF00;
        (mem->mem_buf[word_addr]) |= (uint32_t)val;
    }
}