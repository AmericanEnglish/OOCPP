#include "superclass.h"

SuperClass::SuperClass(int aNum1, int aNum2) {
    num1 = aNum1;
    num2 = aNum2;
}

// Public
int SuperClass::sum(int aNum) {
    return internalSum() + aNum;
}

// Protected
int SuperClass::internalSum() {
    return num1 + num2;
}
