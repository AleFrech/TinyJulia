extern printf
extern power
global main

section .bss
x resb 100

section .data
format db "%d", 0
formatString db "%s", 0
newline db "" ,10 ,0
literal0 db "Mayor a 25 ", 0
literal1 db "Menor a 25 ", 0
literal2 db "Igual a 25 ", 0
literal3 db "", 9, " Hello ", 34, "Inner", 34, " World", 10, "", 0

section .text
main:
push ebp
mov ebp, esp
lea edi,[x]
mov ecx, 0
mov eax, 15
mov [edi+ecx*4], eax
inc ecx
mov eax, 34
mov [edi+ecx*4], eax
inc ecx
mov eax, 25
mov [edi+ecx*4], eax
inc ecx
mov eax, 54
mov [edi+ecx*4], eax
inc ecx



mov eax, 1
sub esp, 4
mov DWORD[ebp  - 4], eax
.L0:
mov ecx , 4
cmp DWORD[ebp  - 4], ecx
jg .L1
mov ebx, DWORD[ebp  - 4]
sub ebx, 1
lea edi, [x]
mov esi, [edi + ebx * 4]
mov DWORD[ebp - 8], esi


mov ecx,DWORD[ebp - 8]
mov edx,25
xor eax, eax
cmp ecx, edx
setg al
mov DWORD[ebp - 8], eax

mov eax, DWORD[ebp - 8]
cmp eax , 0
je .L3
sub esp, 8
push literal0
push  formatString
call printf
add esp, 8
mov ebx, DWORD[ebp  - 4]
sub ebx, 1
lea edi, [x]
mov esi, [edi + ebx * 4]
mov DWORD[ebp - 12], esi

sub esp, 8
push DWORD[ebp - 12]
push format
call printf
add esp, 8
sub esp, 4
push newline
call printf
add esp, 4

jmp .L2
.L3:
mov ebx, DWORD[ebp  - 4]
sub ebx, 1
lea edi, [x]
mov esi, [edi + ebx * 4]
mov DWORD[ebp - 12], esi


mov ecx,DWORD[ebp - 12]
mov edx,25
xor eax, eax
cmp ecx, edx
setl al
mov DWORD[ebp - 12], eax

mov eax, DWORD[ebp - 12]
cmp eax , 0
je .L5
sub esp, 8
push literal1
push  formatString
call printf
add esp, 8
mov ebx, DWORD[ebp  - 4]
sub ebx, 1
lea edi, [x]
mov esi, [edi + ebx * 4]
mov DWORD[ebp - 16], esi

sub esp, 8
push DWORD[ebp - 16]
push format
call printf
add esp, 8
sub esp, 4
push newline
call printf
add esp, 4

jmp .L4
.L5:
sub esp, 8
push literal2
push  formatString
call printf
add esp, 8
mov ebx, DWORD[ebp  - 4]
sub ebx, 1
lea edi, [x]
mov esi, [edi + ebx * 4]
mov DWORD[ebp - 16], esi

sub esp, 8
push DWORD[ebp - 16]
push format
call printf
add esp, 8
sub esp, 4
push newline
call printf
add esp, 4

.L4:
.L2:

inc DWORD[ebp  - 4]
jmp .L0
.L1:
sub esp, 8
push literal3
push  formatString
call printf
add esp, 8

leave
ret

