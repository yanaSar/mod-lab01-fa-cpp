#include <iostream>
#include "fun.h"

int main() {
    //for #1
    const char *test1 = "Hello world 123 tes3 abc42 def";
    std::cout << "Test 1: " << faStr1(test1) << std::endl; //3

    //for #2
    const char *test2 = "Hello world test Xyz123 Good";
    std::cout << "Test 2: " << faStr2(test2) << std::endl; //2

    //for #3
    const char *test3 = "Hello world from C++ programming";
    std::cout << "Test 3: " << faStr3(test3) << std::endl; //5

    return 0;
}
