#include "Integer.h"
#include <iostream>
#include <string>

using namespace cosc326;

void test(const std::string &num1, const std::string &num2, char op)
{

    Integer a(num1);
    Integer b(num2);
    Integer result;

    switch (op)
    {
    case '+':
        result = a + b;
        break;
    case '-':
        result = a - b;
        break;
    case '*':
        result = a * b;
        break;
    case '/':
        if (b != Integer("0"))
        {
            result = a / b;
        }
        else
        {
            std::cerr << "Error: Division by zero." << std::endl;
            return;
        }
        break;
    case '%':
        if (b != Integer("0"))
        {
            result = a % b;
        }
        else
        {
            std::cerr << "Error: Division by zero." << std::endl;
            return;
        }
        break;
    default:
        std::cerr << "Error: Invalid operator." << std::endl;
        return;
    }

    std::cout << result << std::endl;
}

int main(int argc, char const *argv[])
{

    if (argc > 1)
    {
        std::string num1, num2;
        char op;

        while (std::cin >> num1 >> op >> num2)
        {
            test(num1, num2, op);
        }

        return 0;
    }

    Integer test("-5382261");
    Integer test2("4994794");

    // std::cout << test.debugPrint() << std::endl;

    std::cout << test << " + " << test2 << std::endl;

    Integer output = test + test2;

    // std::cout << output.debugPrint() << std::endl;
    std::cout << output << std::endl;

    return 0;
}
