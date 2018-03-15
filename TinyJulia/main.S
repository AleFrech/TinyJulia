extern printf
global main

section .data
formatln db "%d ", 10, 0
format db "%d ", 0
formatStringln db "%s ", 10, 0
formatString db "%s ", 0
x dd 0

section .text
main:
push ebp
mov ebp, esp
mov eax, 10
mov DWORD [x], eax

leave
ret
