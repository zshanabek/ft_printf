#include "ft_printf.h"

void	ft_analyze_c(wint_t c, t_item *form, char *flags, int *count)
{
	int		size;

	size = ft_charlen(c);
	if (find_minus(flags))
		form->minus = true;
	else if (find_zero(flags))
		form->zero = true;
	form->pad = get_width(flags) - size;
	create_output(form);
	if (form->minus == false)
		ft_putstr(form->pad_str);
	if (c == 0)
		ft_putchar(0);
	else if (c >= 32 && c <= 126)
		ft_putchar(c);
	else
		ft_putsymbol(c);
	if (form->minus == true)
		ft_putstr(form->pad_str);
	*count += (ft_strlen(form->pad_str) + size);
}

void	ft_analyze_percent(t_item *form, char *flags, int *count)
{
	if (find_minus(flags))
		form->minus = true;
	else if (find_zero(flags))
		form->zero = true;
	form->pad = get_width(flags) - 1;
	create_output(form);
	if (form->minus == false)
		ft_putstr(form->pad_str);
	ft_putchar('%');
	if (form->minus == true)
		ft_putstr(form->pad_str);
	*count += (ft_strlen(form->pad_str) + 1);
}

void	ft_analyze_ls(wchar_t *str, t_item *form, char *flags, int *count)
{
	wchar_t		*output;

	output = ft_strnew_w(0);
	if (find_minus(flags))
		form->minus = true;
	else if (find_zero(flags))
		form->zero = true;
	if (str == NULL)
		output = ft_strdupw(L"(null)");
	else if (get_precision(flags) != -1)
		output = ft_strsub_w(str, 0, get_precision(flags));
	else
		output = ft_strdupw(str);
	form->pad = calculate_padding_ws(output, flags);
	create_output(form);	
	if (form->minus == false)
		ft_putstr(form->pad_str);
	ft_putstrw(output);
	if (form->minus == true)
		ft_putstr(form->pad_str);
	*count += (ft_strlen(form->pad_str) + ft_wstrlen(output));
}

void	ft_analyze_s(char *str, t_item *form, char *flags, int *count)
{
	char *output;
	char *padding_str;

	output = ft_strnew(0);
	padding_str = ft_strnew(0);
	if (find_minus(flags))
		form->minus = true;
	else if (find_zero(flags))
		form->zero = true;
	if (str == NULL)
		output = ft_strdup("(null)");
	else if (get_precision(flags) != -1)
		output = ft_strsub(str, 0, get_precision(flags));
	else
		output = ft_strdup(str);
	form->pad = calculate_padding_s(output, flags);
	create_output(form);
	if (form->minus == false)
		ft_putstr(form->pad_str);
	ft_putstr(output);
	if (form->minus == true)
		ft_putstr(form->pad_str);
	*count += (ft_strlen(form->pad_str) + ft_strlen(output));
}
