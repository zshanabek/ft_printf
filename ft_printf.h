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

typedef enum	e_size
{
	h,
	l,
	hh,
	ll
}				t_size;

typedef struct	s_item
{
	int		plus;
	int		space;
	int		minus;
	int		zero;
	int		hash;
	int		prec;
	int		pad;
	int		order;
	char	sign;
	char	spec;
	char	*hex_sign;
	char	*pad_str;
	char	*zer_str;
}				t_item;

int				find_minus(char *flags);
int				find_zero(char *flags);
int				find_plus(char *flags);
int				find_space(char *flags);
int				find_hash(char *flags);
int				get_width(char *flags);
int				get_precision(char *flags);
int				calculate_zeros(intmax_t num, char *flags);
int				calculate_padding(intmax_t num, t_item *form, char *flags);
int				calculate_zeros_u(int len, char *flags);
int				calculate_padding_u(int len, t_item *form, char *flags);
int				is_specifier(char c);
t_item			*create_struct();
void			create_output_d(intmax_t num, t_item *form, int *count);
char			*ft_strfill(size_t size, char c);
int				is_sign(char c);
void			ft_analyze_d(intmax_t n, t_item *form, char *flags, int *c);
void			ft_analyze_ls(wchar_t *str, t_item *form, char *flags, int *c);
void			ft_analyze_s(char *str, t_item *form, char *flags, int *count);
int				calculate_padding_ws(wchar_t *str, char *flags);
int				calculate_padding_s(char *str, char *flags);
void			ft_analyze_u(uintmax_t n, t_item *form, char *flags, int *c);
void			ft_analyze_x(uintmax_t n, t_item *form, char *flags, int *c);
void			ft_analyze_c(wint_t c, t_item *form, char *flags, int *count);
void			ft_analyze_percent(t_item *form, char *flags, int *count);
int				ft_printf(const char *restrict format, ...);
char			*get_inform(const char *restrict format, int i, t_item *form);
int				find_length_s(char *flags);
wint_t			find_length_c(va_list ap, char *flags, t_item *form);
void			ft_sign_order_u(t_item *form, int *count);
int				find_spec(char *flags);
#endif
