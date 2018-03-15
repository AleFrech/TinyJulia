extern printf
global main

section .data
formatln db "%d ", 10, 0
format db "%d ", 0
formatStringln db "%s ", 10, 0
formatString db "%s ", 0
x dd 0
y dd 0

section .text
main:
push ebp
mov ebp, esp
mov eax, 10
mov DWORD [x], eax

mov eax, 3
mov DWORD [y], eax


push DWORD [x]
push formatln
call printf
add esp, 8


push DWORD [y]
push formatln
call printf
add esp, 8



mov eax,DWORD [x]
cdq
mov ecx,-1
imul ecx
mov DWORD[ebp - 4], eax


push DWORD[ebp - 4]
push formatln
call printf
add esp, 8



mov eax,DWORD [y]
cdq
mov ecx,-1
imul ecx
mov DWORD[ebp - 4], eax


push DWORD[ebp - 4]
push formatln
call printf
add esp, 8



mov eax, DWORD [x]
add eax,DWORD [y]
mov DWORD[ebp - 4], eax

push DWORD[ebp - 4]
push formatln
call printf
add esp, 8



mov eax, DWORD [x]
sub eax,DWORD [y]
mov DWORD[ebp - 4], eax

push DWORD[ebp - 4]
push formatln
call printf
add esp, 8



mov eax,DWORD [x]
cdq
mov ecx,DWORD [y]
imul ecx
mov DWORD[ebp - 4], eax

push DWORD[ebp - 4]
push formatln
call printf
add esp, 8



mov eax,DWORD [x]
cdq
mov ecx,DWORD [y]
idiv ecx
mov DWORD[ebp - 4], eax

push DWORD[ebp - 4]
push formatln
call printf
add esp, 8



mov eax,DWORD [x]
cdq
mov ecx,DWORD [y]
idiv ecx
mov DWORD[ebp - 4], edx

push DWORD[ebp - 4]
push formatln
call printf
add esp, 8

leave
ret

