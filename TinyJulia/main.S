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
x dd 0
y dd 0

section .text
main:
push ebp
mov ebp, esp
mov eax, 10
mov DWORD [x], eax

mov eax, 3
mov DWORD [y], eax


sub esp, 8
push DWORD [x]
push format
call printf
add esp, 8
sub esp, 4
push newline
call printf
add esp, 4


sub esp, 8
push DWORD [y]
push format
call printf
add esp, 8
sub esp, 4
push newline
call printf
add esp, 4



mov eax,DWORD [x]
cdq
mov ecx,-1
imul ecx
mov DWORD[ebp - 4], eax


sub esp, 8
push DWORD[ebp - 4]
push format
call printf
add esp, 8
sub esp, 4
push newline
call printf
add esp, 4



mov eax,DWORD [y]
cdq
mov ecx,-1
imul ecx
mov DWORD[ebp - 4], eax


sub esp, 8
push DWORD[ebp - 4]
push format
call printf
add esp, 8
sub esp, 4
push newline
call printf
add esp, 4



mov eax, DWORD [x]
add eax,DWORD [y]
mov DWORD[ebp - 4], eax

sub esp, 8
push DWORD[ebp - 4]
push format
call printf
add esp, 8
sub esp, 4
push newline
call printf
add esp, 4



mov eax, DWORD [x]
sub eax,DWORD [y]
mov DWORD[ebp - 4], eax

sub esp, 8
push DWORD[ebp - 4]
push format
call printf
add esp, 8
sub esp, 4
push newline
call printf
add esp, 4



mov eax,DWORD [x]
cdq
mov ecx,DWORD [y]
imul ecx
mov DWORD[ebp - 4], eax

sub esp, 8
push DWORD[ebp - 4]
push format
call printf
add esp, 8
sub esp, 4
push newline
call printf
add esp, 4



mov eax,DWORD [x]
cdq
mov ecx,DWORD [y]
idiv ecx
mov DWORD[ebp - 4], eax

sub esp, 8
push DWORD[ebp - 4]
push format
call printf
add esp, 8
sub esp, 4
push newline
call printf
add esp, 4



mov eax,DWORD [x]
cdq
mov ecx,DWORD [y]
idiv ecx
mov DWORD[ebp - 4], edx

sub esp, 8
push DWORD[ebp - 4]
push format
call printf
add esp, 8
sub esp, 4
push newline
call printf
add esp, 4



push DWORD [y]
push DWORD [x]
call power
add esp,8
mov DWORD[ebp - 4], eax

sub esp, 8
push DWORD[ebp - 4]
push format
call printf
add esp, 8
sub esp, 4
push newline
call printf
add esp, 4

leave
ret

