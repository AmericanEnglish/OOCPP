# Introduction to C++ Object Oriented Programming
This small repo serves as a quick crash course through C++ object oriented 
programming. 
The idea  is that after following this small run through you should have 
the skill sets to design some basic objects in C++ and their respective 
header files. 
On top of that I will cover some basic design for Qt 5.8 and subclassing 
the windows.

## Forward on Starting Object Oriented Programming (OOP)
Object Oriented programming revoles around several concepts that
incorporate fancy terms and various other lingo. 
The aim of this repo is to keep it simple.  
I'll go back through and introduce some definition of these fancy terms 
when it suits me.

## Header Files and Implementation Files

### Header Files

My favorite definition of header files  for objects is that [header files are like contracts](https://ocw.mit.edu/courses/electrical-engineering-and-computer-science/6-088-introduction-to-c-memory-management-and-c-object-oriented-programming-january-iap-2010/lecture-notes/MIT6_088IAP10_lec04.pdf)
otherwise looked at as "agreements" that the object will implement.

### CPP Files
This is the actual implementation of the object. 
The meat and potatoes of the object and its methods.
Methods are basically functions that belong to an object. 
Typically your object will require what is called a "constructor"
this constructor is how the object will build itself given some data.
An object can and often will have multiple constructors.
Below is an example of a basic object compared to a function.
Both the object and the function have the same purpose. 
The code can be found in the example1 file set.
```c++
// Header File (.h / .hpp)
class adder {
    public:
        // Variables and Methods that can be accessed outside the object itself
        // Constructor 
        adder();
        // Variable
        int num1;
        // Method
        int addOne(int num);
    private:
        // Variables and Methods that only the object itself can access
};
// Declartion File (.cpp)
// The object must include its own header file
#include "object1.h"
#include <iostream>

// A regular funtion
int addOne(int num) {
    return num + 1;
}
//  The object
adder::adder() {
    num = num;
}
int adder::addOne(int num) {
    return num + 1;
}

int main() {
    std::cout << "Begin" << std::endl;
    int example = 1;
    std::cout << "Function: " << addOne(example) << std::endl;
    // Prints 2
    adder obj = adder();
    std::cout << "Object: " << obj.addOne(example) << std::endl;
    // Prints 2
}
```

### Expanded Examples - Example2
So example1 might not seem super useful. 
Clearly it is more effective to just use a function for simple numerical
incrementation.
However what if you wanted to store more than just one value?
Say you wanted to store a message and an integer to go with it.
In a regular c++ file you'd see something like.
```c++
// myRootFunction.cpp
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
    std::cout << myString << myRoot(myNum) << std::endl;
    
}
```
For one operation this might be fine. 
You keep the function approach and continue creating more functions
to handle this number over and over again.
However you COULD create and object to do the same.
```c++
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
// CPP File
#include <iostream>
#include <string>
#include "object2.h"

myInteger::myInteger(int aNum, std::string message) {
    num = aNum;
    msg = message;
    
}

void myInteger::print() {
    std::cout << msg << mySqrt() << std::endl;
}

void myInteger::setNum(int newNum) {
    num = newNum;
}

// This can only be used by the object itself
int myInteger::mySqrt() {
    return (int) sqrt((double) num);
}
```

Notice that this file lacks a main.
I'd like to talk about the main just below. 
Notice the contructor
```c++
myInteger(int num = 0, std::string message = "");
```
Having the equal sign allows the object to spawned, otherwise called 
instantiated, with defaults BUT allows you to pass values to the object
if you so choose.

So to demonstrate this we will spawn several objects in our main.
```c++
int main(int argc, char **argv) {
    // No vars given
    myInteger obj1 = myInteger();
    // One var given
    myInteger obj2 = myInteger(144);
    // Both vars given
    myInteger obj3 = myInteger (169, "sqrt(13) =");

}
```

Then we will go through and call all their methods.
```c++
    obj1.print();
    // Prints
    // 0
    obj2.print();
    // Prints
    // 12
    obj3.print();
    // Prints
    // sqrt(13) =13
```

The benefit here is that if I wanted to do the sqrt and print an output
message for 100 numbers.
I'd have to go through and type the `std::cout` line 100 times as well
spawn all the numers into being, and all the strings, all the extra casting 
from int to double in each square root call.
With the object this process is abstracted away to just spawning the objects
with their respective numbers and messages.

