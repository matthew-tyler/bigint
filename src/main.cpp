#include "Integer.h"
#include "Rational.h"
#include <iostream>
#include <string>
#include <sstream>

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

    // std::vector<int_fast8_t> digits(INT32_MAX);

    // std::vector<int_fast8_t> digits_two(INT32_MAX);

    // for (int i = 0; i < INT32_MAX; i++)
    // {
    //     digits[i] = (rand() % 10);
    //     digits_two[i] = (rand() % 10);
    // }

    // Integer test(1, digits);
    // Integer test_two(1, digits_two);

    // Integer result = test + test_two;
    // std::cout << result << std::endl;
    Rational r4("0.1/3");

    Rational r6("-3.2/4");

    std::cout << r4 << " " << r6 << " " << std::endl;
    return 0;
}
