NAME = push_swap
CC = cc
CFLAGS = -Wall -Wextra -Werror
LIBFT = libft/libft.a

SRC = push_swap.c \
      rules.c \
      sort_utils.c \
      sort.c \
      t_stucks_utils.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) -o $(NAME)

%.o: %.c push_swap.h
	$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT):
	make -C libft

clean:
	rm -f $(OBJ)
	make -C libft clean

fclean: clean
	rm -f $(NAME)
	make -C libft fclean

re: fclean all

.PHONY: all clean fclean re