mov eax, 7
push eax
call isPrime
add esp, 4
#show eax
#stop

isPrime:
    push ebp
    mov ebp, esp
    sub esp, 8

    mov DWORD [ebp-8], 0
    mov DWORD [ebp-4], 2
for:
    mov eax, [ebp+8]
    cdq
    mov ebx, 2
    idiv ebx
    cmp DWORD [ebp-4], eax
    jge forEnd
    mov eax, [ebp+8]
    cdq
    mov ebx, [ebp-4]
    idiv ebx
    cmp edx, 0
    je trueCondition
    inc [ebp-4]

trueCondition:
    mov DWORD[ebp-8], 1
    jmp forEnd

forEnd:
    xor eax, eax
    cmp DWORD [ebp-8], 0
    sete al
    leave ret