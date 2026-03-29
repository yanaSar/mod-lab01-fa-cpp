#include <iostream>
#include "fun.h"

int main() {
    const char *test1 = "Hello world 123 tes3 abc42 def";
    std::cout << "Test 1: " << faStr1(test1) << std::endl;

    const char *test2 = "Hello world test Xyz123 Good";
    std::cout << "Test 2: " << faStr2(test2) << std::endl;

    const char *test3 = "Hello world from C++ programming";
    std::cout << "Test 3: " << faStr3(test3) << std::endl;

    return 0;
}