GLOBAL strToInt ;von Thore Brehmer, Nikolas Haase, Piyush Soni
SECTION .text

strToInt:		;basis >1 und <37, Char von 0,1...9 und A,B...Z definiert
mov rax, 0
mov rdx, 0
mov r8, 0		;für rechnung
mov cl, [rdi]	;cl = erster char


cmp rsi, 1		;basis<=1
jbe fin
cmp rsi, 36		;basis>36
ja fin


cmp cl, '-'		;prüft ob negativ
jne wiederholung
mov r9, -1		
inc rdi
mov cl, [rdi]


wiederholung: 

cmp cl, 00		;testet auf Nullterminierung
je ende

cmp cl, 48		;Char not def. if ASCII<48
JB error

cmp cl, 90		;Char not def. if ASCII>90
JA error

cmp cl, 65		;cmp Char if ASCII>=65
jae buchstaben
cmp cl, 57		;cmp Zahl if ASCII<=57
jbe zahlen

error:
mov rax, 0
jmp fin

zahlen:
sub cl, 48		;für Zahlen
jmp rechnung

buchstaben:
sub cl, 55		;für Buchstaben 

rechnung:
mov r10b, sil
sub r10b, 1
cmp r10b, cl	;cmp basis, char
jb error		;basis<char = error

mul r8			;r8=r8*rax
mov r8, rsi		;für basis
add al, cl		;rax= rax+ dezimal
inc rdi
mov cl, [rdi]   ;cl = next char
jmp wiederholung

ende:

cmp r9, -1		;falls Zahl negative
jne fin	
mul r9			

fin:
RET
