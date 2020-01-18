#ifndef TEST_UTILS_H
#define TEST_UTILS_H

#include <iostream>
#include <functional>

typedef std::function<void()> TestFunc;

void test(TestFunc testFunc, std::string testName)
{
    std::cout << "Testing " << testName << std::endl;
    testFunc();
    std::cout << testName << " passed all tests successfully" << std::endl;
}

#endif