extern printf
global main

section .data
formatln db "%d ", 10, 0
format db "%d ", 0
formatStringln db "%s ", 10, 0
formatString db "%s ", 0
literal0 db "This is an ", 0
literal1 db "and will be ", 0
literal2 db "Hello World", 0

section .text
main:
push ebp
mov ebp, esp
push literal0
push  formatString
call printf
add esp, 8
push literal1
push  formatString
call printf
add esp, 8

push literal2
push  formatStringln
call printf
add esp, 8

leave
ret
