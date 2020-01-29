#include <assert.h>

#include "memory.h"

void test_memory()
{
    Memory mem = init_memory(1024);
    writew(&mem, 4*20, (uint32_t)0x12345678);

    assert(readw(&mem, 4*20) == 0x12345678);
    
    assert(readh(&mem, 4*20) == 0x1234);
    assert(readh(&mem, 4*20+2) == 0x5678);

    assert(readb(&mem, 4*20) == 0x12);
    assert(readb(&mem, 4*20+1) == 0x34);
    assert(readb(&mem, 4*20+2) == 0x56);
    assert(readb(&mem, 4*20+3) == 0x78);
    
    writeh(&mem, 4*20, 0x6969);
    assert(readh(&mem, 4*20) == 0x6969);
    assert(readh(&mem, 4*20+2) == 0x5678);

    writeh(&mem, 4*20+2, 0x6999);
    assert(readh(&mem, 4*20) == 0x6969);
    assert(readh(&mem, 4*20+2) == 0x6999);
    assert(readw(&mem, 4*20) == 0x69696999);

    writeb(&mem, 4*20, 0x69);
    writeb(&mem, 4*20 + 1, 0x96);
    writeb(&mem, 4*20 + 3, 0x11);
    assert(readw(&mem, 4*20) == 0x69966911);

    return;
}