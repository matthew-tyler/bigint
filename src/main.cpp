#include "Integer.h"
#include <iostream>
#include <string>

using namespace cosc326;

int main(int argc, char const *argv[])
{
    // How to print / For testing if setup works on new machine
    // std::cout << "Hello, world!" << std::endl;

    Integer test("20");
    Integer test2("-8");

    // std::cout << test.debugPrint() << std::endl;

    int proof = 20 + 8;

    Integer output = test + test2;
    test = test + test2;
    // std::cout << output.debugPrint() << std::endl;

    std::cout << test << std::endl;
    std::cout << output << std::endl;
    std::cout << proof << std::endl;

    return 0;
}
