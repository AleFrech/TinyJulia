extern printf
extern power
global main

section .bss
a resb 100
b resb 100

section .data
format db "%d", 0
formatString db "%s", 0
newline db "" ,10 ,0
literal0 db "Imprimiendo Booleans", 0

section .text
main:
push ebp
mov ebp, esp
lea edi,[a]
mov ecx, 0
mov eax, 7
mov [edi+ecx*4], eax
inc ecx
mov eax, 4
mov [edi+ecx*4], eax
inc ecx
mov eax, 9
mov [edi+ecx*4], eax
inc ecx
mov eax, 2
mov [edi+ecx*4], eax
inc ecx
mov eax, 10
mov [edi+ecx*4], eax
inc ecx
mov eax, 1
mov [edi+ecx*4], eax
inc ecx
mov eax, 5
mov [edi+ecx*4], eax
inc ecx
mov eax, 3
mov [edi+ecx*4], eax
inc ecx
mov eax, 8
mov [edi+ecx*4], eax
inc ecx
mov eax, 6
mov [edi+ecx*4], eax
inc ecx
mov eax, 0
mov [edi+ecx*4], eax
inc ecx



mov eax, 1
sub esp, 4
mov DWORD[ebp  - 4], eax
.L0:
mov ecx , 11
cmp DWORD[ebp  - 4], ecx
jg .L1


mov eax, 1
sub esp, 4
mov DWORD[ebp  - 8], eax
.L2:
mov ecx , 10
cmp DWORD[ebp  - 8], ecx
jg .L3
mov ebx, DWORD[ebp  - 8]
sub ebx, 1
lea edi, [a]
mov esi, [edi + ebx * 4]
mov DWORD[ebp - 12], esi



mov eax, DWORD[ebp  - 8]
add eax,1
mov DWORD[ebp - 16], eax
mov ebx, DWORD[ebp - 16]
sub ebx, 1
lea edi, [a]
mov esi, [edi + ebx * 4]
mov DWORD[ebp - 20], esi

mov ecx,DWORD[ebp - 12]
mov edx,DWORD[ebp - 20]
xor eax, eax
cmp ecx, edx
setg al
mov DWORD[ebp - 12], eax

mov eax, DWORD[ebp - 12]
cmp eax , 0
je .L5


mov eax, DWORD[ebp  - 8]
add eax,1
mov DWORD[ebp - 20], eax
mov ebx, DWORD[ebp - 20]
sub ebx, 1
lea edi, [a]
mov esi, [edi + ebx * 4]
mov DWORD[ebp - 24], esi
mov eax, DWORD[ebp - 24]
mov DWORD[ebp  - 16], eax

mov ebx, DWORD[ebp  - 8]
sub ebx, 1
lea edi, [a]
mov esi, [edi + ebx * 4]
mov DWORD[ebp - 24], esi


mov eax, DWORD[ebp  - 8]
add eax,1
mov DWORD[ebp - 32], eax

mov eax, DWORD[ebp - 24]
mov ebx, DWORD[ebp - 32]
sub ebx, 1
lea edi, [a]
mov [edi + ebx*4], eax



mov eax, DWORD[ebp  - 16]
mov ebx, DWORD[ebp  - 8]
sub ebx, 1
lea edi, [a]
mov [edi + ebx*4], eax


jmp .L4
.L5:
.L4:

inc DWORD[ebp  - 8]
jmp .L2
.L3:
inc DWORD[ebp  - 4]
jmp .L0
.L1:


mov eax, 1
sub esp, 4
mov DWORD[ebp  - 24], eax
.L6:
mov ecx , 11
cmp DWORD[ebp  - 24], ecx
jg .L7
mov ebx, DWORD[ebp  - 24]
sub ebx, 1
lea edi, [a]
mov esi, [edi + ebx * 4]
mov DWORD[ebp - 28], esi

sub esp, 8
push DWORD[ebp - 28]
push format
call printf
add esp, 8
sub esp, 4
push newline
call printf
add esp, 4

inc DWORD[ebp  - 24]
jmp .L6
.L7:
lea edi,[b]
mov ecx, 0
mov eax, 1
mov [edi+ecx*4], eax
inc ecx
mov eax, 0
mov [edi+ecx*4], eax
inc ecx
mov eax, 0
mov [edi+ecx*4], eax
inc ecx
mov eax, 1
mov [edi+ecx*4], eax
inc ecx
mov eax, 1
mov [edi+ecx*4], eax
inc ecx
mov eax, 0
mov [edi+ecx*4], eax
inc ecx

sub esp, 8
push literal0
push  formatString
call printf
add esp, 8
sub esp, 4
push newline
call printf
add esp, 4



mov eax, 1
sub esp, 4
mov DWORD[ebp  - 28], eax
.L8:
mov ecx , 6
cmp DWORD[ebp  - 28], ecx
jg .L9
mov ebx, DWORD[ebp  - 28]
sub ebx, 1
lea edi, [b]
mov esi, [edi + ebx * 4]
mov DWORD[ebp - 32], esi

sub esp, 8
push DWORD[ebp - 32]
push format
call printf
add esp, 8
sub esp, 4
push newline
call printf
add esp, 4

inc DWORD[ebp  - 28]
jmp .L8
.L9:
leave
ret

