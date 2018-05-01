# make -C libft re
gcc main.c spec_handlers.c auxiliary.c -Llibft -lft
./a.out | cat -e