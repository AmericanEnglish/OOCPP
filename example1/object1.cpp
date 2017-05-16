// The object must include its own header file
#include "object1.h"
#include <iostream>

// A regular funtion
int addOne(int num) {
    return num + 1;
}
//  The object
adder::adder() {
}
int adder::addOne(int num) {
    return num + 1;
}

int main() {
    std::cout << "Begin" << std::endl;
    int example = 1;
    std::cout << "Function: " << addOne(example) << std::endl;
    // Prints 2
    adder obj = adder();
    std::cout << "Object: " << obj.addOne(example) << std::endl;
    // Prints 2
}
