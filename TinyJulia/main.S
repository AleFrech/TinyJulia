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
mov eax, 4
mov [edi+ecx*4], eax
inc ecx
mov eax, 2
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



mov eax, 1
sub esp, 4
mov DWORD[ebp  - 4], eax
.L0:
mov ecx , 5
cmp DWORD[ebp  - 4], ecx
jg .L1



mov eax, 5
sub eax,1
mov DWORD[ebp - 8], eax

mov eax, 1
sub esp, 4
mov DWORD[ebp  - 12], eax
.L2:
mov ecx , DWORD[ebp - 8]
cmp DWORD[ebp  - 12], ecx
jg .L3
mov ebx, DWORD[ebp  - 12]
sub ebx, 1
lea edi, [a]
mov esi, [edi + ebx * 4]
mov DWORD[ebp - 16], esi



mov eax, DWORD[ebp  - 12]
add eax,1
mov DWORD[ebp - 20], eax
mov ebx, DWORD[ebp - 20]
sub ebx, 1
lea edi, [a]
mov esi, [edi + ebx * 4]
mov DWORD[ebp - 24], esi

mov ecx,DWORD[ebp - 16]
mov edx,DWORD[ebp - 24]
xor eax, eax
cmp ecx, edx
setg al
mov DWORD[ebp - 16], eax

mov eax, DWORD[ebp - 16]
cmp eax , 0
je .L5


mov eax, DWORD[ebp  - 12]
add eax,1
mov DWORD[ebp - 24], eax
mov ebx, DWORD[ebp - 24]
sub ebx, 1
lea edi, [a]
mov esi, [edi + ebx * 4]
mov DWORD[ebp - 28], esi
mov eax, DWORD[ebp - 28]
mov DWORD[ebp  - 20], eax

mov ebx, DWORD[ebp  - 12]
sub ebx, 1
lea edi, [a]
mov esi, [edi + ebx * 4]
mov DWORD[ebp - 28], esi


mov eax, DWORD[ebp  - 12]
add eax,1
mov DWORD[ebp - 36], eax

mov eax, DWORD[ebp - 28]
mov ebx, DWORD[ebp - 36]
sub ebx, 1
lea edi, [a]
mov [edi + ebx*4], eax



mov eax, DWORD[ebp  - 20]
mov ebx, DWORD[ebp  - 12]
sub ebx, 1
lea edi, [a]
mov [edi + ebx*4], eax


jmp .L4
.L5:
.L4:

inc DWORD[ebp  - 12]
jmp .L2
.L3:
inc DWORD[ebp  - 4]
jmp .L0
.L1:


mov eax, 1
sub esp, 4
mov DWORD[ebp  - 32], eax
.L6:
mov ecx , 5
cmp DWORD[ebp  - 32], ecx
jg .L7
mov ebx, DWORD[ebp  - 32]
sub ebx, 1
lea edi, [a]
mov esi, [edi + ebx * 4]
mov DWORD[ebp - 36], esi

sub esp, 8
push DWORD[ebp - 36]
push format
call printf
add esp, 8
sub esp, 4
push newline
call printf
add esp, 4

inc DWORD[ebp  - 32]
jmp .L6
.L7:
leave
ret

suma11:
push ebp
mov ebp, esp


mov eax, DWORD[ebp + 8]
add eax,DWORD[ebp + 12]
mov DWORD[ebp - 4], eax

mov eax, DWORD[ebp - 4]
leave
ret


xor eax, eax
leave
ret
