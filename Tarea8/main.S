extern printf
global main

section .data
formatln db "%d ", 10, 0
format db "%d ", 0
funcn dd 0
funcx dd 0
funcz dd 0
y dd 0

section .text
main:
push ebp
mov ebp, esp
mov eax, 10
mov DWORD[y], eax


mov eax, 20
mov DWORD[y], eax

push 5
call func
add esp, 4
mov DWORD[ebp - 4], eax

push DWORD[ebp - 4]
push format
call printf
add esp, 8

leave
ret

func:
push ebp
mov ebp, esp
mov eax, DWORD [ebp+8]
mov DWORD [funcn], eax
mov eax, 10
mov DWORD[funcx], eax

mov eax, DWORD[y]
mov DWORD[ebp - 4], eax

mov eax, DWORD[funcx]
mov DWORD[ebp - 8], eax

mov eax, DWORD[ebp - 4]
add eax,DWORD[ebp - 8]
mov DWORD[ebp - 4], eax

mov eax, DWORD[funcn]
mov DWORD[ebp - 8], eax

mov eax, DWORD[ebp - 4]
add eax,DWORD[ebp - 8]
mov DWORD[ebp - 4], eax
mov eax, DWORD[ebp - 4]
mov DWORD[funcz], eax

mov eax, DWORD[funcz]
mov DWORD[ebp - 4], eax

mov eax, DWORD[ebp - 4]
leave
ret


xor eax, eax
leave
ret
