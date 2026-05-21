global  ft_write
extern __errno_location

section .text

ft_write:
    mov rax, 1
syscall
    cmp rax, 0
    jge .exit

    push    rax
    call    __errno_location wrt ..plt
    pop rcx
    neg rcx
    mov [rax], ecx
    mov rax, -1
    ret

.exit:
    ret