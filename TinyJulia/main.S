extern printf
extern power
global main

section .bss

section .data
format db "%d", 0
formatString db "%s", 0
nothing db "",0
true db "true",0
false db "false",0
newline db "" ,10 ,0

section .text
main:
push ebp
mov ebp, esp

sub esp, 8
push 1
push format
call printf
add esp, 8
sub esp, 4
push newline
call printf
add esp, 4


sub esp, 8
push 11
push format
call printf
add esp, 8
sub esp, 4
push newline
call printf
add esp, 4

mov eax, 0
leave
ret

