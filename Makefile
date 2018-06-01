NAME = libftprintf.a
FLAGS = -Wall -Wextra -Werror
FILES =  pf_start.c pf_spec_handlers.c pf_utils.c pf_itoa_max.c pf_pad_prec_size.c pf_dspec.c pf_uspec.c pf_helpers.c

all: 	$(NAME)

$(NAME): 
		@gcc $(FLAGS) -c libft/*.c -I libft/libft.h
		@gcc $(FLAGS) -c $(FILES)
		@ar rc $(NAME) *.o

clean:
		@rm -rf *.o libft/*.o	

fclean: clean
		@rm -rf $(NAME)

re:		fclean all
