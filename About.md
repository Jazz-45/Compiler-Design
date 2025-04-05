# 📓 Matrix Instruction Compiler: Project Development Log

This document explains in detail all the steps followed to complete the assignment titled:

> **"Design a custom instruction for a given equation in a compiler."**

---

## 🧠 Problem Understanding
The goal was to create a compiler (using Lex/Flex and C) that could accept a specific custom instruction syntax like:
```
compute M = A * B;
```
Where A and B are matrices entered by the user at runtime, and the result M is calculated through matrix multiplication. Specifically:
- A: 3×2 matrix
- B: 2×2 matrix
- M: 3×2 matrix (result)

---

## 🛠️ Project Setup
I started by creating a new folder with the following source files:
- `main.c`
- `compute.c`
- `compute.h`
- `compute.l`
- `Makefile` (optional)

---

## 🧾 Step-by-Step Implementation

### 1. **Lex File (`compute.l`)**
This file uses Flex to define the tokenization rules. I defined a rule to match the custom instruction syntax:
```
compute M = A * B;
```
Upon detecting this pattern, Flex triggers a C function call to perform matrix input and multiplication.

Also, I ensured to include this function to prevent linking errors:
```c
int yywrap() { return 1; }
```

### 2. **Header File (`compute.h`)**
I defined function prototypes for all matrix operations:
```c
void inputMatrix(float matrix[][2], int rows, int cols);
void multiplyMatrices(float A[][2], float B[][2], float result[][2]);
void printMatrix(float result[][2], int rows, int cols);
```

### 3. **Computation File (`compute.c`)**
This file implements the actual matrix logic:
- `inputMatrix`: Takes user input for matrices A and B
- `multiplyMatrices`: Performs matrix multiplication
- `printMatrix`: Outputs the resulting matrix M

I ensured that matrix sizes were hardcoded to 3x2 and 2x2 for simplicity and clarity.

### 4. **Main File (`main.c`)**
This file runs the lexer:
```c
extern int yyparse();
int main() {
    yylex();
    return 0;
}
```

### 5. **Compilation and Debugging**
I followed this sequence:
```bash
flex compute.l
gcc -c main.c
gcc -c compute.c
gcc -c lex.yy.c -o lex.yy.o
```

Initially, I faced a few issues:
- Missing `yywrap` function → solved by defining it
- Missing `-lfl` on MinGW → skipped using `-lfl`, and wrote `yywrap` manually

### 6. **Final Linking**
```bash
gcc -o equation.exe main.o compute.o lex.yy.o
```
I made sure the executable was generated in a separate `Executable_Build/` folder.

### 7. **Testing**
I tested the executable multiple times using the input format:
```
compute M = A * B;
```
and verified that the matrix multiplication was accurate for all test cases.

---

## 🗃️ Folder Structure
I organized the repo into two folders:
- `Executable_Build/`: Contains the final `.exe` and compiled object files
- `Source_Code/`: Contains all the C source files and lexer code

---

## 🧪 Sample Output
```
compute M = A * B;
Enter values for 3x2 matrix A:
1 2
3 4
5 6
Enter values for 2x2 matrix B:
7 8
9 10

Result:
25.00 28.00
57.00 64.00
89.00 100.00
```

---

## 📸 Screenshot
I took a screenshot of the terminal output and saved it as `output_screenshot.png` for the README file.

---

## 📤 GitHub Preparation
To make the project submission-ready:
- Created README with usage, structure, and sample output
- Added screenshot image
- Verified build instructions
- Pushed everything to GitHub

---

## ✅ Conclusion
This assignment helped me understand how to:
- Write custom token patterns using Flex
- Connect a lexer to C logic
- Perform matrix operations
- Compile multi-file C projects
- Structure a project repository professionally

📚 **Skills Used**: C Programming, Flex (Lex), GitHub, Terminal commands

---

**Author:** Jayesh

**Submission:** Matrix Instruction Compiler

