
CC = clang
FLAGWS = -Wall -Wextra -Werror
AR = ar rcs
RM = /bin/rm -f

OBJS_DIR = ./objs/
NAME = push_swap
SRC_FILES = linked_utils.c linked_utils1.c main.c mouv.c mouv1.c mouv2.c check_input.c check_input1.c check_input2.c sorted_small.c cost.c algo.c algo1.c sorted_big.c algo2.c algo3.c algo4.c mouv3.c
C_OBJS = $(addprefix $(OBJS_DIR), $(SRC_FILES:.c=.o))
HEADERS = push_swap.h
LIBFT_DIR = ./lib/libft
PRINTF_DIR = ./lib/ftprintf
LIB = -L$(LIBFT_DIR) -lft -L$(PRINTF_DIR) -lftprintf

all:$(LIBFT_DIR)/libft.a $(PRINTF_DIR)/libftprintf.a $(OBJS_DIR) $(NAME)

$(OBJS_DIR):
	mkdir -p $(OBJS_DIR)

$(OBJS_DIR)%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(C_OBJS)
	$(CC) $(CFLAGS) $(C_OBJS) -o $(NAME) $(LIB)

$(LIBFT_DIR)/libft.a:
	@$(MAKE) -sC $(LIBFT_DIR)

$(PRINTF_DIR)/libftprintf.a:
	@$(MAKE) -sC $(PRINTF_DIR)

clean:
	$(RM) -rf $(OBJS_DIR)

fclean: clean
	@$(MAKE) -sC $(LIBFT_DIR) fclean
	@$(MAKE) -sC $(PRINTF_DIR) fclean
	$(RM) -f $(NAME)

re: fclean all

.PHONY: all clean fclean re







