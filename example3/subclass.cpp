#include "subclass.h"

SubClass::SubClass(int aNum, std::string c, std::string m) : SuperClass(aNum, c) {
//                                                         ^ Super class call
    secondString = m;
}

int SubClass::subtract(int aNum) {
    // num is private :(
    //return num - aNum;
    // If only there was a better way
    return sum(0) - aNum;
}

int SubClass::subtract2(int aNum) {
    // num2 is protected :)
    return num2 - aNum;
}
