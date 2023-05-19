#include "Integer.h"
#include "Rational.h"
#include <iostream>
#include <string>

using namespace cosc326;

void test(const std::string &num1, const std::string &num2, char op)
{

    Integer a(num1);
    Integer b(num2);

    Integer result("0");
    Rational result_r;

    switch (op)
    {
    case '+':
        result = a + b;
        std::cout << result << std::endl;
        return;
        break;
    case '-':
        result = a - b;
        std::cout << result << std::endl;
        return;
        break;
    case '*':
        result = a * b;
        std::cout << result << std::endl;
        return;
        break;
    case '/':
        if (b != Integer("0"))
        {
            result = a / b;
            std::cout << result << std::endl;
            return;
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
            std::cout << result << std::endl;
            return;
        }
        else
        {
            std::cerr << "Error: Division by zero." << std::endl;
            return;
        }
        break;
    case 'g':
        result = gcd(a, b);
        std::cout << result << std::endl;
        return;
        break;
    case 'p':
        result_r = (Rational(a, b) + Rational((a), (b + a)));
        std::cout << result_r << std::endl;
        break;
    case 's':
        result_r = (Rational(a, b) + Rational((a), (b + a)));
        std::cout << result_r << std::endl;
        break;
    case 'm':
        result_r = (Rational(a, b) + Rational((a), (b + a)));
        std::cout << result_r << std::endl;
        break;
    case 'd':
        result_r = (Rational(a, b) + Rational((a), (b + a)));
        std::cout << result_r << std::endl;
        break;
    default:
        std::cerr << "Error: Invalid operator." << std::endl;
        return;
    }
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

    Rational r1(Integer("1"), Integer("100"));
    Rational r2(Integer("5"), Integer("1"));

    std::cout << -(r1 + r2) << std::endl;
    std::cout << -(r1 - r2) << std::endl;
    std::cout << -(r1 * r2) << std::endl;
    std::cout << -(r1 / r2) << std::endl;

    // Integer t1("500");

    // Integer t2("600000");

    // Integer ouput = t1 * t2;

    return 0;
}
