section .text

global ft_list_remove_if
extern free

; rdi t_list **begin_list
; rsi void *data_ref
; rdx function pointer to comp data with data_ref
; rcx function pointer to free data
ft_list_remove_if:
	push rbx
	push r12
	push r13
	push r14
	push r15
	push rcx						; free function
	sub rsp, 8						; align stack on 16bytes
	mov rbx, rdi					; **begin list
	mov r12, rsi					; data_ref
	mov r13, rdx					; cmp function
	mov r15, QWORD [rdi]			; *list_begin
	.compare_and_remove_loop:
		test r15, r15				; check if element of list is NULL
		je .end_function

		mov rdi, QWORD [r15]		; call comp function with list->data and data_ref
		mov rsi, r12
		call r13

		cmp rax, 0
		jne .end_remove_element
		.remove_element:
			mov rdi, QWORD [r15]			; free data with free_fct
			call [rsp + 8]

			mov rax, QWORD [r15 + 8]		; get next element pointer

			cmp r15, [rbx]					; comp element with the list head
			je .remove_first_element
			mov QWORD [r14 + 8], rax		; set next element of the previous one
			jmp .end_remove_first_element
			.remove_first_element:
				mov QWORD [rbx], rax		; set the begin of the list
			.end_remove_first_element:
			mov rdi, r15					; give argument to free function
			mov r15, rax					; move the list to the next element
			call free
			jmp .compare_and_remove_loop
		.end_remove_element:
		mov r14, r15
		mov r15, QWORD [r15 + 8]
		jmp .compare_and_remove_loop

	.end_function:
		add rsp, 8
		pop rcx
		pop r15
		pop r14
		pop r13
		pop r12
		pop rbx
		ret