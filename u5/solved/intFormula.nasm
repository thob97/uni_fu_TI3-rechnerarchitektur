Global formula
Section .text
formula:

add rdi, rsi	;rdi=a+b
sub rdx, rcx 	;rdx=c-d
mov rcx, rdx	;rcx=rdx
mov rax, rdi	;rax=rdi
mov rdx, 0
imul rcx		;rax=(a+b)*(c-d)
mov rdi, rax

shl r8, 3		;e*8
shl r9, 2		;f*4
add r8,r9		;rax = e*8+f*4

mov rax, [rsp+8];rax=g
shr rax, 1		;rax=g/2

sub r8, rax		;e*8+f*4-g/2


mov rax, [rsp+16];rax=h
shr rax, 2			;rax=h/4
add rax, r8		;rax=rax+h/4
mov rdx, 0

imul rdi		;(...)*(.....)

mov rsi, 3
idiv rsi		;(...)*(.....)/3

ret