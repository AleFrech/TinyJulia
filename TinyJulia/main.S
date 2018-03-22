extern printf
extern power
global main

section .bss

section .data
format db "%d", 0
formatString db "%s", 0
newline db "" ,10 ,0

section .text
main:
push ebp
mov ebp, esp

push 5
call factorial1
add esp, 4
mov DWORD[ebp - 8], eax

sub esp, 8
push DWORD[ebp - 8]
push format
call printf
add esp, 8
sub esp, 4
push newline
call printf
add esp, 4

leave
ret

factorial1:
push ebp
mov ebp, esp
sub esp, 8


mov ecx,DWORD[ebp + 8]
mov edx,1
xor eax, eax
cmp ecx, edx
sete al
mov DWORD[ebp - 4], eax



mov ecx,DWORD[ebp + 8]
mov edx,0
xor eax, eax
cmp ecx, edx
sete al
mov DWORD[ebp - 8], eax

mov eax, DWORD[ebp - 4]
test eax, eax
jnz .L1
mov eax ,DWORD[ebp - 8]
test eax, eax
jnz .L1
.L0:
mov DWORD[ebp - 4], 0
jmp .L2
.L1:
mov DWORD[ebp - 4], 1
jmp .L2
.L2:

mov eax, DWORD[ebp - 4]
cmp eax , 0
je .L4

mov eax, 1
leave
ret

jmp .L3
.L4:
.L3:



mov eax, DWORD[ebp + 8]
sub eax,1
mov DWORD[ebp - 8], eax
push DWORD[ebp - 8]
call factorial1
add esp, 4
mov DWORD[ebp - 8], eax


mov eax,DWORD[ebp - 8]
cdq
mov ecx,DWORD[ebp + 8]
imul ecx
mov DWORD[ebp - 8], eax

mov eax, DWORD[ebp - 8]
leave
ret


xor eax, eax
leave
ret
