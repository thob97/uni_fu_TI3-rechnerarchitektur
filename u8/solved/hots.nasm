GLOBAL zipWith, fold
Section .text

zipWith:
mov r9, 0
mov r10, rsi
mov r11, rdi

start:
cmp r10, 0             ;test auf leere liste
je ende

mov rdi, [rdx + r9 * 8]    ;Elemente von Listen
mov rsi, [rcx + r9 * 8]

push r9                ;Register sichern
push r10
push r11
push rcx
push rdx
push rdi
push rsi
push r8
call r11
pop r8
pop rsi
pop rdi
pop rdx
pop rcx
pop r11
pop r10
pop r9

mov [r8 + r9 * 8], rax    ;Ergebniss Liste in r8

dec r10                   ; 1 - length 
inc r9                    ;inc Pointer
jmp start

ende:
ret



fold:
cmp rsi, 0                ;Leere liste
je ausnahme1
cmp rsi, 1                ;Nur ein Element
je ausnahme2


cmp rcx, 1                ;links oder rechts
je right

mov r8, rsi
mov rsi, [rdx]             ;Variable 1
mov r9, 1
mov r10, rdi

left:
cmp r8, 1
je ende

mov rdi, [rdx + r9 * 8]    ;Variable 2

push r9                    ;Register sichern
push r10
push r11
push rcx
push rdx
push rdi
push rsi
push r8
call r10
pop r8                    
pop rsi
pop rdi
pop rdx
pop rcx
pop r11
pop r10
pop r9

mov rsi, rax                ;Ergebniss in Variable1

dec r8                      ; 1 - Length 
inc r9                      ;inc Pointer  
jmp left


right:
mov r8, rsi
dec r8
mov rsi, [rdx+r8*8]         ;Variable 1
mov r10, rdi
dec r8

rights:
mov rdi, [rdx + r8 * 8]    ;Variable 2

push r9                    ;Register sichern
push r10
push r11
push rcx
push rdx
push rdi
push rsi
push r8
call r10
pop r8
pop rsi
pop rdi
pop rdx
pop rcx
pop r11
pop r10
pop r9

mov rsi, rax                ;Ergebniss in Variable1

cmp r8, 0
je ende

dec r8                      ;Dec Pointer
jmp rights

ausnahme1:
xor rax, rax
ret
ausnahme2:
mov rax, [rdx]
ret