#include "reg_file.h"

void write_reg(RegisterFile *reg_file, uint8_t reg_id, uint32_t val)
{
    reg_file->reg[reg_id] = val;
}

uint32_t read_reg(RegisterFile *reg_file, uint8_t reg_id)
{
    if(reg_id == REG_ZERO)
        return 0;
    else
        return reg_file->reg[reg_id];
}
