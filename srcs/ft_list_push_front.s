section .text

global ft_list_push_front
extern malloc

; rdi t_list **begin_list
; rsi void *data
ft_list_push_front:
	push rbx
	push r12
	push r13
	mov rbx, rdi				; save begin list in rbx
	mov r12, rsi				; save data in r12

	mov rdi, 16					; size to malloc for struct s_list(void* + t_list*)
	call malloc

	test rax, rax				; test if malloc failed
	je .end

	mov QWORD rax[0], r12		; add data to the new t_list element

	mov r13, QWORD [rbx]		; add next to the t_list according to begin_list
	mov QWORD rax[8], r13

	mov [rbx], rax				; return the next t_list as the first of the list

	.end:
		pop r13
		pop r12
		pop rbx
		ret

