#include <assert.h>

#include "reg_file.h"

void test_reg_file()
{
    RegisterFile reg_file;
    
    write_reg(&reg_file, REG_T0, 969);
    assert(read_reg(&reg_file, REG_T0) == 969);
    
    assert(read_reg(&reg_file, REG_ZERO) == 0);
    write_reg(&reg_file, REG_ZERO, 969);
    assert(read_reg(&reg_file, REG_ZERO) == 0);
    return;
}