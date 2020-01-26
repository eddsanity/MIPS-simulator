#include "test_utils.h"

// declare used tests
void test_memory();
void test_instruction();

int main()
{
    test(test_memory, "Memory");
    test(test_instruction, "Instruction");
    return 0;
}