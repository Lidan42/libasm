global ft_strdup

extern __errno_location
extern malloc
extern ft_strlen
extern ft_strcpy

ft_strdup:
    push    rdi
    call    ft_strlen wrt ..plt
    inc     rax         ;pour le /0
    mov     rdi, rax
    call    malloc wrt ..plt
    cmp     rax, 0
    je      .exit
    pop     rsi
    mov     rdi, rax    ;rsi et rdi pour arg strcpy
    push    rax         ;save le pointeur
    call    ft_strcpy wrt ..plt
    pop     rax
    ret

.exit:
    pop     rdi         ;stack alignement
    push    rax
    call    __errno_location wrt ..plt
    mov     dword [rax], 12
    pop     rax
    xor     eax, eax
    ret
