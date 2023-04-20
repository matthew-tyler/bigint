#include "Integer.h"
#include <iostream>
#include <string>

using namespace cosc326;

void example()
{
    // Some notes as a reminder for myself + Rosie

    // Declaring classes can be done in two ways:
    Integer test;                   // as whatever a not pointer is
    Integer *test2 = new Integer(); // as a pointer

    // If we want to use the other constructors:
    Integer test3(test);                // as whatever a not pointer is
    Integer *test4 = new Integer(test); // as a pointer

    // if we want to use their overloaded methods:
    test + test;     // as whatever a not pointer is
    *test2 + *test2; // as a pointer
}

int main(int argc, char const *argv[])
{
    // How to print / For testing if setup works on new machine
    // std::cout << "Hello, world!" << std::endl;

    Integer test("-8777");
    Integer test2("9777");

    // std::cout << test.debugPrint() << std::endl;

    short proof = -8777 + 9777;

    test = test + test2;

    std::cout << test << std::endl;

    std::cout << proof << std::endl;

    return 0;
}
