section .text
global ft_strcpy

ft_strcpy:
	mov rax, rdi
	cmp byte [rdi], 0
	je .end
	.loop:
		mov byte dl, [rsi]
		mov byte [rdi], dl
		add rsi, 1
		add rdi, 1
		cmp byte [rdi], 0
		jne .loop
	.end:
		ret

; ft_strcpy:
; 	mov rax, rdi
; 	cmp byte rdi, 0
; 	je .end
; 	.loop:
; 		rep movsb rdi, rsi
; 		cmp byte rdi, 0
; 		jne .loop
; 	.end:
; 		ret