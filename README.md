#  Custom Instruction Compiler: Matrix Multiplication (3x2 × 2x2)

This project is a simple compiler that processes a **custom instruction** for matrix multiplication. Using Flex (Lexical Analyzer) and C, it interprets the instruction, takes matrix input from the user at runtime, performs multiplication of a 3x2 matrix with a 2x2 matrix, and outputs the result as a 3x2 matrix.

---

## 📌 Objective
Design and implement a **custom instruction** in a compiler to compute the result of a matrix multiplication equation:

```bash
compute M = A * B;
```

Where:
- `A` is a 3×2 matrix (entered by the user)
- `B` is a 2×2 matrix (entered by the user)
- `M` is the resulting 3×2 matrix after multiplication

---

## 📁 Project Structure
```
Matrix-Instruction-Compiler/
├── Executable_Build/     # Precompiled executable and object files
│   ├── equation.exe
│   ├── main.o
│   ├── compute.o
│   ├── lex.yy.o
│   ├── lex.yy.c
│   └── README.md
│
├── Source_Code/          # Source files for compilation
│   ├── main.c
│   ├── compute.c
│   ├── compute.h
│   ├── compute.l
│   ├── Makefile (optional)
│   └── README.md
```

---

## ⚙️ Build & Execution Instructions

### ✅ Method 1: Manual Compilation (Windows using MinGW)
```bash
# Step 1: Generate the lexer
flex compute.l

# Step 2: Compile source files
gcc -c main.c
gcc -c compute.c
gcc -c lex.yy.c -o lex.yy.o

# Step 3: Link object files into executable
gcc -o equation.exe main.o compute.o lex.yy.o

# Step 4: Run the program
./equation.exe
```

> **Note**: Ensure your `compute.l` ends with:
```c
int yywrap() { return 1; }
```
This prevents "undefined reference to `yywrap`" linker errors.

---

### ✅ Method 2: Using Makefile (If Available)
```bash
make           # Builds the project
./equation.exe # Runs the compiled executable

make clean     # Removes object and temporary files
```

---

## 🧪 Sample Input & Output
```
Enter command like: compute M = A * B;
> compute M = A * B;
Enter values for 3x2 matrix A (row-wise):
1 2
3 4
5 6
Enter values for 2x2 matrix B (row-wise):
7 8
9 10
Resultant 3x2 Matrix (A * B):
   25.00    28.00 
   57.00    64.00 
   89.00   100.00 
```

---

## 📘 Command Reference Table
| Command                                | Description                                      |
|----------------------------------------|--------------------------------------------------|
| `flex compute.l`                       | Generates lexer source file `lex.yy.c`           |
| `gcc -c main.c`                        | Compiles the main program logic                  |
| `gcc -c compute.c`                     | Compiles matrix computation implementation       |
| `gcc -c lex.yy.c -o lex.yy.o`          | Compiles the generated lexer code                |
| `gcc -o equation.exe ...`              | Links all object files into an executable        |
| `equation.exe`                         | Executes the program                             |

---

## 🚀 Features
- Accepts input for two matrices at runtime
- Validates custom command syntax via Flex
- Performs real-time multiplication
- Clean output of the result matrix

---

## 📦 Submission Guidelines
- Push the entire project to a GitHub repository.
- Include:
  - `Executable_Build/` — for ready-to-run executable
  - `Source_Code/` — for code-level inspection and manual compilation
- Place this `README.md` in both folders for reference

---

## 💡 Future Enhancements
- Add support for more matrix operations (addition, transpose)
- Implement error handling for input formats and command syntax
- Create a simple GUI or web interface for interaction

---

## 🧑‍💻 Author
**Name:** Jayesh (replace with your full name for submission)  
**Project Title:** Custom Instruction Compiler for Matrix Multiplication

---

Happy Coding! 🚀

