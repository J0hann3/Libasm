%include "tools.inc"

section .text
global ft_read
extern errno

; rdi => fd
; rsi => string to stock the buffer
; rdx => size of the string to read
ft_read:
	sub rsp, 8

	mov rax, SYS_READ
	syscall

	add rsp, 8

	test rax, rax
	js .error
	ret

	.error:
		neg rax
		push rax
		call errno
		pop rdi
		mov [rax], edi
		mov rax, -1
		ret