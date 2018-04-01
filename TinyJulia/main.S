extern printf
extern power
global main

section .bss

section .data
format db "%d", 0
formatString db "%s", 0
newline db "" ,10 ,0
literal0 db "The favorite number, ", 0
literal1 db ", has been reached: ", 0
literal2 db "Is pair ", 0
literal3 db " the val: ", 0
literal4 db "#", 0
literal5 db " is pair: ", 0
literal6 db "Weird stuff from val: ", 0
literal7 db " now: ", 0
literal8 db "All a lie.", 0
el_bool dd 0
el_global dd 0

section .text
main:
push ebp
mov ebp, esp
mov eax, 100
mov DWORD [el_global], eax

mov eax, 0
mov DWORD [el_bool], eax



sub esp, 8
push literal4
push  formatString
call printf
add esp, 8

sub esp, 8
push DWORD [el_global]
push format
call printf
add esp, 8
sub esp, 8
push literal5
push  formatString
call printf
add esp, 8

push DWORD [el_global]
call IsPair1
add esp, 4
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

sub esp, 8
push DWORD [el_global]
push format
call printf
add esp, 8
sub esp, 8
push literal7
push  formatString
call printf
add esp, 8

push DWORD [el_global]
call WeirdStuff1
add esp, 4
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



mov ecx,DWORD [el_bool]
mov edx,0
xor eax, eax
cmp ecx, edx
sete al
mov DWORD[ebp - 4], eax

mov eax, DWORD[ebp - 4]
cmp eax , 0
je .L5
sub esp, 8
push literal8
push  formatString
call printf
add esp, 8
sub esp, 4
push newline
call printf
add esp, 4

jmp .L4
.L5:
.L4:

leave
ret

IsPair1:
push ebp
mov ebp, esp


mov eax,DWORD[ebp + 8]
cdq
mov ecx,2
idiv ecx
mov DWORD[ebp - 4], edx


mov ecx,DWORD[ebp - 4]
mov edx,0
xor eax, eax
cmp ecx, edx
sete al
mov DWORD[ebp - 4], eax

mov eax, DWORD[ebp - 4]
leave
ret


xor eax, eax
leave
ret
WeirdStuff1:
push ebp
mov ebp, esp
sub esp, 12


mov eax,DWORD[ebp + 8]
cdq
mov ecx,2
imul ecx
mov DWORD[ebp - 8], eax
mov eax, DWORD[ebp - 8]
mov DWORD[ebp  - 4], eax



mov eax, 0
sub esp, 4
mov DWORD[ebp  - 12], eax
.L0:
mov ecx , DWORD[ebp  - 4]
cmp DWORD[ebp  - 12], ecx
jg .L1


mov ecx,DWORD[ebp  - 12]
mov edx,5
xor eax, eax
cmp ecx, edx
sete al
mov DWORD[ebp - 16], eax

mov eax, DWORD[ebp - 16]
cmp eax , 0
je .L3
sub esp, 8
push literal0
push  formatString
call printf
add esp, 8

sub esp, 8
push DWORD[ebp  - 12]
push format
call printf
add esp, 8
sub esp, 8
push literal1
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

jmp .L2
.L3:
.L2:

sub esp, 8
push literal2
push  formatString
call printf
add esp, 8

sub esp, 8
push DWORD[ebp  - 12]
push format
call printf
add esp, 8
sub esp, 8
push literal3
push  formatString
call printf
add esp, 8

push DWORD[ebp  - 12]
call IsPair1
add esp, 4
mov DWORD[ebp - 16], eax

sub esp, 8
push DWORD[ebp - 16]
push format
call printf
add esp, 8
sub esp, 4
push newline
call printf
add esp, 4

inc DWORD[ebp  - 12]
jmp .L0
.L1:


mov eax,DWORD[ebp  - 4]
cdq
mov ecx,DWORD [el_global]
imul ecx
mov DWORD[ebp - 16], eax

mov eax, DWORD[ebp - 16]
leave
ret


xor eax, eax
leave
ret
