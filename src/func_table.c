#include "func_table.h"
#include "r_funcs.h"
#include "i_funcs.h"
#include "j_funcs.h"
#include "instruction.h"

void init_func_table()
{
    // R Type functions are offset by 0x40 (0x40 + funct)
    // J Type 2 and 3
    // I Type 1, 4 - 62

    // R Type initialization
    func_table[R_OFFSET + ADD_OFFSET]       = ADD;
    func_table[R_OFFSET + ADDU_OFFSET]      = ADDU;
    func_table[R_OFFSET + SUB_OFFSET]       = SUB;
    func_table[R_OFFSET + SUBU_OFFSET]      = SUBU;
    func_table[R_OFFSET + DIV_OFFSET]       = DIV;
    func_table[R_OFFSET + DIVU_OFFSET]      = DIVU;
    func_table[R_OFFSET + MULT_OFFSET]      = MULT;
    func_table[R_OFFSET + MULTU_OFFSET]     = MULTU;
    func_table[R_OFFSET + AND_OFFSET]       = AND;
    func_table[R_OFFSET + OR_OFFSET]        = OR;
    func_table[R_OFFSET + XOR_OFFSET]       = XOR;
    func_table[R_OFFSET + NOR_OFFSET]       = NOR;
    func_table[R_OFFSET + SLL_OFFSET]       = SLL;
    func_table[R_OFFSET + SRL_OFFSET]       = SRL;
    func_table[R_OFFSET + SLT_OFFSET]       = SLT;
    func_table[R_OFFSET + SLTU_OFFSET]      = SLTU;
    func_table[R_OFFSET + MFHI_OFFSET]      = MFHI;
    func_table[R_OFFSET + MFLO_OFFSET]      = MFLO;
    func_table[R_OFFSET + SYSCALL_OFFSET]   = SYSCALL;
    // I Type initialization
    func_table[ADDI_OFFSET]                 = ADDI;
    func_table[ADDIU_OFFSET]                = ADDIU;
    func_table[ANDI_OFFSET]                 = ANDI;
    func_table[ORI_OFFSET]                  = ORI;
    func_table[XORI_OFFSET]                 = XORI;
    func_table[BEQ_OFFSET]                  = BEQ;
    func_table[BZ_OFFSET]                   = BZ;
    func_table[BGTZ_OFFSET]                 = BGTZ;
    func_table[BLEZ_OFFSET]                 = BLEZ;
    func_table[BNE_OFFSET]                  = BNE;
    func_table[SLTI_OFFSET]                 = SLTI;
    func_table[SLTIU_OFFSET]                = SLTIU;
    func_table[LB_OFFSET]                   = LB;
    func_table[LBU_OFFSET]                  = LBU;
    func_table[LH_OFFSET]                   = LH;
    func_table[LHU_OFFSET]                  = LHU;
    func_table[LUI_OFFSET]                  = LUI;
    func_table[LW_OFFSET]                   = LW;
    func_table[SB_OFFSET]                   = SB;
    func_table[SH_OFFSET]                   = SH;
    func_table[SW_OFFSET]                   = SW;
    // J Type initialization
    func_table[J_OFFSET]                    = J;
    func_table[JAL_OFFSET]                  = JAL;
}

mips_func get_func(Instruction instr)
{
    if(instr.instr_format == RTYPE)
        return func_table[R_OFFSET + instr.funct];
    return func_table[instr.opcode];
}