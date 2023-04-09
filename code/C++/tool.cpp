#include <iostream>

int test()
{
    return 1;
}

void Log(const char* message)
{
    std::cout << "return void ..." << message << "test" << std::endl;
    test();
}