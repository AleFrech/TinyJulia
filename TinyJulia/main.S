This is a Hello World
extern printf
global main

section .data
formatln db "%d ", 10, 0
format db "%d ", 0

section .text
main:
push ebp
mov ebp, esp





leave
ret
