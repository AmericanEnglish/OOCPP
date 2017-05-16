#include <iostream>
#include <string>
#include "superclass.h"

class SubClass : public SuperClass {
    //            ^ inheritance type
    public:
        // Only Constructor
        SubClass(int aNum = 0, std::string c = "a", std::string m = "Q");
        
        // Special subtract methods
        int subtract(int aNum);
        int subtract2(int aNum);

    private:
        std::string secondString;
};
