extern printf
global main

section .data
formatln db "%d ", 10, 0
format db "%d ", 0
sumaa dd 0
sumab dd 0
x dd 0
y dd 0
z dd 0

section .text
main:
push ebp
mov ebp, esp

mov eax, 10
mov DWORD[x], eax

mov eax, 20
mov DWORD[y], eax

mov eax, DWORD[y]
mov DWORD[ebp - 4], eax
push DWORD[ebp - 4]
mov eax, DWORD[x]
mov DWORD[ebp - 8], eax
push DWORD[ebp - 8]
call suma
add esp, 8
mov DWORD[ebp - 8], eax
mov eax, DWORD[ebp - 8]
mov DWORD[z], eax

mov eax, DWORD[z]
mov DWORD[ebp - 8], eax

push DWORD[ebp - 8]
push formatln
call printf
add esp, 8

leave
ret

suma:
push ebp
mov ebp, esp
mov eax, DWORD [ebp+8]
mov DWORD [sumaa], eax
mov eax, DWORD [ebp+12]
mov DWORD [sumab], eax
mov eax, DWORD[sumaa]
mov DWORD[ebp - 4], eax

mov eax, DWORD[sumab]
mov DWORD[ebp - 8], eax

mov eax, DWORD[ebp - 4]
add eax,DWORD[ebp - 8]
mov DWORD[ebp - 4], eax

push DWORD[ebp - 4]
push formatln
call printf
add esp, 8


leave
ret
