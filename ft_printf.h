#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include "libft/libft.h"
# include <stdio.h>
# include <stdarg.h>
# include <stdbool.h>
# include <stdint.h>
# include <stdlib.h>
# include <wchar.h>
# include <locale.h>

typedef enum e_size
{
	h,
	l,
	hh,
	ll
}			t_size;

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
	char *hex_sign;	
	int order;
	char specifier;
	char *padding_str;
	char *zeros_str;
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
int				calculate_zeros(int64_t num, char *flags);
int				calculate_padding(int64_t num, t_item *form, char *flags);
int				calculate_zeros_u(int len, char *flags);
int				calculate_padding_u(int len, t_item *form, char *flags);
int				is_specifier(char c);
t_item			*create_struct();
void			create_output_d(int64_t num, t_item *form, int *count);
char			*ft_strfill(size_t size, char c);
int				is_sign(char c);
void			ft_sign_order(t_item *form, char *padding_str, char *zeros_str);
void			ft_analyze_d(int64_t num, t_item *form, char *flags, int *count);
void			ft_analyze_s(wchar_t *str, t_item *form, char *flags, int *count);
int				calculate_padding_s(wchar_t *str, t_item *form, char *flags);
void			ft_analyze_u(uint64_t num, t_item *form, char *flags, int *count);
void			ft_analyze_x(uint64_t num, t_item *form, char *flags, int *count);
void			ft_analyze_c(wint_t c, t_item *form, char *flags, int *count);
void			ft_analyze_percent(t_item *form, char *flags, int *count);
int				ft_printf(const char * restrict format, ...);

#endif