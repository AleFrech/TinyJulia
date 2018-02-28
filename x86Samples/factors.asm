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
    mov eax, [ebp+8]
    cmp DWORD [ebp-8], eax
    jg for_end
    cdq
    mov ebx, [ebp-8]
    idiv ebx
    cmp edx, 0
    jne if_end

    mov ebx, DWORD [ebp-4] ;ebx =index
    mov ecx, DWORD [ebp+16] ; ecx = f[]
    mov edx, DWORD [ebp-8] ; edx = i
    mov DWORD [ecx+4*ebx] = edx ; f[index] =i
    inc DWORD [ebp-4] ; index ++
    mov ebx, DWORD [ebp-4]
    cmp ebx, DWORD [ebp+12]
    je for_end

if_end:
    inc DWORD [ebp-8]
    jmp for
for_end:
    mov eax, [ebp-4]
    leave 
    ret