extern printf
extern power
global main

section .data
format db "%d", 0
formatString db "%s", 0
newline db "" ,10 ,0
test1 dd 0

section .text
main:
push ebp
mov ebp, esp
mov eax, 1
mov DWORD [test1], eax

.L0:


mov ecx,DWORD [test1]
mov edx,10
xor eax, eax
cmp ecx, edx
setle al
mov DWORD[ebp - 4], eax

mov eax, DWORD[ebp - 4]
cmp eax , 0
jz .L1

push DWORD [test1]
push format
call printf
add esp, 8
push newline
call printf
add esp, 4



mov eax, DWORD [test1]
add eax,1
mov DWORD[ebp - 8], eax
mov eax, DWORD[ebp - 8]
mov DWORD [test1], eax



jmp .L0
.L1:
leave
ret

