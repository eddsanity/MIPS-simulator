#include <iostream>
#include <functional>

typedef std::function<void()> TestFunc;

void test(TestFunc testFunc, std::string testName)
{
	std::cout << "Testing " << testName << std::endl;
	testFunc();
	std::cout << testName << " passed all tests" << std::endl;
}

void test_memory();

int main()
{
    test(test_memory, "Memory");
    return 0;
}