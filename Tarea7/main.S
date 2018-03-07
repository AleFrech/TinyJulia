extern printf
global main

section .data
format db "%d ", 10, 0
x dd 0
y dd 0

section .text
main:push ebp
mov ebp, esp

mov eax, 5
mov DWORD[x], eax
mov eax, DWORD[x]
mov DWORD[ebp - 4], eax
mov eax, DWORD[ebp - 4]
cmp eax , 0
jz .L0

mov eax, 10
mov DWORD[y], eax
mov eax, DWORD[y]
mov DWORD[ebp - 8], eax
push DWORD[ebp - 8]
push format
call printf
add esp, 8


jmp .L1
.L0:
.L1:
leave
ret