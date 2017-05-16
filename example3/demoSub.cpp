#include <iostream>
#include "subclass.h"

int main(int argc, char **argv) {
    // Build Subclass
    SubClass obj1 = SubClass();
    
    // Now print it out?
    obj1.print();

    // Then Print the subtract method
    std::cout << "1.) 0 - 5 = " << obj1.subtract(5) << std::endl;
    std::cout << "2.) 0 - 5 = " << obj1.subtract2(5) << std::endl;

    // Use the sum method?
    std::cout << "0 + 5 = " << obj1.sum(5) << std::endl;
    return 0;
}
