#include "Integer.h"
#include <iostream>
#include <string>

using namespace cosc326;

void test(const std::string &num1, const std::string &num2, char op)
{

    Integer a(num1);
    Integer b(num2);
    Integer result("0");

    // std::cerr << a << " " << op << " " << b << std::endl;

    // std::cerr << result << std::endl;

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

    Integer t("-0");
    Integer t2("0");
    // 30541696506154
    // Integer output = t * t2;

    std::cout << (t == t2) << std::endl;

    return 0;
}
