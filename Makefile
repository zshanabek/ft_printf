NAME := libftprintf.a
FLAGS := -Wall -Wextra -Werror
LIB := libft
LIBFT := $(LIB)/ft_atoi.c $(LIB)/ft_memalloc.c $(LIB)/ft_putchar.c $(LIB)/ft_strcat.c $(LIB)/ft_striter.c $(LIB)/ft_strncmp.c          \
		$(LIB)/ft_strsub.c $(LIB)/ft_bzero.c $(LIB)/ft_memccpy.c $(LIB)/ft_putchar_fd.c $(LIB)/ft_strchr.c $(LIB)/ft_striteri.c    	   \
		$(LIB)/ft_strncpy.c $(LIB)/ft_strtrim.c $(LIB)/ft_isalnum.c $(LIB)/ft_memchr.c $(LIB)/ft_putendl.c $(LIB)/ft_strclr.c      	   \
		$(LIB)/ft_strjoin.c $(LIB)/ft_strnequ.c $(LIB)/ft_tolower.c $(LIB)/ft_isalpha.c $(LIB)/ft_memcmp.c $(LIB)/ft_putendl_fd.c  	   \
		$(LIB)/ft_strcmp.c $(LIB)/ft_strlcat.c $(LIB)/ft_strnew.c $(LIB)/ft_toupper.c $(LIB)/ft_isascii.c $(LIB)/ft_memcpy.c       	   \
		$(LIB)/ft_putnbr.c $(LIB)/ft_strcpy.c $(LIB)/ft_strlen.c $(LIB)/ft_strnstr.c $(LIB)/ft_isdigit.c $(LIB)/ft_memdel.c        	   \
		$(LIB)/ft_putnbr_fd.c $(LIB)/ft_strdel.c $(LIB)/ft_strmap.c $(LIB)/ft_strrchr.c $(LIB)/ft_isprint.c $(LIB)/ft_memmove.c    	   \
		$(LIB)/ft_putstr.c $(LIB)/ft_strdup.c $(LIB)/ft_strmapi.c $(LIB)/ft_strsplit.c $(LIB)/ft_itoa.c $(LIB)/ft_memset.c         	   \
		$(LIB)/ft_putstr_fd.c $(LIB)/ft_strequ.c $(LIB)/ft_strncat.c $(LIB)/ft_strstr.c $(LIB)/ft_isempty.c $(LIB)/ft_lstnew.c     	   \
		$(LIB)/ft_lstdelone.c $(LIB)/ft_lstdel.c $(LIB)/ft_lstadd.c $(LIB)/ft_lstiter.c $(LIB)/ft_lstmap.c $(LIB)/ft_lstaddend.c   	   \
		$(LIB)/ft_intlen.c $(LIB)/ft_isws.c $(LIB)/ft_print2darr.c $(LIB)/ft_intmax.c $(LIB)/ft_nbrendl.c $(LIB)/ft_itoa_base.c    	   \
		$(LIB)/ft_itoa_base_u.c $(LIB)/ft_itoa_u.c  $(LIB)/ft_intlen_u.c $(LIB)/ft_atoi_u.c $(LIB)/ft_strupcase.c $(LIB)/ft_strsub_w.c \
		$(LIB)/ft_strnew_w.c $(LIB)/ft_strlen_w.c $(LIB)/ft_putstrw.c $(LIB)/ft_putsymbol.c $(LIB)/ft_strdupw.c $(LIB)/ft_itoa_max.c
FILES :=  pf_main.c pf_spec_handlers.c pf_utils.c pf_flags.c pf_width_prec.c pf_dspec.c pf_uspec.c pf_extra.c pf_width_prec_wsu.c
OBJ1 := $(LIBFT:.c=.o)
OBJ2 := $(FILES:.c=.o)

all: 	$(NAME)

$(NAME): $(OBJ)
		@gcc -c -I ft_printf.h $(FILES) $(LIBFT)
		@ar rc $(NAME) $(OBJ1) $(OBJ2)

clean:
		@/bin/rm -f *.o		

fclean: clean
		@/bin/rm -f $(NAME)

re:		fclean all