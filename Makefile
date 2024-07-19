NAME = push_swap

all :
	make -C ./libft 
	cc rules.c push_swap.c t_stucks_utils.c sort_utils.c ./libft/libft.a -o $(NAME)
re :
	make -C libft re
	make all