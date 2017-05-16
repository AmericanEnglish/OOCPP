#include <iostream>
#include <string>

class SuperClass {
    public:
        // Constructor
        SuperClass(int aNum, int aNum2, std::string aC);
        SuperClass(int aNum = 0, std::string aC = "a");

        // Public Method
        void print();
        void setNum(int aNum);
        int sum(int aNum);
    protected:
        int num2;
    private:
        int superSum(int aNum);
        // Private Variables
        int num;
        std::string c;
};
