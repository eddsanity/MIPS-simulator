#ifndef TEST_UTILS_H
#define TEST_UTILS_H

#include <stdio.h>

void test(void (*test_func)(), char *test_name)
{
    printf("Testing %s\n", test_name);
    test_func();
    printf("%s passed all tests successfully\n", test_name);
}

#endif