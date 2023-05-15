import subprocess
import random


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
num_tests = 10000

# Generate random numbers for the test cases
test_cases = [(random.randint(-1000000, 1000000000),
               random.randint(-400000, 1000000)) for _ in range(num_tests)]


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
            answers.append(num1 % num2)


process = subprocess.Popen([PROGRAM, CMD], stdin=subprocess.PIPE,
                           stdout=subprocess.PIPE, stderr=subprocess.PIPE, text=True)
stdout, stderr = process.communicate(input_data)

if process.returncode == 0:
    cpp_output_lines = stdout.strip().split('\n')

    all_correct = True
    for i, (cpp_output, answer) in enumerate(zip(cpp_output_lines, answers)):
        try:
            if int(cpp_output) != answer:
                all_correct = False
                print(
                    f"Test case {i}: {test_cases[i][0]} {OPERAND} {test_cases[i][1]} != {cpp_output}, should be {answer}")
        except ValueError:
            all_correct = False
            print(
                f"Test case {i}: {test_cases[i][0]} {OPERAND} {test_cases[i][1]} cannot be parsed, output was {cpp_output}")

    if all_correct:
        print("PASS")
    else:
        print("FAIL")
else:
    print("Error:", stderr)
