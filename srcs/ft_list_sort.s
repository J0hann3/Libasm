section .text

global ft_list_sort
extern ft_list_size

; rdi t_list **begin_list
; rsi function pointer
ft_list_sort:
	push rbx
	push r12
	push r13
	push r14
	push r15
	mov r15, [rdi]						; save t_list *begin_list
	mov r12, rsi						; save function pointer

	mov rdi, QWORD [rdi]
	call ft_list_size
	mov r13, rax						; get size list of list in in r13

	mov r14, 0							; set counter to 0
	sort_loop:
		cmp r14, r13					; loop r13 time over the list
		jge end_loop
		mov rbx, r15					; get begin_list in rbx
		swap_element_loop:
			test rbx, rbx				; check if pointer is null
			je end_swap_element_loop

			mov rdi, QWORD [rbx]
			mov rsi, QWORD [rbx + 8]	; get next element
			test rsi, rsi				; check pointer next is null
			je end_swap_element_loop
			mov rsi, QWORD [rsi]
			call r12					; call compare function

			cmp eax, 0					; cmp return value to see if positive or negative
			js end_swap_value
			swap_element:
			mov rsi, [rbx]
			mov rdx, [rbx + 8]
			xchg rsi, [rdx]
			mov [rbx], rsi
			end_swap_value:

			mov rbx, QWORD [rbx + 8]	; go to the next element of the list
			jmp swap_element_loop
		end_swap_element_loop:
		inc r14
		jmp sort_loop

	end_loop:
		pop r15
		pop r14
		pop r13
		pop r12
		pop rbx
		ret



