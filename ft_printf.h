#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include "libft/libft.h"
# include <stdio.h>
# include <stdarg.h>
# include <stdbool.h>
# include <stdint.h>

enum			length
{
	ll,
	hh,
	l,
	h
};

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
int				calculate_zeros(int num, char *flags);
int				calculate_padding(int num, t_item *form, char *flags);
int				is_specifier(char c);
t_item			*create_struct();
void			create_output_d(intmax_t num, t_item *form, int *count);
char			*ft_strfill(size_t size, char c);
int				is_sign(char c);
void			ft_sign_order(t_item *form, char *padding_str, char *zeros_str);
void			ft_analyze_d(intmax_t num, t_item *form, char *flags, int *count);
void			ft_analyze_s(char *str, t_item *form, char *flags, int *count);
int				calculate_padding_s(char *str, t_item *form, char *flags);
void			ft_analyze_o(int num, t_item *form, char *flags, int *count);
void			ft_analyze_x(int num, t_item *form, char *flags, int *count);
void			ft_analyze_c(char c, t_item *form, char *flags, int *count);
int				ft_printf(const char * restrict format, ...);

#endif