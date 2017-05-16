// CPP File
#include <iostream>
#include <string>
#include "object2.h"

myInteger::myInteger(int aNum, std::string message) {
    num = aNum;
    msg = message;
    
}

void myInteger::print() {
    std::cout << msg << mySqrt() << std::endl;
}

void myInteger::setNum(int newNum) {
    num = newNum;
}

// This can only be used by the object itself
int myInteger::mySqrt() {
    return (int) sqrt((double) num);
}

int main(int argc, char **argv) {
    // No vars given
    myInteger obj1 = myInteger();
    // One var given
    myInteger obj2 = myInteger(144);
    // Both vars given
    myInteger obj3 = myInteger (169, "sqrt(13) =");

    obj1.print();
    obj2.print();
    obj3.print();
}
