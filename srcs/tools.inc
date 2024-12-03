%ifndef TOOLS_INC
	%define TOOLS_INC

	SYS_READ equ 0
	SYS_WRITE equ 1

	%define errno __errno_location
	%define True 1
	%define False 0
	
%endif