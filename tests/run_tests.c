#include "test_utils.h"

// declare used tests
void test_memory();
void test_instruction();
void test_func_table();
void test_reg_file();

int main()
{
    test(test_memory, "Memory");
    test(test_instruction, "Instruction");
    test(test_func_table, "Function Table");
    test(test_reg_file, "Register File");
    return 0;
}