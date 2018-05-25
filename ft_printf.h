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
# include <limits.h>

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
int				calculate_zeros(int len, char *flags);
int				calculate_padding(int len, t_item *form, char *flags);
int				is_specifier(char c);
t_item			*create_struct();
void			create_output_d(intmax_t num, t_item *form, int *count);
char			*ft_strfill(size_t size, char c);
int				is_sign(char c);
void			ft_analyze_d(intmax_t n, t_item *form, char *flags, int *c);
void			ft_analyze_ls(wchar_t *str, t_item *form, char *flags, int *c);
void			ft_analyze_s(char *str, t_item *form, char *flags, int *count);
void			ft_analyze_u(uintmax_t n, t_item *form, char *flags, int *c);
void			ft_analyze_x(uintmax_t n, t_item *form, char *flags, int *c);
void			ft_analyze_c(wint_t c, t_item *form, char *flags, int *count);
void			ft_analyze_percent(t_item *form, char *flags, int *count);
int				ft_printf(const char *restrict format, ...);
char			*get_inform(const char *restrict format, int i, t_item *form);
int				find_length_s(char *flags);
intmax_t		find_length(va_list ap, char *flags, t_item *form);
uintmax_t		find_length_u(va_list ap, char *flags, t_item *form);
wint_t			find_length_c(va_list ap, char *flags, t_item *form);
void			ft_sign_order_u(t_item *form, int *count);
int				find_spec(char *flags);
void			create_output(t_item *form);
void			ft_sign_order(t_item *form);
void			ft_basic_analyze(char *flags, t_item *form);
#endif
