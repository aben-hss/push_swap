NAME = push_swap
CHECKER = ./checker
CC = cc
CFLAGS = -Wall -Wextra -Werror
LIBFT = libft/libft.a

SRC = push_swap.c \
      parse.c \
      rules.c \
      sort_utils.c \
      sort.c \
      t_stucks_utils.c

CHECKER_SRC = bonus/checker.c bonus/parse_bonus.c bonus/rules_bonus.c bonus/sort_utils_bonus.c bonus/t_stucks_utils_bonus.c bonus/get_next_line.c bonus/get_next_line_utils.c

LIBFT_SRC = libft/ft_atoi.c libft/ft_bzero.c libft/ft_calloc.c libft/ft_isalnum.c \
            libft/ft_isalpha.c libft/ft_isascii.c libft/ft_isdigit.c libft/ft_isprint.c \
            libft/ft_itoa.c libft/ft_memchr.c libft/ft_memcmp.c libft/ft_memcpy.c \
            libft/ft_memmove.c libft/ft_memset.c libft/ft_putchar_fd.c libft/ft_putendl_fd.c \
            libft/ft_putnbr_fd.c libft/ft_putstr_fd.c libft/ft_split.c libft/ft_strchr.c \
            libft/ft_strdup.c libft/ft_striteri.c libft/ft_strjoin.c libft/ft_strlcat.c \
            libft/ft_strlcpy.c libft/ft_strlen.c libft/ft_strmapi.c libft/ft_strncmp.c \
            libft/ft_strnstr.c libft/ft_strrchr.c libft/ft_strtrim.c libft/ft_substr.c \
            libft/ft_tolower.c libft/ft_toupper.c libft/libft.h

OBJ = $(SRC:.c=.o)

CHECKER_OBJ = $(CHECKER_SRC:.c=.o)

all: $(LIBFT) $(NAME) 

$(NAME): $(LIBFT) $(OBJ) $(LIBFT_SRC)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) -o $(NAME)

%.o: %.c push_swap.h $(LIBFT)
	$(CC) $(CFLAGS) -c $< -o $@

bonus/%.o: bonus/%.c checker.h get_next_line.h $(LIBFT) $(LIBFT_SRC)
	$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT): $(LIBFT_SRC)
	make -C libft

clean:
	rm -f $(OBJ) $(CHECKER_OBJ)
	make -C libft clean

fclean: clean
	rm -f $(NAME) $(CHECKER)
	make -C libft fclean

re: fclean all

bonus: $(LIBFT) $(CHECKER)

$(CHECKER): $(CHECKER_OBJ) $(LIBFT) $(LIBFT_SRC) ./bonus/get_next_line.h ./bonus/checker.h
	$(CC) $(CFLAGS) $(CHECKER_OBJ) $(LIBFT) -o $(CHECKER)

.PHONY: all clean fclean re bonus
