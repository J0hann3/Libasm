section .text
global ft_strlen

ft_strlen:
	mov rcx, 0
	cmp byte rdi[rcx], 0
	je .end
	.loop:
		add rcx, 1
		cmp byte rdi[rcx], 0
		jne .loop
	.end:
		mov rax, rcx
		ret