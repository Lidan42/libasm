NAME        := libasm.a

NASM        := nasm
NASMFLAGS   := -f elf64
AR          := ar
ARFLAGS     := rcs
CC          := gcc
CFLAGS      := -Wall -Wextra -Werror

SRCS        := ft_write.s \
			ft_read.s \
			ft_strlen.s \
			ft_strcpy.s \
			ft_strcmp.s \
			ft_strdup.s

OBJS        := $(SRCS:.s=.o)

# Couleurs
GREEN       := \033[0;32m
YELLOW      := \033[0;33m
RESET       := \033[0m
 
# ============================================================
 
.PHONY: all clean fclean re test
 
all: $(NAME)
 
$(NAME): $(OBJS)
	@$(AR) $(ARFLAGS) $@ $^
	@printf "%b\n" "$(GREEN)✓ $(NAME) compilé$(RESET)"
 
%.o: %.s
	@$(NASM) $(NASMFLAGS) $< -o $@
	@printf "%b\n" "$(YELLOW)  asm $<$(RESET)"
 
# ============================================================
 
test: $(NAME)
	@$(CC) $(CFLAGS) main.c -L. -lasm -o test_libasm
	@printf "%b\n" "$(GREEN)✓ test_libasm compilé$(RESET)"
	@valgrind ./test_libasm
 
# ============================================================
 
clean:
	@rm -f $(OBJS)
	@printf "%b\n" "$(YELLOW)  objets supprimés$(RESET)"
 
fclean: clean
	@rm -f $(NAME) test_libasm
	@printf "%b\n" "$(YELLOW)  $(NAME) supprimé$(RESET)"
 
re: fclean all
 
