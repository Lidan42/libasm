global  ft_write

ft_write:
    mov rax 1   ;
syscall
    cmp rax, 0
    jge exit
    ret

exit:
    ret