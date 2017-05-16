#include "superclass.h"
#include <string>

int main(int argc, char **argv) {
    // Generate two SuperClass objects
    SuperClass obj1 = SuperClass();
    SuperClass obj2 = SuperClass(1, 2, "A");
    obj1.print();
    obj2.print();

    // Print two sums
    std::cout << "Sums:" << std::endl;
    std::cout << obj1.sum(2) << std::endl;
    std::cout << obj2.sum(2) << std::endl;

    return 0;
}
