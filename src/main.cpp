#include "Integer.h"
#include <iostream>
#include <string>

using namespace cosc326;

int main(int argc, char const *argv[])
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

    std::cout << "Hello, world!" << std::endl;

    return 0;
}
