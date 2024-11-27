section .text
global ft_strcmp

ft_strcmp:
	.loop:
		mov al, byte [rdi]		; mov char to the al register
		sub al, byte [rsi]		; diff between string1 and string2

		cmp al, 0				; if diff between string1 and string2 jump to .end
		jne .end

		cmp byte [rdi], 0		; if \0 jump to .end
		je .end

		inc rdi					; increment pointer in string
		inc rsi
		jmp .loop
	.end:
		ret