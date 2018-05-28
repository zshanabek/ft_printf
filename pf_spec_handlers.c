#include "ft_printf.h"

void	ft_analyze_c(wint_t c, t_item *form, char *flags, int *count)
{
	int		size;

	if (c != 0 && (form->spec == 'C' || form->l == true))
		size = ft_charlen(c);
	else
		size = 1;
	ft_basic_analyze(flags, form);
	form->pad = get_width(flags) - size;
	create_output(form);
	if (form->minus == false && form->pad > 0)
		ft_putstr(form->pad_str);
	if (c == 0)
		ft_putchar(0);
	else if (form->spec == 'C' || form->l == true)
		ft_putsymbol(c);
	else if (form->spec == 'c')
		ft_putchar(c);
	if (form->minus == true && form->pad > 0)
		ft_putstr(form->pad_str);
	if (form->pad >= 0)
		*count += form->pad;
	*count += size;
}

void	ft_analyze_percent(t_item *form, char *flags, int *count)
{
	ft_basic_analyze(flags, form);
	form->pad = get_width(flags) - 1;
	create_output(form);
	if (form->minus == false && form->pad > 0)
		ft_putstr(form->pad_str);
	ft_putchar('%');
	if (form->minus == true && form->pad > 0)
		ft_putstr(form->pad_str);
	if (form->pad >= 0)
		*count += form->pad;
	*count += 1;
}

void	ft_analyze_ls(wchar_t *str, t_item *form, char *flags, int *count)
{
	wchar_t		*output;

	ft_basic_analyze(flags, form);
	if (str == NULL)
		output = ft_strdupw(L"(null)");
	else if (get_precision(flags) != -1)
		output = ft_strsub_w(str, 0, get_precision(flags));
	else
		output = ft_strdupw(str);
	form->pad = calculate_padding(ft_wstrlen(output), form, flags);
	create_output(form);
	if (form->minus == false && form->pad > 0)
		ft_putstr(form->pad_str);
	ft_putstrw(output);
	if (form->minus == true && form->pad > 0)
		ft_putstr(form->pad_str);
	if (form->pad >= 0)
		*count += form->pad;
	*count += ft_wstrlen(output);
	ft_wstrdel(&output);
}

void	ft_analyze_s(char *str, t_item *form, char *flags, int *count)
{
	char *output;

	ft_basic_analyze(flags, form);
	if (str == NULL)
		output = ft_strdup("(null)");
	else if (get_precision(flags) != -1)
		output = ft_strsub(str, 0, get_precision(flags));
	else
		output = ft_strdup(str);
	form->pad = calculate_padding(ft_strlen(output), form, flags);
	create_output(form);
	if (form->minus == false && form->pad > 0)
		ft_putstr(form->pad_str);
	ft_putstr(output);
	if (form->minus == true && form->pad > 0)
		ft_putstr(form->pad_str);
	if (form->pad >= 0)
		*count += form->pad;
	*count += ft_strlen(output);
	ft_strdel(&output);
}
