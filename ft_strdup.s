global ft_strdup

extern __errno_location
extern malloc

ft_strdup:
    push rdi
    call ft_strlen
    inc rax
    call malloc
    cmp rax, 0
    je

.exit:

