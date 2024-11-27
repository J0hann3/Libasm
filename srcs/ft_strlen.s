section .text					; section to write code
global ft_strlen				; define function to be use outside of this file

; ft_strlen return the length of the argument
; return size_t
; size_t ft_strlen(const char *s)
; rdi is the string, we need to get its length

ft_strlen:
	mov rcx, 0					; init counter to 0
	cmp byte rdi[rcx], 0		; check if string is empty
	je .end						; jump to the end if source is empty
	.loop:
		add rcx, 1				; increment counter by 1
		cmp byte rdi[rcx], 0	; compare char with \0 to known if the string is ended
		jne .loop				; if not jump to loop again
	.end:
		mov rax, rcx			; copy counter value to return value
		ret						; return from the function