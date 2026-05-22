global ft_strdup

extern __errno_location
extern malloc

ft_strdup:
    push    rdi
    call    ft_strlen
    inc     rax
    mov     rdi, rax
    call    malloc
    cmp     rax, 0
    je      .exit
    pop     rsi
    mov     rdi, rax
    push    rax
    call    ft_strcpy
    pop     rax
    ret

.exit:
    pop     rdi
    push    rax
    call    __errno_location wrt ..plt
    pop     rax
    mov     rax, 0
    ret
