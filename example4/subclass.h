#pragma once
#include "superclass.h"

class SubClass : public SuperClass {
    public:
        // Constructor
        SubClass(int aNum1 = 0, int aNum2 = 0, int aNum3 = 0);

    protected:
        // New
        int internalSum() override;
        // Old
        //int internalSum();
        int num3;
};
