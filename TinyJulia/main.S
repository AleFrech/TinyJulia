extern printf
extern power
global main

section .data
format db "%d", 0
formatString db "%s", 0
newline db "" ,10 ,0
literal0 db "Este es el numero dentro ", 0
z dd 0

section .text
main:
push ebp
mov ebp, esp


push 20
push 15
call Suma11
add esp, 8
mov DWORD[ebp - 8], eax
mov eax, DWORD[ebp - 8]
mov DWORD [z], eax


sub esp, 8
push DWORD [z]
push format
call printf
add esp, 8
sub esp, 4
push newline
call printf
add esp, 4

leave
ret

Suma11:
push ebp
mov ebp, esp
sub esp, 8
mov eax, 0
mov DWORD[ebp  - 4], eax



mov eax, DWORD[ebp + 8]
add eax,DWORD[ebp + 12]
mov DWORD[ebp - 8], eax

mov eax, DWORD[ebp - 8]
leave
ret


xor eax, eax
leave
ret
Suma1:
push ebp
mov ebp, esp
sub esp, 4
mov eax, 10
mov DWORD[ebp  - 4], eax

sub esp, 8
push literal0
push  formatString
call printf
add esp, 8

sub esp, 8
push DWORD[ebp  - 4]
push format
call printf
add esp, 8
sub esp, 4
push newline
call printf
add esp, 4


xor eax, eax
leave
ret
