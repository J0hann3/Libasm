%include "tools.inc"

section .rodata
	whitespace db ' ', 9, 10, 11, 12, 13

section .text

global ft_atoi_base
extern ft_strlen

is_whitespace:
	cmp dil, whitespace[0]
	je .whitespace_find
	cmp dil, whitespace[1]
	je .whitespace_find
	cmp dil, whitespace[2]
	je .whitespace_find
	cmp dil, whitespace[3]
	je .whitespace_find
	cmp dil, whitespace[4]
	je .whitespace_find
	cmp dil, whitespace[5]
	je .whitespace_find
	mov rax, False
	ret
	.whitespace_find:
		mov rax, True
		ret

; rdi string to convert into number
; rsi base for the conversion
ft_atoi_base:
	push rbx
	push r12
	push r13
	push r14
	mov r12, rdi						; number to convert
	mov rbx, rsi						; base for conversion
	mov r14, rsi						; save base for conversion
	parse_base:
		cmp byte [rbx], 0
		je error_base
		cmp byte [rbx + 1], 0
		je error_base

		parse_base_loop:
			check_whitespace_in_base:
			mov dil, byte [rbx]			; check whitespace in base
			call is_whitespace
			cmp rax, True
			je error_base

			check_sign_in_base:
			cmp byte [rbx], '+'			; check +/- in base
			je error_base
			cmp byte [rbx], '-'
			je error_base

			check_duplicate_in_base:
			mov r13, rbx				; check duplicate in base
			inc r13
			mov al, byte [rbx]
			parse_base_loop_duplicate:
				cmp byte [r13], 0
				je end_parse_base_loop_duplicate
				cmp al, byte [r13]
				je error_base
				inc r13
				jmp parse_base_loop_duplicate

			end_parse_base_loop_duplicate:
			inc rbx
			cmp byte [rbx], 0			; check end of base
			je conversion_number
			jmp parse_base_loop

	error_base:							; return parsing error
		pop r14
		pop r13
		pop r12
		pop rbx
		mov rax, 0
		ret

	conversion_number:
		mov rbx, r14
		skip_whitespace_loop:
			mov dil, byte [r12]			; check whitespace in number
			call is_whitespace
			cmp rax, False
			je end_skip_whitespace_loop
			inc r12
			jmp skip_whitespace_loop
		end_skip_whitespace_loop:

		mov r13, 0						; counter of negative sign
		skip_and_count_sign_loop:
			cmp byte [r12], '-'
			je increment_minus_sign
			cmp byte [r12], '+'
			je increment_loop
			jmp end_skip_and_count_sign_loop
			increment_minus_sign:
				inc r13
			increment_loop:
				inc r12
			jmp skip_and_count_sign_loop
		
		end_skip_and_count_sign_loop:
			; check number of minus oven or odd

		mov rdi, rbx
		call ft_strlen
		mov rsi, rax					; size of the base

		mov rax, 0						; contains the res to return at the end
		conversion_number_loop:
			mov rcx, 0					; index for the position in the base
			mov dil, byte [r12]
			check_number_in_base_loop:
				cmp dil, byte [rbx + rcx]
				je end_check_number_in_base_loop
				inc rcx
				cmp byte [rbx + rcx], 0
				je end_conversion_number
				jmp check_number_in_base_loop
			end_check_number_in_base_loop:
			imul rax, rsi
			add rax, rcx
			inc r12
			cmp byte [r12], 0
			je end_conversion_number
			jmp conversion_number_loop

	end_conversion_number:
		test r13, 1
		jz even_number_of_sign
		neg rax
		even_number_of_sign:
		pop r14
		pop r13
		pop r12
		pop rbx
		ret