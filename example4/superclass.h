#pragma once
class SuperClass {
    public:
        // Constructor
        SuperClass(int aNum1 = 0, int aNum2 = 0);
        
        // Methods
        int sum(int aNum);
    protected:
        //int internalSum();
        virtual int internalSum();
        int num1, num2;
};
