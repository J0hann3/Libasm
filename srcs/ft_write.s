%include "tools.inc"

section .text
global ft_write
extern errno

; rdi => fd
; rsi => string to write
; rdx => size of the string to write
ft_write:
	sub rsp, 8				; align stack one 16 bytes

	mov rax, SYS_WRITE		; set syscall write
	syscall

	add rsp, 8				; restore stack after syscall

	test rax, rax			; like `cmp rax, 0` but more optimize
	js .error				; is negative jump to error
	ret

	.error:
		neg rax				; convert rax in a positive number
		push rax			; save return value from syscall on the stack, align the stack on 16
		call errno			; get errno address, return int * in rax
		pop rdi				; get back return value from syscall
		mov [rax], edi		; set errno with return value from write
		mov rax, -1
		ret