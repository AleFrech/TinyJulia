extern printf
extern power
global main

section .data
format db "%d", 0
formatString db "%s", 0
newline db "" ,10 ,0
literal0 db " es par", 0
literal1 db " es impar", 0

section .text
main:
push ebp
mov ebp, esp


mov DWORD[ebp  - 4], 1
.L0:
mov ecx , 10
cmp DWORD[ebp  - 4], ecx
jg .L1


mov eax,DWORD[ebp  - 4]
cdq
mov ecx,2
idiv ecx
mov DWORD[ebp - 8], edx


mov ecx,DWORD[ebp - 8]
mov edx,0
xor eax, eax
cmp ecx, edx
sete al
mov DWORD[ebp - 8], eax

mov eax, DWORD[ebp - 8]
cmp eax , 0
je .L3

sub esp, 8
push DWORD[ebp  - 4]
push format
call printf
add esp, 8
sub esp, 8
push literal0
push  formatString
call printf
add esp, 8
sub esp, 4
push newline
call printf
add esp, 4

jmp .L2
.L3:

sub esp, 8
push DWORD[ebp  - 4]
push format
call printf
add esp, 8
sub esp, 8
push literal1
push  formatString
call printf
add esp, 8
sub esp, 4
push newline
call printf
add esp, 4

.L2:

inc DWORD[ebp  - 4]
jmp .L0
.L1:
leave
ret

