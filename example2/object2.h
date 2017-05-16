// Header
#include <iostream>
#include <string>

class myInteger {
    public:
        // Constructor
        myInteger(int aNum = 0, std::string message = "");
        // Public Variables
        std::string msg;
        // Public Methods
        void print();
        void setNum(int newNum);
    private:
        // Private Variables
        int num;
        // Private Methods
        int mySqrt();
};
