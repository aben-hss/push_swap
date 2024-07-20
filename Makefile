NAME = push_swap

CFLAGS = cc -Wall -Wextra -Werror

RM = rm -rf

# OBJECT = 

all :
	make -C ./libft 
	cc rules.c push_swap.c sort.c t_stucks_utils.c sort_utils.c ./libft/libft.a -o $(NAME)
re :
	make -C libft re
	make all