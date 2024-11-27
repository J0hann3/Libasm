section .text
global ft_strcpy

; ft_strcpy copy the source into th destination
; return pointer to the destination
; char *ft_strcpy(char *dest, const char *src)
; rsi is the source
; rdi is the destination

ft_strcpy:
	mov rax, rdi			; save destination pointer for return value
	cmp byte [rsi], 0		; check if source if empty before copying bytes
	je .end					; jump to the end if ZF is set to 1 => comp is equal
	.loop:
		mov byte dl, [rsi]	; save src char into register
		mov byte [rdi], dl	; copy register into dest
		add rsi, 1			; increment src pointer
		add rdi, 1			; increment dest pointer
		cmp byte [rsi], 0	; check if src end with \0
		jne .loop			; jump to loop if comp is not equal to \0
	.end:
		mov byte [rdi], 0	; add \0 at the end of dest
		ret					; return from the function