GLOBAL pseudocodeÜ2 ;von Thore Brehmer, Nikolas Haase, Soni Piyush
SECTION .text
pseudocodeÜ2:

cmp rdi, 10 
jc xkleiner10	;if (x<10)
jz xgleich10	;if (x==10)
jnc xgroesser10 ;if (x>10)

W()		;else ()
jmp end

xkleiner10: 
S()
jmp end

xgleich10;
T()
jmp end

xgroesser10:
V()
jmp end

end:
RET






GLOBAL while
Section .text
while:




cmp rdi, 10
jz ende		;if (x==10) jmp zum ende
	
redo:		;while()
mov rdi, S	;x=S()
cmp rdi, 10
jnz redo	;if (x!=10) jmp zum redo (while)





mov cx, 1	;benötigt für loop
start:		;Anfang des loops
cmp rdi, 10
jz ende		;if (x==10) Abbruch des Loops, falls Bedienung wahr
inc cx		;cx = cx+1
mov rdi, S	;x = S()
loop start	;jmp start, stop if (cx == 0), else ()cx--




ende:
RET







