global ft_strcmp

ft_strcmp:
.loop:
    mov al, byte [rdi]
    mov bl, byte [rsi]
    cmp al, 0
    je  .exit
    cmp al, bl
    jne .exit
    inc rdi
    inc rsi
    jmp .loop
.exit:
    movzx eax, al ;pour la taille passage de 8 a 32bits pour le return du int = 32 bits = 4octets
    movzx ecx, bl
    sub   eax, ecx
    ret