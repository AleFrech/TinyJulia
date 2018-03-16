extern printf
extern power
global main

section .data
formatln db "%d", 10, 0
format db "%d", 0
formatStringln db "%s", 10, 0
formatString db "%s", 0
literal0 db "trueValue = ", 0
literal1 db "", 10, "", 0
literal10 db "x >= y = ", 0
literal11 db "", 10, "", 0
literal12 db "x < y = ", 0
literal13 db "", 10, "", 0
literal14 db "x <= y = ", 0
literal15 db "", 10, "", 0
literal16 db "x != y = ", 0
literal17 db "", 10, "", 0
literal18 db "x == y = ", 0
literal19 db "", 10, "", 0
literal2 db "falseValue = ", 0
literal20 db "x != y = ", 0
literal21 db "", 10, "", 0
literal22 db "trueValue == falseValue = ", 0
literal23 db "", 10, "", 0
literal24 db "trueValue != falseValue =", 0
literal25 db "", 10, "", 0
literal3 db "", 10, "", 0
literal4 db "x = ", 0
literal5 db "", 10, "", 0
literal6 db "y = ", 0
literal7 db "", 10, "", 0
literal8 db "x > y = ", 0
literal9 db "", 10, "", 0
falseValue dd 0
trueValue dd 0
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

mov eax, 1
mov DWORD [trueValue], eax

mov eax, 0
mov DWORD [falseValue], eax

push literal0
push  formatString
call printf
add esp, 8

push DWORD [trueValue]
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

push DWORD [falseValue]
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

push DWORD [x]
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

push DWORD [y]
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


mov ecx,DWORD [x]
mov edx,DWORD [y]
xor eax, eax
cmp ecx, edx
setg al
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


mov ecx,DWORD [x]
mov edx,DWORD [y]
xor eax, eax
cmp ecx, edx
setge al
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


mov ecx,DWORD [x]
mov edx,DWORD [y]
xor eax, eax
cmp ecx, edx
setl al
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


mov ecx,DWORD [x]
mov edx,DWORD [y]
xor eax, eax
cmp ecx, edx
setle al
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


mov ecx,DWORD [x]
mov edx,DWORD [y]
xor eax, eax
cmp ecx, edx
setne al
mov DWORD[ebp - 4], eax

push DWORD[ebp - 4]
push format
call printf
add esp, 8
push literal17
push  formatString
call printf
add esp, 8

push literal18
push  formatString
call printf
add esp, 8


mov ecx,DWORD [x]
mov edx,DWORD [y]
xor eax, eax
cmp ecx, edx
sete al
mov DWORD[ebp - 4], eax

push DWORD[ebp - 4]
push format
call printf
add esp, 8
push literal19
push  formatString
call printf
add esp, 8

push literal20
push  formatString
call printf
add esp, 8


mov ecx,DWORD [x]
mov edx,DWORD [y]
xor eax, eax
cmp ecx, edx
setne al
mov DWORD[ebp - 4], eax

push DWORD[ebp - 4]
push format
call printf
add esp, 8
push literal21
push  formatString
call printf
add esp, 8

push literal22
push  formatString
call printf
add esp, 8


mov ecx,DWORD [trueValue]
mov edx,DWORD [falseValue]
xor eax, eax
cmp ecx, edx
sete al
mov DWORD[ebp - 4], eax

push DWORD[ebp - 4]
push format
call printf
add esp, 8
push literal23
push  formatString
call printf
add esp, 8

push literal24
push  formatString
call printf
add esp, 8


mov ecx,DWORD [trueValue]
mov edx,DWORD [falseValue]
xor eax, eax
cmp ecx, edx
setne al
mov DWORD[ebp - 4], eax

push DWORD[ebp - 4]
push format
call printf
add esp, 8
push literal25
push  formatString
call printf
add esp, 8

leave
ret

