#include "subclass.h"

SubClass::SubClass(int aNum1, int aNum2, int aNum3) : SuperClass(aNum1, aNum2) {
    num3 = aNum3;
}

int SubClass::internalSum() {
    return num1 + num2 + num3;
}
