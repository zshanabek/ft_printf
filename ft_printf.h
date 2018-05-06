#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include "libft/libft.h"
# include <stdio.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdbool.h>

typedef struct	s_item
{
	int plus;
	int space;	
	int minus;
	int zero;			
	int width;		
	int hash;			
	int precision;
	char specifier;
}				t_item;

void 			print_struct(t_item *form);
void 			print_wp(int width, int precision);
void 			ft_integer(int num, t_item *form);
void 			ft_string(char *str, t_item *form);
int 			find_minus(char *flags);
int 			find_zero(char *flags);
int 			find_plus(char *flags);
int 			find_space(char *flags);
int 			find_hash(char *flags);
int				get_width(char *flags);
int				get_precision(char *flags);

#endif