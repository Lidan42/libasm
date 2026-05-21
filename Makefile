NAME        := libasm.a

NASM        := nasm
NASMFLAGS   := -f elf64
AR          := ar
ARFLAGS     := rcs
CC          := gcc
CFLAGS      := -Wall -Wextra -Werror

SRCS        := ft_write.s \
			ft_read.s \
			ft_strlen.s

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
	@echo "$(GREEN)✓ $(NAME) compilé$(RESET)"
 
%.o: %.s
	@$(NASM) $(NASMFLAGS) $< -o $@
	@echo "$(YELLOW)  asm $<$(RESET)"
 
# ============================================================
 
test: $(NAME)
	@$(CC) $(CFLAGS) main.c -L. -lasm -o test_libasm
	@echo "$(GREEN)✓ test_libasm compilé$(RESET)"
	@./test_libasm
 
# ============================================================
 
clean:
	@rm -f $(OBJS)
	@echo "$(YELLOW)  objets supprimés$(RESET)"
 
fclean: clean
	@rm -f $(NAME) test_libasm
	@echo "$(YELLOW)  $(NAME) supprimé$(RESET)"
 
re: fclean all
 
