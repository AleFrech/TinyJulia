extern printf
extern power
global main

section .bss

section .data
format db "%d", 0
formatString db "%s", 0
nothing db "",0
true db "true",0
false db "false",0
newline db "" ,10 ,0
literal0 db "x = ", 0
literal1 db "y = ", 0
literal10 db "x $ y = ", 0
literal11 db "-8 >> 3 = ", 0
literal12 db "2 << 4 = ", 0
literal2 db "boolValue = ", 0
literal3 db "x < y && x > y = ", 0
literal4 db "x < y || x > y = ", 0
literal5 db "~x = ", 0
literal6 db "~y = ", 0
literal7 db "!boolValue = ", 0
literal8 db "x & y = ", 0
literal9 db "x | y = ", 0
boolValue dd 0
x dd 0
y dd 0
z dd 0

section .text
main:
push ebp
mov ebp, esp
mov eax, 10
mov DWORD [x], eax

mov eax, 20
mov DWORD [y], eax

mov eax, 1
mov DWORD [boolValue], eax

sub esp, 8
push literal0
push  formatString
call printf
add esp, 8

sub esp, 8
push DWORD [x]
push format
call printf
add esp, 8
sub esp, 4
push newline
call printf
add esp, 4

sub esp, 8
push literal1
push  formatString
call printf
add esp, 8

sub esp, 8
push DWORD [y]
push format
call printf
add esp, 8
sub esp, 4
push newline
call printf
add esp, 4

sub esp, 8
push literal2
push  formatString
call printf
add esp, 8

mov edx, DWORD [boolValue]
cmp edx, 0
je .L0
sub esp, 8
push true
jmp .L1
push formatString
.L0:
push false
push formatString
.L1:
call printf
add esp, 8
sub esp, 4
push newline
call printf
add esp, 4

sub esp, 8
push literal3
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
jz .L2
mov eax ,DWORD[ebp - 8]
test eax, eax
jnz .L3
.L2:
mov DWORD[ebp - 4], 0
jmp .L4
.L3:
mov DWORD[ebp - 4], 1
jmp .L4
.L4:

mov edx, DWORD[ebp - 4]
cmp edx, 0
je .L5
sub esp, 8
push true
jmp .L6
push formatString
.L5:
push false
push formatString
.L6:
call printf
add esp, 8
sub esp, 4
push newline
call printf
add esp, 4

sub esp, 8
push literal4
push  formatString
call printf
add esp, 8


mov ecx,DWORD [x]
mov edx,DWORD [y]
xor eax, eax
cmp ecx, edx
setl al
mov DWORD[ebp - 8], eax



mov ecx,DWORD [x]
mov edx,DWORD [y]
xor eax, eax
cmp ecx, edx
setg al
mov DWORD[ebp - 12], eax

mov eax, DWORD[ebp - 8]
test eax, eax
jnz .L8
mov eax ,DWORD[ebp - 12]
test eax, eax
jnz .L8
.L7:
mov DWORD[ebp - 8], 0
jmp .L9
.L8:
mov DWORD[ebp - 8], 1
jmp .L9
.L9:

mov edx, DWORD[ebp - 8]
cmp edx, 0
je .L10
sub esp, 8
push true
jmp .L11
push formatString
.L10:
push false
push formatString
.L11:
call printf
add esp, 8
sub esp, 4
push newline
call printf
add esp, 4

sub esp, 8
push literal5
push  formatString
call printf
add esp, 8

mov eax,DWORD [x]
not eax
mov DWORD[ebp - 12], eax

sub esp, 8
push DWORD[ebp - 12]
push format
call printf
add esp, 8
sub esp, 4
push newline
call printf
add esp, 4

sub esp, 8
push literal6
push  formatString
call printf
add esp, 8

mov eax,DWORD [y]
not eax
mov DWORD[ebp - 12], eax

sub esp, 8
push DWORD[ebp - 12]
push format
call printf
add esp, 8
sub esp, 4
push newline
call printf
add esp, 4

sub esp, 8
push literal7
push  formatString
call printf
add esp, 8

mov eax,DWORD [boolValue]
xor ecx, ecx
test eax, eax
setz cl
mov DWORD[ebp - 12], ecx

mov edx, DWORD[ebp - 12]
cmp edx, 0
je .L12
sub esp, 8
push true
jmp .L13
push formatString
.L12:
push false
push formatString
.L13:
call printf
add esp, 8
sub esp, 4
push newline
call printf
add esp, 4

sub esp, 8
push literal8
push  formatString
call printf
add esp, 8


mov eax,DWORD [x]
cdq
mov ecx,DWORD [y]
and eax, ecx
mov DWORD[ebp - 16], eax

sub esp, 8
push DWORD[ebp - 16]
push format
call printf
add esp, 8
sub esp, 4
push newline
call printf
add esp, 4

sub esp, 8
push literal9
push  formatString
call printf
add esp, 8


mov eax,DWORD [x]
cdq
mov ecx,DWORD [y]
or eax, ecx
mov DWORD[ebp - 16], eax

sub esp, 8
push DWORD[ebp - 16]
push format
call printf
add esp, 8
sub esp, 4
push newline
call printf
add esp, 4

sub esp, 8
push literal10
push  formatString
call printf
add esp, 8


mov eax,DWORD [x]
cdq
mov ecx,DWORD [y]
xor eax, ecx
mov DWORD[ebp - 16], eax

sub esp, 8
push DWORD[ebp - 16]
push format
call printf
add esp, 8
sub esp, 4
push newline
call printf
add esp, 4

sub esp, 8
push literal11
push  formatString
call printf
add esp, 8



mov eax,-8
mov ecx,3
sar eax, cl
mov DWORD[ebp - 16], eax

sub esp, 8
push DWORD[ebp - 16]
push format
call printf
add esp, 8
sub esp, 4
push newline
call printf
add esp, 4

sub esp, 8
push literal12
push  formatString
call printf
add esp, 8

sub esp, 8
push 32
push format
call printf
add esp, 8
sub esp, 4
push newline
call printf
add esp, 4


mov eax,1
xor ecx, ecx
test eax, eax
setz cl
mov DWORD[ebp - 16], ecx
mov eax, DWORD[ebp - 16]
mov DWORD [z], eax


mov eax,DWORD [z]
xor ecx, ecx
test eax, eax
setz cl
mov DWORD[ebp - 20], ecx

mov edx, DWORD[ebp - 20]
cmp edx, 0
je .L14
sub esp, 8
push true
jmp .L15
push formatString
.L14:
push false
push formatString
.L15:
call printf
add esp, 8
sub esp, 4
push newline
call printf
add esp, 4

leave
ret

