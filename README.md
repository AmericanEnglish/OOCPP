
# Introduction to C++ Object Oriented Programming
This small repo serves as a quick crash course through C++ object oriented 
programming. 
The idea  is that after following this small run through you should have 
the skill sets to design some basic objects in C++ and their respective 
header files. 
On top of that I will cover some basic design for Qt 5.8 and subclassing 
the windows.

## Table of Contents
    1. [Introduction to Objects](#intro)
    2. [Bigger Example of OOP](#example2)
    3. [Super and Sub Classes](#classing)
    4. [Virtual and Override Methods](#virto)

## Forward on Starting Object Oriented Programming (OOP)
Object Oriented programming revoles around several concepts that
incorporate fancy terms and various other lingo. 
The aim of this repo is to keep it simple.  
I'll go back through and introduce some definition of these fancy terms 
when it suits me.
Please note that this repo isn't yet meant to be a fully exauhstive course
on all things CPP OOP. 
In fact many things that might be considered important to OOP might not 
be super relevant to the development of Qt windows.
So I won't put anything about Descontructors for example.
Maybe in the future but not for now.

## <a name="intro"></a> Header Files and Implementation Files

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
Take note that the object has access to its own methods and internal 
variables without the need of a "." or "->" operator.
In Python you might seen something like:
```python
class obj1:
    def __init__(self, var1):
        self.var = var1
        #   ^ This thing here
    def method1(self):
        pass
    def method2(self, var2):
        if var2 == self.var:
        #              ^ Again
            return self.var
        else:
            return self.method1()
            #          ^ Here it is
```
C++ doesn't require the dot operator to access internals of the object
itself.
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

## <a name="example2"></a>Bigger by Examples - Example2
So example1 might not seem super useful. 
Clearly it is more effective to just use a function for simple numerical
incrementation.
However what if you wanted to store more than just one value?
Say you wanted to store a message and an integer to go with it.
In a regular c++ file you'd see something like:
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

## <a name="classing"></a> Subclasses and Super Classes - example3
The next idea is the idea of subclassing.
The easiest real life example of subclassing that comes to mind is the subclassing of numbers.
Imagine that following.
* class Number (A Super class)
    * Generic. All numbers can be a number. Range from -inf -> +inf
* class Rational : public Number (A Sub class of Number, Superclass of Integer)
    * Contains numbers which can be represented as a quotient of whole numbers
* class Integer : public Rational (Subclass of Rationals, Superclass of Naturals)
    * Can only be whole numbers from -inf -> +inf
* class Natural : public Integer (Sub class of Integer)
    * Can only be integers greater than 0

My code examples do not implement this idea BUT if does help explain the concept of subclasses and 
superclasses.
Number is a generic terms which can be ANY number.
However Rational is a specialization of Number which means that the number in question could
be represented as a quotient of integers. 
This specialization is what makes subclassing important. 

For the demonstration allow for the following to happen:
1. There exists a superclass called SuperClass
2. There is a subclass which specializes SuperClass

For brevity I will only include the header file code in this example.
```c++
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
    private:
        int superSum(int aNum);
        // Private Variables
        int num;
        std::string c;
};
```
If you want to see the SuperClass in action yourself you can compile demoSuper.cpp with
```
> cl demoSuper.cpp superclass.cpp
> demonSuper.exe
a0
A1
Sums:
2
3
```
Now if we want to specialize/subclass the SuperClass we're going to create another class called SubClass.
```c++
// subclass.h
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
// subclass.cpp
#include "subclass.h"

SubClass::SubClass(int aNum, std::string c, std::string m) : SuperClass(aNum, c) {
//                                                         ^ Super class call
    secondString = m;
}

int SubClass::subtract(int aNum) {
    // num is private :(
    //return num - aNum;
    // If only there was a better way
    return sum(0) - aNum;
}

```

Take note that my call to the super class happens in the header file here:
```c++
class SubClass : public SuperClass {
    //            ^ inheritance type
```
<!--Explain the inhereitance type here-->
<!--Explain the inhereitance type here-->
In the cpp file I also call the constructor for the super class:
```c++
SubClass::SubClass(int aNum, std::string c, std::string m) : SuperClass(aNum, c) {
//                                                         ^ Super class call
```
Passing the variables to the superclass as needed allows for those variables to be setup how the
super class saw fit.
This even allows SubClass to use the same methods of SuperClass! 
This can be seen in demoSub.cpp
```c++
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
```
SubClass can use both its own special method `SubClass::subtract` and `SuperClass::sum`.
The most important section here is that if you look at `SubClass::subtract` there is this poor call to 
`sum(int aNum)`.
This is because in the the variable `num` is considered private and only accessable by superclass methods.
Notice how `SuperClass::sum(int aNum)` works perfectly fine but `SubClass::subtract(int aNum)` needs this 
bad call to the prior method.
In this it would behoove us to redefine another section of privleges called `protected`. 
Protected variables and Methods are somewhere inbetween Private and Public lands.
* Public
    * Everyone can see and use them
* Private
    * Only I, the Object, may see any use them
* Protected
    * Only I, the Object, AND my related/friendly classes have access to them.
    * [Heres a link to a more formal definition](https://msdn.microsoft.com/en-us/library/e761de5s.aspx)

So for the subtract method to work as intended We'll change the header of `SuperClass` to the following:
```c++
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
    /* New Piece */
    protected:
        int num2;
    /*************/
    private:
        int superSum(int aNum);
        // Private Variables
        int num;
        std::string c;
};

```
This will allow us to implement a new method called `SubClass::subtract2(int aNum)` as shown below:
```c++
int SubClass::subtract2(int aNum) {
    // num2 is protected :)
    return num2 - aNum;
}
```

So to compile the whole thing:
```
> cl /EHsc demoSub.cpp subclass.cpp superclass.cpp
> demoSub.exe
a0
1.) 0 - 5 = -5
2.) 0 - 5 = -5
0 + 5 = 5
```

Hopefully this gives you an idea of how subclassing. 
The next two pieces that need to happen are also important. 
Onto Virtual Methods!

### <a name="virto"></a>Override and Virtual Methods
Before I begin I want start up front with the definition of these objects and then 
extrapolation.
1. SuperClass
```c++
// superclass.h
#pragma once
class SuperClass {
    public:
        // Constructor
        SuperClass(int aNum1 = 0, int aNum2 = 0);
        
        // Methods
        int sum(int aNum);
    protected:
        internalSum();
        int num1, num2;
};
// superclass.cpp
#include "superclass.h"

SuperClass::SuperClass(int aNum1, int aNum2) {
    num1 = aNum1;
    num2 = aNum2;
}

// Public
int SuperClass::sum(int aNum) {
    return internalSum() + aNum;
}

// Protected
int SuperClass::internalSum() {
    return num1 + num2;
}
```

2. SubClass
```c++
// subclass.h
#pragma once
#include "superclass.h"

class SubClass : public SuperClass {
    public:
        // Constructor
        SubClass(int aNum1 = 0, int aNum2 = 0, int aNum3 = 0);

    protected:
        int internalSum();
        int num3;
};
// subclass.cpp
#include "subclass.h"

SubClass::SubClass(int aNum1, int aNum2, int aNum3) : SuperClass(aNum1, aNum2) {
    num3 = aNum3;
}

int SubClass::internalSum() {
    return num1 + num2 + num3;
}
```

Now first let's demo these with demoSub.cpp with the following:
```c++
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
```

Compile and run!
```
> cl demonSub.cpp subclass.cpp superclass.cpp
> demoSub.exe
1 + 1 + 3 = 5
1 + 1 + 1 + 3 = 5
```
Definitely not right. Let's take a look at our code to make sure we did it right:
```c++
// superclass.cpp
int SuperClass::internalSum() {
    return num1 + num2;
}
// subclass.cpp
int SubClass::internalSum() {
    return num1 + num2 + num3;
}
```

Both of these classes define `internalSum` but for some reason it is still only 
summing num1 and num2 as if SubClass was calling the method from SuperClass.
In part it "is" calling it. This is a long conversation beyond this crash course.
[Check out binding here](http://stackoverflow.com/questions/36691108/what-is-the-difference-between-early-binding-and-late-binding-in-c).
Basically we need to make `SuperClass::internalSum()` virtual so that 
`SubClass::internalSum()` gets called instead. 
Now:
```c++
#pragma once
class SuperClass {
    public:
        // Constructor
        SuperClass(int aNum1 = 0, int aNum2 = 0);
        
        // Methods
        int sum(int aNum);
    protected:
        // Old
        //int internalSum();
        // New
        virtual int internalSum();
        int num1, num2;
};
```

By adding `virtual` we have made `SuperClass::interalSum()` so that it can be replaced/re
written by `SubClass::internalSum()` and the calls all checkout.
```c++
> demoSub.exe
1 + 1 + 3 = 5
1 + 1 + 1 + 3 = 6
```

* What about `override`?

`override` is a small extension of virtual, as is read [here](http://en.cppreference.com/w/cpp/language/override).
If we wanted to make a SubSubClass of our SubClass we'll have to overwrite 
`SubClass::interalSum()` as well but remember that `SubClass::internalSum()` isn't 
virtual like `SuperClass::internalSum()` is. 
In order to both replace and allow it to be replaced we'll make `SubClass::internalSum()`
virtual by using `override` like just below.
```c++
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
```
This would allow a SubSubClass to replace the `interalSum()` method of SubClass.

## Qt Widget Example
### Qt Subclassing
### Qt Virtual Methods
