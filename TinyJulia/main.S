extern printf
extern power
global main

section .data
formatln db "%d ", 10, 0
format db "%d ", 0
formatStringln db "%s ", 10, 0
formatString db "%s ", 0

section .text
main:
push ebp
mov ebp, esp

push 1
call rec
add esp, 4
mov DWORD[ebp - 4], eax


leave
ret

rec:
push ebp
mov ebp, esp
sub esp, 4

push DWORD[ebp + 8]
push formatln
call printf
add esp, 8



mov eax, DWORD[ebp + 8]
add eax,1
mov DWORD[ebp - 4], eax
push DWORD[ebp - 4]
call rec
add esp, 4
mov DWORD[ebp - 4], eax

mov eax, DWORD[ebp - 4]
leave
ret


xor eax, eax
leave
ret
