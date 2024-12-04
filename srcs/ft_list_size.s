section .text

global ft_list_size

; rdi t_list *begin_list
ft_list_size:
	push rbp						; align stack on 16
	mov rax, 0						; initialize counter with 0
	.size_loop:
		test rdi, rdi				; check NULL pointer
		je .end
		inc rax						; increment counter
		mov rdi, QWORD [rdi + 8]	; mov to next elem in the lis
		jmp .size_loop
	
	.end:
		pop rbp
		ret