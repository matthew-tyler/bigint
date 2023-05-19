import subprocess
import random
import math as maths
from fractions import Fraction


def print_rational(r: Fraction):
    if r.numerator == 0:
        return "0"
    elif r.denominator == 1:
        return str(r.numerator)
    elif abs(r) < 1:
        return str(r.numerator) + "/" + str(r.denominator)
    else:
        whole_part = int(abs(r.numerator) / r.denominator)
        numerator = int(maths.fmod(abs(r.numerator), r.denominator))
        sign = "-" if r.numerator < 0 else ""
        return sign + str(whole_part) + "." + str(numerator) + "/" + str(r.denominator)

compile_process = subprocess.Popen(
    "make", stdout=subprocess.PIPE, stderr=subprocess.PIPE, text=True)
stdout, stderr = compile_process.communicate()

if compile_process.returncode == 0:
    print("Make successful with output: ", stdout)
else:
    print("Make command failed")
    print("Error:", stderr)


PROGRAM = "./bin/rational_thinking"
CMD = "test"
OPERAND = "/"

# Number of test cases
num_tests = 1000

# Generate random numbers for the test cases 
test_cases = [(random.randint(-1000000000, 1000000000),
               random.randint(-10000000000, 1000000000)) for _ in range(num_tests)]


answers = []

input_data = f""
for num1, num2 in test_cases:
    input_data += f"{num1} {OPERAND} {num2}\n"

    match OPERAND:
        case "+":
            answers.append(num1 + num2)
        case "-":
            answers.append(num1 - num2)
        case "/":
            answers.append(int(num1 / num2))
        case "*":
            answers.append(num1 * num2)
        case "%":
            answers.append(int(maths.fmod(num1, num2))) # Same as int % int in C++. 
        case "g": # short for GCD
            answers.append(maths.gcd(num1,num2))
        case "p":
            r1 = Fraction(num1,num2)
            r2 = Fraction((num1),(num2 + num1))
            answers.append(print_rational((r1 + r2)))
        case "s":
            r1 = Fraction(num1,num2)
            r2 = Fraction((num1),(num2 + num1))
            answers.append(print_rational((r1 - r2)))
        case "m":
            r1 = Fraction(num1,num2)
            r2 = Fraction((num1),(num2 + num1))
            answers.append(print_rational((r1 * r2)))
        case "d":
            r1 = Fraction(num1,num2)
            r2 = Fraction((num1),(num2 + num1))
            answers.append(print_rational((r1 / r2)))



process = subprocess.Popen([PROGRAM, CMD], stdin=subprocess.PIPE,
                           stdout=subprocess.PIPE, stderr=subprocess.PIPE, text=True)
stdout, stderr = process.communicate(input_data)

if process.returncode == 0:
    cpp_output_lines = stdout.strip().split('\n')

    all_correct = True
    for i, (cpp_output, answer) in enumerate(zip(cpp_output_lines, answers)):
        try:
            if OPERAND in "+-/*%g" and int(cpp_output) != answer:
                all_correct = False
                print(
                    f"Test case {i}: {test_cases[i][0]} {OPERAND} {test_cases[i][1]} != {cpp_output}, should be {answer}")
                continue
            if OPERAND in "psmd" and cpp_output != answer:
                all_correct = False
                print(
                    f"Test case {i}: {test_cases[i][0]} {OPERAND} {test_cases[i][1]} != {cpp_output}, should be {answer}")
                continue

        except ValueError:
            all_correct = False
            print(
                f"Test case {i}: {test_cases[i][0]} {OPERAND} {test_cases[i][1]} cannot be parsed, output was {cpp_output}, answer was {answer}")

    if all_correct:
        print("PASS")
    else:
        print("FAIL")
else:
    print("Error:", stderr)
