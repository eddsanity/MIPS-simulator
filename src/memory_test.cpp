#include <cassert>
#include "memory.hpp"

int main()
{
    Memory mem(1024);
    mem.writew(4*20, (uint32_t)0x12345678);

    assert(mem.readw(4*20) == 0x12345678);
    
    assert(mem.readh(4*20) == 0x1234);
    assert(mem.readh(4*20+2) == 0x5678);

    assert(mem.readb(4*20) == 0x12);
    assert(mem.readb(4*20+1) == 0x34);
    assert(mem.readb(4*20+2) == 0x56);
    assert(mem.readb(4*20+3) == 0x78);
    
    mem.writeh(4*20, 0x6969);
    assert(mem.readh(4*20) == 0x6969);
    assert(mem.readh(4*20+2) == 0x5678);
    mem.writeh(4*20+2, 0x6999);
    assert(mem.readh(4*20) == 0x6969);
    assert(mem.readh(4*20+2) == 0x6999);
    assert(mem.readw(4*20) == 0x69696999);

    mem.writeb(4*20, 0x69);
    mem.writeb(4*20 + 1, 0x96);
    mem.writeb(4*20 + 3, 0x11);
    assert(mem.readw(4*20) == 0x69966911);

    return 0;
}