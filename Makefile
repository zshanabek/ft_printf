NAME := ft_printf
FILES := main.c spec_handlers.c utils.c flags.c get_width_prec.c d_specifier.c
LIB := ./libft/libft.a

NAME = libftprintf.a
FLAGS = -Wall -Wextra -Werror
FILES = ft_printf.c spec_handlers.c utils.c flags.c get_width_prec.c d_specifier.c 
OBJ = ft_printf.o spec_handlers.o utils.o flags.o get_width_prec.o d_specifier.o

all: 	$(NAME)

$(NAME): $(FILES)
		gcc -c -I libft.h $(FILES) -Llibft -lft
		ar rc $(NAME) $(OBJ)

clean:
		/bin/rm -f $(OBJ)

fclean: clean
		/bin/rm -f $(NAME)

re:		fclean all