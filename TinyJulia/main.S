extern printf
extern power
global main

section .data
format db "%d", 0
formatString db "%s", 0
newline db "" ,10 ,0

section .text
main:
push ebp
mov ebp, esp


mov DWORD[ebp - 4], 1
mov edx, 5
.L0:
cmp DWORD[ebp  - 4], edx
je .L1

push DWORD[ebp  - 4]
push format
call printf
add esp, 8
push newline
call printf
add esp, 4


inc DWORD[ebp  - 4]
jmp .L0
.L1:
leave
ret

