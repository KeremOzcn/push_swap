NAME = push_swap
CC = cc
CFLAGS = -Wall -Wextra -Werror

LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a

SRCS = atoi_utils.c \
       calc_utils.c \
       checker_utils.c \
       costs_utils.c \
       future_movement.c \
       input_parser.c \
       moves_utils.c \
       push_swap.c \
       sort_manager.c \
       three_sort_utils.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) -L$(LIBFT_DIR) -lft -o $(NAME)

$(LIBFT):
	@$(MAKE) -C $(LIBFT_DIR)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)
	@$(MAKE) clean -C $(LIBFT_DIR)

fclean: clean
	rm -f $(NAME)
	@$(MAKE) fclean -C $(LIBFT_DIR)

re: fclean all

.PHONY: all clean fclean re