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
	int hash;			
	int precision;
	int padding;
	char sign;
	int order;	
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
int				calculate_zeros(int num, t_item *form, char *flags);
int				calculate_padding(int num, t_item *form, char *flags);
int				is_specifier(char c);
t_item			*create_struct();
void			create_output_d(int num, t_item *form);
char			*ft_strfill(size_t size, char c);

#endif