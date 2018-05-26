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
	int		l;
	char	sign;
	char	spec;
	char	*hex_sign;
	char	*pad_str;
	char	*zer_str;
	char	*output;	
	char	*temp;
}				t_item;

int				find_minus(const char *flags);
int				find_zero (const char *flags);
int				find_plus (const char *flags);
int				find_space(const char *flags);
int				find_hash (const char *flags);
int				get_width (const char *flags);
int				get_precision(const char *flags);
int				calculate_zeros(int len, const char *flags);
int				calculate_padding(int len, t_item *form, const char *flags);
int				is_specifier(char c);
t_item			*create_struct();
void			create_output_d(intmax_t num, t_item *form, int *count);
char			*ft_strfill(size_t size, char c);
int				is_sign(char c);
void			ft_analyze_d(intmax_t n, t_item *form, const char *flags, int *c);
void			ft_analyze_ls(wchar_t *str, t_item *form, const char *flags, int *c);
void			ft_analyze_s(char *str, t_item *form, const char *flags, int *count);
void			ft_analyze_u(uintmax_t n, t_item *form, const char *flags, int *c);
void			ft_analyze_x(uintmax_t n, t_item *form, const char *flags, int *c);
void			ft_analyze_c(wint_t c, t_item *form, const char *flags, int *count);
void			ft_analyze_percent(t_item *form, const char *flags, int *count);
int				ft_printf(const char *restrict format, ...);
void			get_inform(const char *restrict format, int i, t_item *form);
int				find_length_s(const char *flags);
intmax_t		find_length(va_list ap, const char *flags, t_item *form);
uintmax_t		find_length_u(va_list ap, const char *flags, t_item *form);
wint_t			find_length_c(va_list ap, const char *flags, t_item *form);
void			ft_sign_order_u(t_item *form, int *count);
int				find_spec(const char *flags);
void			create_output(t_item *form);
void			ft_sign_order(t_item *form);
void			ft_basic_analyze(const char *flags, t_item *form);
void			form_del(t_item *form);

#endif
