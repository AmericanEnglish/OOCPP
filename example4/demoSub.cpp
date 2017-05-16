#include "subclass.h"
#include "superclass.h"
#include <iostream>

int main() {
    // Demo The Superclass
    SuperClass obj1 = SuperClass(1, 1);
    std::cout << "1 + 1 + 3 = " << obj1.sum(3) << std::endl;

    // Demo the Subclass
    SubClass obj2 = SubClass(1, 1, 1);
    std::cout << "1 + 1 + 1 + 3 = " << obj2.sum(3) << std::endl;
    return 0;
}
