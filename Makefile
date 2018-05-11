NAME := ft_printf
FILES := main.c spec_handlers.c utils.c flags.c get_width_prec.c d_specifier.c
LIB := ./libft/libft.a

all:$(NAME)

$(NAME): $(FILES)
		make -C libft
		gcc -c $(FILES) $(LIB)

clean:
		make -C libft clean
		rm *.o
fclean: clean
		make -C libft fclean
		/bin/rm -f $(NAME)

re:		fclean all

.PHONY:all clean fclean re