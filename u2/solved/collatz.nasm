GLOBAL collatz      ;von Thore Brehmer, Nikolas Haase, Soni Piyush
SECTION .text
collatz:

mov r10, 0	;k = 0


cmp rdi, 1
jbe ende		;if (n<=1) jmp zum Ende
while:

inc r10		;k++
mov rdx, 0
mov rax, rdi
mov rbx, 2
div rbx		;rdx= n mod 2
cmp rdx, 0	;(isEven(n)) Bedienung
jz if

mov rbx, 3	;else
mov rax, rdi
mul rbx		;rax=n*3
mov rdi, rax	;n=rax
inc rdi		;n++
jmp skipIF

if:
mov rdi, rax	;rax=n/2, n=rax

skipIF:
cmp rdi,1	;while Bedienungen
ja while	;if (n>1) jmp zum while

ende:
mov rax, r10
RET
