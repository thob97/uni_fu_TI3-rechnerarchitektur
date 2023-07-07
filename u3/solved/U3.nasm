GLOBAL asm_fib_it	;von Thore Brehmer, Nikolas Haase, Piyush Soni 
GLOBAL asm_fib_rek
SECTION .text

asm_fib_it:
mov r10, 0	;x=0
mov r11, 1	;y=1
mov rax, 0	;k=0

while:
cmp rdi, 0
jbe abbruch	;if (n<=0) jmp abbruch
mov r10, r11	;x=y
mov r11, rax	;y=k
mov rax, r10	;rax=x
add rax, r11	;rax=x+y
dec rdi		;n--
jmp while

abbruch:
ret


asm_fib_rek:

cmp rdi, 3
jb anker		;if(n<3) jmp zum anker
dec rdi			;n--
push rdi		;n im stack
call asm_fib_rek	;fib(n-1)
pop rdi			;hole n aus dem stack
dec rdi			;n--
call asm_fib_rek	;fib(n-2)
ret

anker:
inc rax			;return 1
ret
