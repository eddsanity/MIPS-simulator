#include "test_utils.h"

// declare used tests
void test_memory();
void test_instruction();
void test_func_table();

int main()
{
    test(test_memory, "Memory");
    test(test_instruction, "Instruction");
    test(test_func_table, "Function Table");
    return 0;
}