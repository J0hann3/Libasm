<h1 align=center>💻 Libasm</h1>
<p align="center">
  <img src="img/libasm.png?raw=true"/>
</p>

## About

> The aim of this project is to get familiar with assembly language.

[Subject Libasm Project 42](libasm.pdf)


## Features
- **Description**: 
- **Feature**: 
- **How to Use**: 

## Setup

**Clone the Repository**:
```bash
git clone https://github.com/J0hann3/Libasm.git;
cd Libasm
```
## Usage

## New Notion
- Registers => 64 bits
	- `rip`(Instruction pointer) => next address to be executed in the control flow
- Stack (Last In First Out):
	- `rsp`(Stack Pointer) => top address of the stack
	- `rbp`(Stack Base Pointer) => bottom address of the stack

### CPU
- Register => 64 bits
- ALU (Arithmetic Logic Unit) => +/-/*//
- Status flags:
	- Carry(CF)
	- Parity(PF)
	- Adjust(AF)
	- Zero(ZF)
	- Unsigned result(SF)
	- (TF)
	- (IF)
	- (DF)
	- Overflow(OF)
	- (IOPL)
	- (NT)
	- (RF)
	- (VM)
	- (AC)
	- (VIF)
	- (VIP)
	- (ID)
- Program Counter(PC)
- Input/Output

### RAM
- Program Memory

### Assembly languages
- Opcode -> action to do
- Operand -> argument
	- source: register, memory, value, implicit
	- destination: register, memory
	- ATTENTION: source and destination can't be memory at the same time
- Addressing mode:
	- Register Addressing
		- `mov ax, bx`, moves contents of register bx into ax
	- Immediate
		- `mov ax, 1`, moves value of 1 into register ax
		- `mov ax, 010Ch`, moves value of 0x010C into register ax
	- Direct
		- `mov ax, [my_var]`, copy my_var content into ax
		- `mov al, [byte_table + 2]`
		- `mov al, byte_table[2]`
	- Indirect
		- The registers used for indirect addressing are BX, BP, SI, DI
		- `mov ax, [di]`

- section
	- .data => define data before compilation
	- .bss => allocate data
	- .text => code
- label
	- variables
	- `_start` => mandatory to run the code
- global
- `rax` return value from functions
- Calling convention
	- caller => person that call the function
	- callee => function being called
- Instruction suffix:
	- `b` -> 1 bytes
	- `w` -> 2 bytes
	- `l` -> 4 bytes
	- `q` -> 8 bytes
- Binary
	- `10101B`
- Hexadecimal
	- `F82EH`

### Registers

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

### Syscall

| system call number | 1st parameter | 2nd parameter | 3rd parameter | 4th parameter | 5th parameter | 6th parameter | result |
| ------------------|----------------|----------------|---------------|-------------|---------------|-------|-------------|
| `rax` | `rdi` | `rsi` | `rdx` | `r10` | `r8` | `r9` | `rax`|

All registers, except `rcx` and `r11` (and the return value, `rax`), are preserved during the system call with syscall. 

### Intel syntax

`mov destination, source`

`mov qword ptr[rax],rbx`

`call qword ptr[rbx+rsi*4-0xe8]`


### Unit test
- TDD:
	- write code only to fix a test that failed
	- stop writing unit test when one failed
	- stop writing code when unit test pass



