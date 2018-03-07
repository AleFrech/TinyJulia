extern printf
global main

section .data
format db "%d ", 10, 0
x dd 0
y dd 0

section .text
main:push ebp
mov ebp, esp

mov eax, 7
mov DWORD[x], eax
mov eax, DWORD[x]
mov DWORD[ebp - 4], eax
mov eax, DWORD[ebp - 4]
add eax,10
mov DWORD[ebp - 8], eax


mov eax, DWORD[x]
mov DWORD[ebp - 12], eax
mov eax,5
cdq
mov ecx,DWORD[ebp - 12]
cdq
imul ecx
mov DWORD[ebp - 16], eax
mov eax, DWORD[ebp - 8]
sub eax,DWORD[ebp - 16]
mov DWORD[ebp - 20], eax

mov eax, DWORD[ebp - 20]
mov DWORD[y], eax
mov eax, DWORD[y]
mov DWORD[ebp - 24], eax

mov eax,DWORD[ebp - 24]
cdq
mov ecx,3
cdq
idiv ecx
mov DWORD[ebp - 28], eax

mov eax,DWORD[ebp - 28]
cdq
mov ecx,-1
cdq
imul ecx
mov DWORD[ebp - 32], eax
push DWORD[ebp - 32]
push format
call printf
add esp, 8

leave
ret