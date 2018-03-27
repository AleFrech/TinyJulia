extern printf
extern power
global main

section .bss

section .data
format db "%d", 0
formatString db "%s", 0
newline db "" ,10 ,0
literal0 db "", 9, " Hello ", 34, "Inner", 34, " World", 10, "", 0

section .text
main:
push ebp
mov ebp, esp
sub esp, 8
push literal0
push  formatString
call printf
add esp, 8

leave
ret

