extern printf
global main

section .data
format db "%d ", 10, 0
i dd 0
x dd 0
y dd 0

section .text
main:push ebp
mov ebp, esp

mov eax, 10
mov DWORD[x], eax


mov eax, 2
mov DWORD[y], eax

mov eax, DWORD[x]
mov DWORD[ebp - 4], eax

mov eax, DWORD[y]
mov DWORD[ebp - 8], eax

mov eax, DWORD[ebp - 4]
add eax,DWORD[ebp - 8]
mov DWORD[ebp - 4], eax

push DWORD[ebp - 4]
push format
call printf
add esp, 8

mov eax, DWORD[x]
mov DWORD[ebp - 4], eax

mov eax, DWORD[y]
mov DWORD[ebp - 8], eax

mov eax, DWORD[ebp - 4]
sub eax,DWORD[ebp - 8]
mov DWORD[ebp - 4], eax

push DWORD[ebp - 4]
push format
call printf
add esp, 8

mov eax, DWORD[x]
mov DWORD[ebp - 4], eax

mov eax, DWORD[y]
mov DWORD[ebp - 8], eax

mov eax,DWORD[ebp - 4]
cdq
mov ecx,DWORD[ebp - 8]
imul ecx
mov DWORD[ebp - 4], eax

push DWORD[ebp - 4]
push format
call printf
add esp, 8

mov eax, DWORD[x]
mov DWORD[ebp - 4], eax

mov eax, DWORD[y]
mov DWORD[ebp - 8], eax

mov eax,DWORD[ebp - 4]
cdq
mov ecx,DWORD[ebp - 8]
idiv ecx
mov DWORD[ebp - 4], eax

push DWORD[ebp - 4]
push format
call printf
add esp, 8

mov eax, DWORD[x]
mov DWORD[ebp - 4], eax

mov eax, DWORD[ebp - 4]
add eax,2
mov DWORD[ebp - 4], eax

push DWORD[ebp - 4]
push format
call printf
add esp, 8

mov eax, DWORD[x]
mov DWORD[ebp - 4], eax

mov eax, DWORD[ebp - 4]
sub eax,2
mov DWORD[ebp - 4], eax

push DWORD[ebp - 4]
push format
call printf
add esp, 8

mov eax, DWORD[x]
mov DWORD[ebp - 4], eax


mov eax,DWORD[ebp - 4]
cdq
mov ecx,2
imul ecx
mov DWORD[ebp - 4], eax

push DWORD[ebp - 4]
push format
call printf
add esp, 8

mov eax, DWORD[x]
mov DWORD[ebp - 4], eax


mov eax,DWORD[ebp - 4]
cdq
mov ecx,2
idiv ecx
mov DWORD[ebp - 4], eax

push DWORD[ebp - 4]
push format
call printf
add esp, 8

mov eax, DWORD[y]
mov DWORD[ebp - 4], eax

mov eax, 10
add eax,DWORD[ebp - 4]
mov DWORD[ebp - 4], eax

push DWORD[ebp - 4]
push format
call printf
add esp, 8

mov eax, DWORD[y]
mov DWORD[ebp - 4], eax

mov eax, 10
sub eax,DWORD[ebp - 4]
mov DWORD[ebp - 4], eax

push DWORD[ebp - 4]
push format
call printf
add esp, 8


mov eax, DWORD[y]
mov DWORD[ebp - 4], eax

mov eax,10
cdq
mov ecx,DWORD[ebp - 4]
imul ecx
mov DWORD[ebp - 4], eax

push DWORD[ebp - 4]
push format
call printf
add esp, 8


mov eax, DWORD[y]
mov DWORD[ebp - 4], eax

mov eax,10
cdq
mov ecx,DWORD[ebp - 4]
idiv ecx
mov DWORD[ebp - 4], eax

push DWORD[ebp - 4]
push format
call printf
add esp, 8


push 12
push format
call printf
add esp, 8


push 8
push format
call printf
add esp, 8


push 20
push format
call printf
add esp, 8


push 5
push format
call printf
add esp, 8


mov eax, 10
mov DWORD[i], eax

.L0:
mov eax, DWORD[i]
mov DWORD[ebp - 4], eax

mov eax, DWORD[ebp - 4]
cmp eax , 0
jz .L1
mov eax, DWORD[i]
mov DWORD[ebp - 8], eax

push DWORD[ebp - 8]
push format
call printf
add esp, 8

mov eax, DWORD[i]
mov DWORD[ebp - 8], eax

mov eax, DWORD[ebp - 8]
sub eax,1
mov DWORD[ebp - 8], eax

mov eax, DWORD[ebp - 8]
mov DWORD[i], eax


jmp .L0
.L1:
mov eax, DWORD[i]
mov DWORD[ebp - 4], eax

mov eax, DWORD[ebp - 4]
add eax,1
mov DWORD[ebp - 4], eax

mov eax, DWORD[ebp - 4]
mov DWORD[i], eax

mov eax, DWORD[i]
mov DWORD[ebp - 4], eax

mov eax, DWORD[ebp - 4]
cmp eax , 0
jz .L2

push 100
push format
call printf
add esp, 8


jmp .L3
.L2:

push 0
push format
call printf
add esp, 8

.L3:
mov eax, DWORD[i]
mov DWORD[ebp - 4], eax

mov eax, DWORD[ebp - 4]
sub eax,1
mov DWORD[ebp - 4], eax

mov eax, DWORD[ebp - 4]
mov DWORD[i], eax

mov eax, DWORD[i]
mov DWORD[ebp - 4], eax

mov eax, DWORD[ebp - 4]
cmp eax , 0
jz .L4

push 100
push format
call printf
add esp, 8


jmp .L5
.L4:

push 0
push format
call printf
add esp, 8

.L5:
leave
ret