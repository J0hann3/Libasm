section .text

global ft_strdup

extern ft_strlen
extern ft_strcpy
extern malloc
extern errno

; rdi string to duplicate
ft_strdup:
	push rbx			; save variable to use this register after, align on 16bytes

	mov rbx, rdi		; save the string in register caller owned
	call ft_strlen

	add eax, 1			; add 1 to the length for the \0
	mov rdi, rax		; pass length to malloc
	call malloc

	test rax, rax		; check if malloc failed
	je .end

	mov rdi, rax		; pass malloc string to strcpy
	mov rsi, rbx		; pass string to copy to strcpy
	call ft_strcpy

	.end:
		pop rbx			; restore rbx value
		ret