#include "ft_printf.h"

void	ft_analyze_c(wint_t c, t_item *form, char *flags, int *count)
{
	char	*padding_str;
	int		size;

	size = 1;
	padding_str = ft_strnew(0);
	if (find_minus(flags))
		form->minus = true;
	else if (find_zero(flags))
		form->zero = true;
	form->pad = get_width(flags) - 1;
	if (form->pad > 0 && form->zero)
		padding_str = ft_strfill(form->pad, '0');
	else if (form->pad > 0)
		padding_str = ft_strfill(form->pad, ' ');
	if (form->minus == false)
		ft_putstr(padding_str);
	if (c == 0)
		ft_putchar(0);
	else if (c >= 32 && c <= 126)
		ft_putchar(c);
	else
		size = ft_putsymbol(c);
	if (form->minus == true)
		ft_putstr(padding_str);
	*count += (ft_strlen(padding_str) + size);
}

void	ft_analyze_percent(t_item *form, char *flags, int *count)
{
	char *padding_str;

	padding_str = ft_strnew(0);
	if (find_minus(flags))
		form->minus = true;
	else if (find_zero(flags))
		form->zero = true;
	form->pad = get_width(flags) - 1;
	if (form->pad > 0 && form->zero)
		padding_str = ft_strfill(form->pad, '0');
	else if (form->pad > 0)
		padding_str = ft_strfill(form->pad, ' ');
	if (form->minus == false)
		ft_putstr(padding_str);
	ft_putchar('%');
	if (form->minus == true)
		ft_putstr(padding_str);
	*count += (ft_strlen(padding_str) + 1);
}

void	ft_analyze_ls(wchar_t *str, t_item *form, char *flags, int *count)
{
	wchar_t		*output;
	char		*padding_str;
	int			size;

	size = 0;
	output = ft_strnew_w(0);
	padding_str = ft_strnew(0);
	if (find_minus(flags))
		form->minus = true;
	if (str == NULL)
		output = ft_strdupw(L"(null)");
	else if (get_precision(flags) != -1)
		output = ft_strsub_w(str, 0, get_precision(flags));
	else
		output = ft_strdupw(str);
	form->pad = calculate_padding_ws(output, flags);
	if (form->pad > 0)
		padding_str = ft_strfill(form->pad, ' ');
	if (form->minus == false)
		ft_putstr(padding_str);
	size = ft_putstrw(output);
	if (form->minus == true)
		ft_putstr(padding_str);
	*count += (ft_strlen(padding_str) + size);
}

void	ft_analyze_s(char *str, t_item *form, char *flags, int *count)
{
	char *output;
	char *padding_str;

	output = ft_strnew(0);
	padding_str = ft_strnew(0);
	if (find_minus(flags))
		form->minus = true;
	if (str == NULL)
		output = ft_strdup("(null)");
	else if (get_precision(flags) != -1)
		output = ft_strsub(str, 0, get_precision(flags));
	else
		output = ft_strdup(str);
	form->pad = calculate_padding_s(output, flags);
	if (form->pad > 0)
		padding_str = ft_strfill(form->pad, ' ');
	if (form->minus == false)
		ft_putstr(padding_str);
	ft_putstr(output);
	if (form->minus == true)
		ft_putstr(padding_str);
	*count += (ft_strlen(padding_str) + ft_strlen(output));
}
