extern printf
extern power
global main

section .bss
a resb 100

section .data
format db "%d", 0
formatString db "%s", 0
newline db "" ,10 ,0

section .text
main:
push ebp
mov ebp, esp
lea edi,[a]
mov ecx, 0
mov eax, 5
mov [edi+ecx*4], eax
inc ecx
mov eax, 4
mov [edi+ecx*4], eax
inc ecx
mov eax, 2
mov [edi+ecx*4], eax
inc ecx
mov eax, 1
mov [edi+ecx*4], eax
inc ecx
mov eax, 3
mov [edi+ecx*4], eax
inc ecx

mov eax, 7

mov ebx, 2
sub ebx, 1
lea edi, [a]
mov [edi + ebx*4], eax




mov eax, 1
mov DWORD[ebp  - 8], eax
.L0:
mov ecx , 5
cmp DWORD[ebp  - 8], ecx
jg .L1
mov ebx, DWORD[ebp  - 8]
sub ebx, 1
lea edi, [a]
mov esi, [edi + ebx * 4]
mov DWORD[ebp - 4], esi

sub esp, 8
push DWORD[ebp - 4]
push format
call printf
add esp, 8
sub esp, 4
push newline
call printf
add esp, 4

inc DWORD[ebp  - 8]
jmp .L0
.L1:
leave
ret

