#include "memory.hpp"

Memory::Memory(uint32_t size)
{
    m_memSize = size;
    for (size_t i = 0; i < m_memSize; ++i)
        m_memBuf.push_back(0);
}

uint32_t Memory::readw(uint32_t addr)
{
    uint32_t wordAddr = addr>>2;
    assert(wordAddr < m_memSize);
    return m_memBuf[wordAddr];
}

uint16_t Memory::readh(uint32_t addr)
{
    uint32_t wordAddr = addr>>2;
    assert(wordAddr < m_memSize);
    if(wordAddr<<2 == addr)
        return m_memBuf[wordAddr]>>16;    // first halfword
    else
        return m_memBuf[wordAddr];        // second halfword
}

uint8_t Memory::readb(uint32_t addr)
{
    uint32_t wordAddr = addr>>2;
    assert(wordAddr < m_memSize);
    if(wordAddr<<2 == addr)
        return m_memBuf[wordAddr]>>24;    // first byte
    else if(wordAddr<<2 == addr-1)
        return m_memBuf[wordAddr]>>16;    // second byte
    else if(wordAddr<<2 == addr-2)
        return m_memBuf[wordAddr]>>8;     // third byte
    else
        return m_memBuf[wordAddr];        // forth byte
}

void Memory::writew(uint32_t addr, uint32_t val)
{
    uint32_t wordAddr = addr>>2;
    assert(wordAddr < m_memSize);
    m_memBuf[wordAddr] = val;
}

void Memory::writeh(uint32_t addr, uint16_t val)
{
    uint32_t wordAddr = addr>>2;
    assert(wordAddr < m_memSize);
    if(wordAddr<<2 == addr) {          // first halfword
        m_memBuf[wordAddr] &= (uint32_t)0x0000FFFF;
        m_memBuf[wordAddr] |= ((uint32_t)val) << 16;
    } else {                            // second halfword
        m_memBuf[wordAddr] &= (uint32_t)0xFFFF0000;
        m_memBuf[wordAddr] |= ((uint32_t)val);
    }
}

void Memory::writeb(uint32_t addr, uint8_t val)
{
    uint32_t wordAddr = addr>>2;
    assert(wordAddr < m_memSize);
    if(wordAddr<<2 == addr) {          // first byte
        m_memBuf[wordAddr] &= (uint32_t)0x00FFFFFF;
        m_memBuf[wordAddr] |= ((uint32_t)val) << 24;
    } else if(wordAddr<<2 == addr-1) { // second byte
        m_memBuf[wordAddr] &= (uint32_t)0xFF00FFFF;
        m_memBuf[wordAddr] |= ((uint32_t)val) << 16;
    } else if(wordAddr<<2 == addr-2) { // third byte
        m_memBuf[wordAddr] &= (uint32_t)0xFFFF00FF;
        m_memBuf[wordAddr] |= ((uint32_t)val) << 8;
    } else {                            // forth byte
        m_memBuf[wordAddr] &= (uint32_t)0xFFFFFF00;
        m_memBuf[wordAddr] |= ((uint32_t)val);
    }
}
