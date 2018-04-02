extern printf
extern power
global main

section .bss
a resb 100

section .data
format db "%d", 0
formatString db "%s", 0
newline db "" ,10 ,0
literal0 db "---------------Ya Ordenado----------------------", 0

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
.L12:
mov ecx , 11
cmp DWORD[ebp  - 4], ecx
jg .L13
mov ebx, DWORD[ebp  - 4]
sub ebx, 1
lea edi, [a]
mov esi, [edi + ebx * 4]
mov DWORD[ebp - 8], esi

sub esp, 8
push DWORD[ebp - 8]
push format
call printf
add esp, 8
sub esp, 4
push newline
call printf
add esp, 4

inc DWORD[ebp  - 4]
jmp .L12
.L13:
sub esp, 8
push literal0
push  formatString
call printf
add esp, 8
sub esp, 4
push newline
call printf
add esp, 4



push 11
push 0
call quickSort11
add esp, 8
mov DWORD[ebp - 8], eax




mov eax, 1
sub esp, 4
mov DWORD[ebp  - 8], eax
.L14:
mov ecx , 11
cmp DWORD[ebp  - 8], ecx
jg .L15
mov ebx, DWORD[ebp  - 8]
sub ebx, 1
lea edi, [a]
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

inc DWORD[ebp  - 8]
jmp .L14
.L15:
leave
ret

quickSort11:
push ebp
mov ebp, esp
sub esp, 20
mov eax, DWORD[ebp + 8]
mov DWORD[ebp  - 4], eax

mov eax, DWORD[ebp + 12]
mov DWORD[ebp  - 8], eax

mov eax, 0
mov DWORD[ebp  - 12], eax



mov eax, DWORD[ebp + 8]
add eax,DWORD[ebp + 12]
mov DWORD[ebp - 20], eax


mov eax,DWORD[ebp - 20]
cdq
mov ecx,2
idiv ecx
mov DWORD[ebp - 20], eax
mov ebx, DWORD[ebp - 20]
sub ebx, 1
lea edi, [a]
mov esi, [edi + ebx * 4]
mov DWORD[ebp - 24], esi
mov eax, DWORD[ebp - 24]
mov DWORD[ebp  - 16], eax

.L0:


mov ecx,DWORD[ebp  - 4]
mov edx,DWORD[ebp  - 8]
xor eax, eax
cmp ecx, edx
setle al
mov DWORD[ebp - 24], eax

mov eax, DWORD[ebp - 24]
cmp eax , 0
jz .L1
.L2:
mov ebx, DWORD[ebp  - 4]
sub ebx, 1
lea edi, [a]
mov esi, [edi + ebx * 4]
mov DWORD[ebp - 28], esi


mov ecx,DWORD[ebp - 28]
mov edx,DWORD[ebp  - 16]
xor eax, eax
cmp ecx, edx
setl al
mov DWORD[ebp - 28], eax

mov eax, DWORD[ebp - 28]
cmp eax , 0
jz .L3


mov eax, DWORD[ebp  - 4]
add eax,1
mov DWORD[ebp - 32], eax
mov eax, DWORD[ebp - 32]
mov DWORD[ebp  - 4], eax



jmp .L2
.L3:
.L4:
mov ebx, DWORD[ebp  - 8]
sub ebx, 1
lea edi, [a]
mov esi, [edi + ebx * 4]
mov DWORD[ebp - 28], esi


mov ecx,DWORD[ebp - 28]
mov edx,DWORD[ebp  - 16]
xor eax, eax
cmp ecx, edx
setg al
mov DWORD[ebp - 28], eax

mov eax, DWORD[ebp - 28]
cmp eax , 0
jz .L5


mov eax, DWORD[ebp  - 8]
sub eax,1
mov DWORD[ebp - 32], eax
mov eax, DWORD[ebp - 32]
mov DWORD[ebp  - 8], eax



jmp .L4
.L5:


mov ecx,DWORD[ebp  - 4]
mov edx,DWORD[ebp  - 8]
xor eax, eax
cmp ecx, edx
setle al
mov DWORD[ebp - 28], eax

mov eax, DWORD[ebp - 28]
cmp eax , 0
je .L7
mov ebx, DWORD[ebp  - 4]
sub ebx, 1
lea edi, [a]
mov esi, [edi + ebx * 4]
mov DWORD[ebp - 32], esi
mov eax, DWORD[ebp - 32]
mov DWORD[ebp  - 12], eax


mov ebx, DWORD[ebp  - 8]
sub ebx, 1
lea edi, [a]
mov esi, [edi + ebx * 4]
mov DWORD[ebp - 32], esi

mov eax, DWORD[ebp - 32]
mov ebx, DWORD[ebp  - 4]
sub ebx, 1
lea edi, [a]
mov [edi + ebx*4], eax



mov eax, DWORD[ebp  - 12]
mov ebx, DWORD[ebp  - 8]
sub ebx, 1
lea edi, [a]
mov [edi + ebx*4], eax




mov eax, DWORD[ebp  - 4]
add eax,1
mov DWORD[ebp - 32], eax
mov eax, DWORD[ebp - 32]
mov DWORD[ebp  - 4], eax




mov eax, DWORD[ebp  - 8]
sub eax,1
mov DWORD[ebp - 32], eax
mov eax, DWORD[ebp - 32]
mov DWORD[ebp  - 8], eax


jmp .L6
.L7:
.L6:


jmp .L0
.L1:


mov ecx,DWORD[ebp + 8]
mov edx,DWORD[ebp  - 8]
xor eax, eax
cmp ecx, edx
setl al
mov DWORD[ebp - 24], eax

mov eax, DWORD[ebp - 24]
cmp eax , 0
je .L9


push DWORD[ebp  - 8]
push DWORD[ebp + 8]
call quickSort11
add esp, 8
mov DWORD[ebp - 28], eax


jmp .L8
.L9:
.L8:



mov ecx,DWORD[ebp  - 4]
mov edx,DWORD[ebp + 12]
xor eax, eax
cmp ecx, edx
setl al
mov DWORD[ebp - 24], eax

mov eax, DWORD[ebp - 24]
cmp eax , 0
je .L11


push DWORD[ebp + 12]
push DWORD[ebp  - 4]
call quickSort11
add esp, 8
mov DWORD[ebp - 28], eax


jmp .L10
.L11:
.L10:


xor eax, eax
leave
ret
