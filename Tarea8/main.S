extern printf
global main

section .data
formatln db "%d ", 10, 0
format db "%d ", 0
x dd 0
y dd 0

section .text
main:push ebp
mov ebp, esp

mov eax, 10
mov DWORD[x], eax


mov eax, 20
mov DWORD[y], eax

mov eax, DWORD[x]
mov DWORD[ebp - 4], eax

push DWORD[ebp - 4]
push formatln
call printf
add esp, 8

mov eax, DWORD[y]
mov DWORD[ebp - 4], eax

push DWORD[ebp - 4]
push formatln
call printf
add esp, 8

mov eax, DWORD[x]
mov DWORD[ebp - 4], eax

mov eax, DWORD[y]
mov DWORD[ebp - 8], eax

mov ecx,DWORD[ebp - 4]
mov edx,DWORD[ebp - 8]
xor eax, eax
cmp ecx, edx
setg al
mov DWORD[ebp - 4], eax

push DWORD[ebp - 4]
push formatln
call printf
add esp, 8

mov eax, DWORD[x]
mov DWORD[ebp - 4], eax

mov eax, DWORD[y]
mov DWORD[ebp - 8], eax

mov ecx,DWORD[ebp - 4]
mov edx,DWORD[ebp - 8]
xor eax, eax
cmp ecx, edx
setl al
mov DWORD[ebp - 4], eax

push DWORD[ebp - 4]
push formatln
call printf
add esp, 8

mov eax, DWORD[x]
mov DWORD[ebp - 4], eax

mov eax, DWORD[y]
mov DWORD[ebp - 8], eax

mov ecx,DWORD[ebp - 4]
mov edx,DWORD[ebp - 8]
xor eax, eax
cmp ecx, edx
setge al
mov DWORD[ebp - 4], eax

push DWORD[ebp - 4]
push formatln
call printf
add esp, 8

mov eax, DWORD[x]
mov DWORD[ebp - 4], eax

mov eax, DWORD[y]
mov DWORD[ebp - 8], eax

mov ecx,DWORD[ebp - 4]
mov edx,DWORD[ebp - 8]
xor eax, eax
cmp ecx, edx
setle al
mov DWORD[ebp - 4], eax

push DWORD[ebp - 4]
push formatln
call printf
add esp, 8

mov eax, DWORD[x]
mov DWORD[ebp - 4], eax

mov eax, DWORD[y]
mov DWORD[ebp - 8], eax

mov ecx,DWORD[ebp - 4]
mov edx,DWORD[ebp - 8]
xor eax, eax
cmp ecx, edx
setne al
mov DWORD[ebp - 4], eax

push DWORD[ebp - 4]
push formatln
call printf
add esp, 8

mov eax, DWORD[x]
mov DWORD[ebp - 4], eax

mov eax, DWORD[y]
mov DWORD[ebp - 8], eax

mov ecx,DWORD[ebp - 4]
mov edx,DWORD[ebp - 8]
xor eax, eax
cmp ecx, edx
sete al
mov DWORD[ebp - 4], eax

push DWORD[ebp - 4]
push formatln
call printf
add esp, 8

leave
ret