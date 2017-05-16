#include <iostream>
#include <string>

int myRoot(int num) {
    return (int) sqrt((double) num);
}

int main(int argc, char **argv) {
    // My integer
    int myNum = 144;
    // My string
    std::string myString = "Sqrt(num) = ";
    // Output
    std::cout << "num = " << myNum << std::endl;
    std::cout << myString;
    std::cout << myRoot(myNum) << std::endl;
    
}
