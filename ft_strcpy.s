global  ft_strcpy

ft_strcpy:
    mov rax, rdi
.loop:
    mov al, byte [rsi]
    mov byte [rdi], al
    cmp byte [rdi], 0
    je  .exit
    inc rsi
    inc rdi
    jmp .loop
.exit:
    ret