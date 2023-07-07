GLOBAL sort
SECTION .text

sort:
jmp skip

start:
dec rdi                   ;i--
skip:
cmp rdi, 1                ;i=size(A); i>1;
jle end 

mov r10, 0                ;j=0
mov r11, rdi
dec r11
jmp skip2

loop:
inc r10                    ;j++
skip2:
cmp r10,r11               ;j<i-1
jge start

mov r8, [rsi+r10*8]          ;tmp=A[j]
mov r9, [rsi+r10*8+8]
cmp r8, r9                 ;A[j] > A[j+1]
jle loop
mov [rsi+r10*8], r9          ;A[j] = A[j+1]
mov [rsi+r10*8+8], r8        ;A[j+1] = tmp
jmp loop

end:
mov rax, rsi
ret
