%include "tools.inc"

section .text
global ft_write

; rdi => fd
; rsi => string to write
; rdx => size of the string to write
ft_write:
	mov rax, SYS_WRITE
	syscall
	ret