<h1 align=center>💻 Libasm</h1>
<p align="center">
  <img src="img/libasm.png?raw=true"/>
</p>

## About

> The aim of this project is to get familiar with assembly language.

Use for the first time assembly languages

[Subject Libasm Project 42](libasm.pdf)


## Features
- **Description**: Learn to manipulate assembly language and get one step closer to understanding how computers work at a low level.
- **Feature**: Recreate basic functions in assembly using the x86_64 architecture with Intel syntax.
- **How to Use**: Use the `Libasm.a` library to access all the functions.

## Setup

**Clone the Repository**:
```bash
git clone https://github.com/J0hann3/Libasm.git;
cd Libasm
```
## Usage

- Compile the library with the following command:
```bash
make
```
- Add the function prototypes in your source file.
- Compile your file with the libraby:
```bash
gcc main.c -L. -lasm
```
- Run Unit Tests to verify the functionality of each function:
```bash
make test
```

## New Notion

### CPU Architecture
- **Registers**: can have 8, 16, 32 or 64 bits.
	- This project will use 64 bits registers. 
- **ALU**(Arithmetic Logic Unit): Handles arithmetic operations like `*`, `-`, `/`, and `+`.
- **Status flags**:
	-Carry Flag (CF)
	- Parity Flag (PF)
	- Adjust Flag (AF)
	- Zero Flag (ZF)
	- Sign Flag (SF)
	- Overflow Flag (OF)
	- Trap Flag (TF)
	- Interrupt Flag (IF)
	- Direction Flag (DF)
	- and more...
- **Program Counter(PC)**: Points to the next instruction to execute.
- **Input/Output(I/O)** operations.

### Assembly Language Basics
- **Opcode**: Represents the action to be performed (e.g., `mov`, `add`, `sub`).
- **Operand**: The argument of the instruction, which can be a source or destination.
	- **Source**: Can be a register, memory, constant, or implicit.
	- **Destination**: Can be a register or memory.
	- **Note**: Both source and destination cannot be memory at the same time.
- **Addressing Modes**:
	- **Register Addressing**:
	Example: `mov ax, bx` — moves the content of `bx` into `ax`.
	- **Immediate Addressing**:
	Example: `mov ax, 1` — moves the value `1` into `ax`.
	Example: `mov ax, 0x010C` — moves the value `0x010C` into `ax`.
	- **Direct Addressing**:
	Example: `mov ax, [my_var]` — copies the content of `my_var` into `ax`.
	- **Indirect Addressing**:
	Registers like `BX`, `BP`, `SI`, and `DI` are used in indirect addressing.
	Example: `mov ax, [di]` — loads the value from the address in `di` into `ax`.

- **Sections**:
   - `.data` — Define data before compilation.
  	- `.bss` — Allocate uninitialized data.
    - `.text` — Code section.
    - `.rodata` — Read-only data.
- **Labels**: Used for variables and code references.
  - `_start`: Mandatory entry point for an executable program.
- **Global**: Expands the scope of variables/functions outside the file.

- **Calling Convention**:

    - **Caller-owned**: The function calling another function.
	- **Callee-owned**: The function being called.
    - The stack must be aligned to 16 bytes before calling a function.
- **Instruction suffix**:
	- `b` -> 1 byte.
	- `w` -> 2 bytes.
	- `l` -> 4 bytes.
	- `q` -> 8 bytes.
- **Data Representation**:
    - Binary: `10101B`
    - Hexadecimal: `F82EH`
- **Registers**
	- `rip`(Instruction pointer) — Points to the next instruction.
	- `rsp`(Stack Pointer) — Top address of the stack.
	- `rbp`(Stack Base Pointer) — Bottom address of the stack.

### Registers Overview

| 64-Bits | 32-Bits | 16-Bits | 8-Bits | Calling Convention |  Main Purpose | Purpose |
| --------| --------| --------| -------| -------------------| --------------| --------|
| `rax` | `eax` | `ax` | `al` | Callee-owned | Return value | Accumulator |
| `rdi` | `edi` | `di` | `dil` | Callee-owned | 1st argument | Destination Index |
| `rsi` | `esi` | `si` | `sil` | Callee-owned | 2nd argument | Source Index |
| `rdx` | `edx` | `dx` | `dl` | Callee-owned | 3rd argument | high Accumulator mul/div |
| `rcx` | `ecx` | `cx` | `cl` | Callee-owned | 4th argument | Counter, variable shift, rotate via CL |
| `r8` | `r8d` | `r8w` | `r8b` | Callee-owned | 5th argument|
| `r9` | `r9d` | `r9w` | `r9b` | Callee-owned | 6th argument|
| `r10` | `r10d` | `r10w` | `r10b` | Callee-owned | Temporary |
| `r11` | `r11d` | `r11w` | `r11b` | Callee-owned | Temporary |
| `rsp` | `esp` | `sp` | `spl` | Caller-owned | Stack Pointer |
| `rbx` | `ebx` | `bx` | `bl` | Caller-owned | Local Variable | Index register |
| `rbp` | `ebp` | `bp` | `bpl` | Caller-owned | Base Pointer |
| `r12` | `r12d` | `r12w` | `r12b` | Caller-owned | Local Variable |
| `r13` | `r13d` | `r13w` | `r13b` | Caller-owned | Local Variable |
| `r14` | `r14d` | `r14w` | `r14b` | Caller-owned | Local Variable |
| `r15` | `r15d` | `r15w` | `r15b` | Caller-owned | Local Variable |
| `rip` | | | | | Instruction Pointer |
| `eflags` | | | | | Status/condition code bits |

### Syscalls

| System Call Number | 1st parameter | 2nd parameter | 3rd parameter | 4th parameter | 5th parameter | 6th parameter | result |
| ------------------|----------------|----------------|---------------|-------------|---------------|-------|-------------|
| `rax` | `rdi` | `rsi` | `rdx` | `r10` | `r8` | `r9` | `rax`|

All registers, except `rcx` and `r11` (and the return value, `rax`), are preserved during a system call. 

### Intel syntax
Example instructions in Intel syntax:
- `mov destination, source`
- `mov qword ptr[rax],rbx`
- `call qword ptr[rbx+rsi*4-0xe8]`
