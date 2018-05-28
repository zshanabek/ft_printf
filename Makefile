NAME = libftprintf.a
FLAGS = -Wall -Wextra -Werror
FILES =  pf_start.c pf_spec_handlers.c pf_utils.c pf_flags.c pf_width_prec.c pf_dspec.c pf_uspec.c pf_extra.c pf_find_size.c

all: 	$(NAME)

$(NAME): 
		@gcc $(FLAGS) -c libft/*.c -I libft/libft.h
		@gcc -c $(FILES)
		@ar rc $(NAME) *.o

clean:
		@rm -rf *.o libft/*.o	

fclean: clean
		@rm -rf $(NAME)

re:		fclean all
