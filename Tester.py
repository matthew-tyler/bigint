import subprocess
import random


compile_process = subprocess.Popen("make", stdout=subprocess.PIPE, stderr=subprocess.PIPE, text=True)
stdout, stderr = compile_process.communicate()

if compile_process.returncode == 0:
    print("Make successful with output: ", stdout)
else:
    print("Make command failed")
    print("Error:", stderr)
    

PROGRAM = "./bin/rational_thinking"  
CMD = "test"
OPPERAND = "-"

# Number of test cases
num_tests = 10

# Generate random numbers for the test cases
test_cases = [(random.randint(-1000000000, 1000000000), random.randint(-1000000000, 1000000000)) for _ in range(num_tests)]


answers = []

input_data = f""
for num1, num2 in test_cases:
    input_data += f"{num1} {OPPERAND} {num2}\n"
    
    match OPPERAND:
        case "+":
            answers.append(num1 + num2)
        case "-":
            answers.append(num1 - num2)
        case "/":
            answers.append(num1 / num2)
        case "*":
            answers.append(num1 * num2)


process = subprocess.Popen([PROGRAM, CMD], stdin=subprocess.PIPE, stdout=subprocess.PIPE, stderr=subprocess.PIPE, text=True)
stdout, stderr = process.communicate(input_data)

if process.returncode == 0:
    cpp_output_lines = stdout.strip().split('\n')
    
    all_correct = True
    for i, (cpp_output, answer) in enumerate(zip(cpp_output_lines, answers)):
        if int(cpp_output) != answer:
            all_correct = False
            print(f"Test case {i}: {test_cases[i][0]} {OPPERAND} {test_cases[i][1]} != {cpp_output}, should be {answer}")
    
    if all_correct:
        print("PASS")
    else:
        print("FAIL")
else:
    print("Error:", stderr)