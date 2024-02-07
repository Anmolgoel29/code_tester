# Code Tester

## Overview

Code Tester is a command-line tool written in C++ for testing C++ programs against multiple test cases. It reads input test cases from a text file or through standard input (stdin), executes the target C++ program, and compares the output with the expected output. This tool is designed to automate the testing process, making it easier to validate the correctness of your C++ programs.

## Features

- **Test Case Input**: Accepts test cases from a text file or stdin.
- **Customizable Output Format**: Allows you to define the expected output for each test case.
- **Comparison**: Compares the actual output of the program with the expected output.
- **Detailed Report**: Generates a detailed report highlighting passed and failed test cases.

## Usage

```bash
./code_tester <program_to_test> <test_cases_file>
```

- `program_to_test`: The C++ program you want to test.
- `test_cases_file`: Path to the file containing test cases.

### Example

```bash
./code_tester my_program.cpp test_cases.txt
```

## Test Case Format

The test case file should have the following format:

```
input_1
expected_output_1

input_2
expected_output_2

...
```

Each test case consists of an input section and an expected output section. They should be separated by a newline.

## Building

To build the Code Tester, you can use a C++ compiler such as g++:

```bash
g++ -o code_tester code_tester.cpp
```

## Contributing

Contributions are welcome! If you find any issues or have suggestions for improvements, please open an issue or submit a pull request.

## Acknowledgments

- Inspired by the need for automated testing in C++ development.
- Built with a passion for reliable and efficient code testing.

Feel free to use, modify, and distribute this tool to enhance your C++ development workflow. Happy coding!
