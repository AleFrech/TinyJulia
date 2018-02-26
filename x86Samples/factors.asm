; ebp+8 = number
; ebp+12 = count
; ebp+16 = f[]
; ebp-4 = index
; ebp-8 = i
factors:
    push ebp
    mov ebp, esp
    sub esp, 8

    mov DWORD [ebp-4], 0
    mov DWORD [ebp-8], 1
for:
    cmp DWORD [ebp-8], DWORD [ebp+8]
    jg for_end
    mov eax, [ebp+8]
    cdq
    mov ebx, [ebp-8]
    idiv ebx
    cmp edx, 0
    je if_body
    inc DWORD [ebp-8]
    jmp for

if_body:
    ;f[index] = i
    inc DWORD [ebp-4]
    cmp DWORD [ebp-4], DWORD [ebp+12]
    je for_end
    jmp for
   

for_end:
    mov eax, [ebp-4]
    leave ret
