#include <iostream>
#include <string>
#include "superclass.h"

// First Constructor
SuperClass::SuperClass(int aNum, int aNum2, std::string aC) {
    num2 = aNum;
    num = aNum;
    c = aC;
}

// Second Constructor
SuperClass::SuperClass(int aNum, std::string aC) {
    num2 = aNum;
    num = aNum;
    c = aC;
}

// Public
void SuperClass::print() {
    std::cout << c << num << std::endl;
}

// Public
// Sets a private variable using a public method
void SuperClass::setNum(int aNum) {
    num = aNum;
}

// Public
int SuperClass::sum(int aNum) {
    // Public method accessing a private method
    return superSum(aNum);
}

// Private
int SuperClass::superSum(int aNum) {
    return num + aNum;
}


