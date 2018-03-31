extern printf
extern power
global main

section .bss

section .data
format db "%d", 0
formatString db "%s", 0
newline db "" ,10 ,0
literal0 db "x = ", 0
literal1 db "y = ", 0
literal10 db "x^y = ", 0
literal2 db "-x = ", 0
literal3 db "-y = ", 0
literal4 db "x+y = ", 0
literal5 db "x+true = ", 0
literal6 db "x-y = ", 0
literal7 db "x*y = ", 0
literal8 db "x/y = ", 0
literal9 db "x%y = ", 0
x dd 0
y dd 0
z dd 0

section .text
main:
push ebp
mov ebp, esp
mov eax, 10
mov DWORD [x], eax

mov eax, 3
mov DWORD [y], eax

mov eax, 0
mov DWORD [z], eax

sub esp, 8
push literal0
push  formatString
call printf
add esp, 8

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
push literal1
push  formatString
call printf
add esp, 8

sub esp, 8
push DWORD [y]
push format
call printf
add esp, 8
sub esp, 4
push newline
call printf
add esp, 4

sub esp, 8
push literal2
push  formatString
call printf
add esp, 8


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

sub esp, 8
push literal3
push  formatString
call printf
add esp, 8


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

sub esp, 8
push literal4
push  formatString
call printf
add esp, 8


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

sub esp, 8
push literal5
push  formatString
call printf
add esp, 8


mov eax, DWORD [x]
add eax,1
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

sub esp, 8
push literal6
push  formatString
call printf
add esp, 8


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

sub esp, 8
push literal7
push  formatString
call printf
add esp, 8


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

sub esp, 8
push literal8
push  formatString
call printf
add esp, 8


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

sub esp, 8
push literal9
push  formatString
call printf
add esp, 8


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

sub esp, 8
push literal10
push  formatString
call printf
add esp, 8


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

