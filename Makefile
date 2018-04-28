NAME = ft_printf
FLAGS = -Wall -Wextra -Werror
FILES = main.c
LIB = ./libft/libft.a

all:$(NAME)

$(NAME): $(FILES)
		make -C libft
		gcc $(FLAGS) -o $(NAME) $(FILES) $(LIB)

clean:
		make -C libft clean

fclean: clean
		make -C libft fclean
		/bin/rm -f $(NAME)

re:		fclean all