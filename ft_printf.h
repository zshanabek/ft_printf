#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include "libft/libft.h"
# include <stdio.h>
# include <unistd.h>
# include <stdarg.h>

typedef struct	s_item
{
	int pls_spc;
	int min_zer;	
	int width;		
	int hash;			
	int precision;
	int is_precision;
	char specifier;
	int percent;
}				t_item;

void print_struct(t_item *form);
void print_wp(int width, int precision);
void ft_integer(int num, t_item *form);

#endif