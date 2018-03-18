extern printf
extern power
global main

section .data
formatln db "%d", 10, 0
format db "%d", 0
formatStringln db "%s", 10, 0
formatString db "%s", 0
literal0 db "x = ", 0
literal1 db "", 10, "", 0
literal10 db "~y = ", 0
literal11 db "", 10, "", 0
literal12 db "x & y = ", 0
literal13 db "", 10, "", 0
literal14 db "x | y = ", 0
literal15 db "", 10, "", 0
literal16 db "x $ y = ", 0
literal17 db "", 10, "", 0
literal2 db "y = ", 0
literal3 db "", 10, "", 0
literal4 db "x < y && x > y = ", 0
literal5 db "", 10, "", 0
literal6 db "x < y || x > y = ", 0
literal7 db "", 10, "", 0
literal8 db "~x = ", 0
literal9 db "", 10, "", 0
x dd 0
y dd 0

section .text
main:
push ebp
mov ebp, esp
mov eax, 10
mov DWORD [x], eax

mov eax, 20
mov DWORD [y], eax

push literal0
push  formatString
call printf
add esp, 8

push DWORD [x]
push format
call printf
add esp, 8
push literal1
push  formatString
call printf
add esp, 8

push literal2
push  formatString
call printf
add esp, 8

push DWORD [y]
push format
call printf
add esp, 8
push literal3
push  formatString
call printf
add esp, 8

push literal4
push  formatString
call printf
add esp, 8


mov ecx,DWORD [x]
mov edx,DWORD [y]
xor eax, eax
cmp ecx, edx
setl al
mov DWORD[ebp - 4], eax



mov ecx,DWORD [x]
mov edx,DWORD [y]
xor eax, eax
cmp ecx, edx
setg al
mov DWORD[ebp - 8], eax

mov eax, DWORD[ebp - 4]
test eax, eax
jz .L0
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

push DWORD[ebp - 4]
push format
call printf
add esp, 8
push literal5
push  formatString
call printf
add esp, 8

push literal6
push  formatString
call printf
add esp, 8


mov ecx,DWORD [x]
mov edx,DWORD [y]
xor eax, eax
cmp ecx, edx
setl al
mov DWORD[ebp - 4], eax



mov ecx,DWORD [x]
mov edx,DWORD [y]
xor eax, eax
cmp ecx, edx
setg al
mov DWORD[ebp - 8], eax

mov eax, DWORD[ebp - 4]
test eax, eax
jnz .L4
mov eax ,DWORD[ebp - 8]
test eax, eax
jnz .L4
.L3:
mov DWORD[ebp - 4], 0
jmp .L5
.L4:
mov DWORD[ebp - 4], 1
jmp .L5
.L5:

push DWORD[ebp - 4]
push format
call printf
add esp, 8
push literal7
push  formatString
call printf
add esp, 8

push literal8
push  formatString
call printf
add esp, 8

mov eax,DWORD [x]
not eax
mov DWORD[ebp - 4], eax

push DWORD[ebp - 4]
push format
call printf
add esp, 8
push literal9
push  formatString
call printf
add esp, 8

push literal10
push  formatString
call printf
add esp, 8

mov eax,DWORD [y]
not eax
mov DWORD[ebp - 4], eax

push DWORD[ebp - 4]
push format
call printf
add esp, 8
push literal11
push  formatString
call printf
add esp, 8

push literal12
push  formatString
call printf
add esp, 8


mov eax,DWORD [x]
cdq
mov ecx,DWORD [y]
and eax, ecx
mov DWORD[ebp - 4], eax

push DWORD[ebp - 4]
push format
call printf
add esp, 8
push literal13
push  formatString
call printf
add esp, 8

push literal14
push  formatString
call printf
add esp, 8


mov eax,DWORD [x]
cdq
mov ecx,DWORD [y]
or eax, ecx
mov DWORD[ebp - 4], eax

push DWORD[ebp - 4]
push format
call printf
add esp, 8
push literal15
push  formatString
call printf
add esp, 8

push literal16
push  formatString
call printf
add esp, 8


mov eax,DWORD [x]
cdq
mov ecx,DWORD [y]
xor eax, ecx
mov DWORD[ebp - 4], eax

push DWORD[ebp - 4]
push format
call printf
add esp, 8
push literal17
push  formatString
call printf
add esp, 8

leave
ret

