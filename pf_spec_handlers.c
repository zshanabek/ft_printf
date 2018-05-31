#include "ft_printf.h"

void	ft_analyze_c(wint_t c, t_item *form, int *count)
{
	int		size;

	if (c != 0 && (form->spec == 'C' || form->l == true))
		size = ft_charlen(c);
	else
		size = 1;
	form->pad = form->pad - size;
	create_output(form);
	if (form->minus == false && form->pad > 0)
		ft_putstr(form->pad_str);
	if (c == 0)
		ft_putchar(0);
	else if (form->spec == 'C' || form->size == 'l')
		ft_putsymbol(c);
	else
		ft_putchar(c);
	if (form->minus == true && form->pad > 0)
		ft_putstr(form->pad_str);
	if (form->pad >= 0)
		*count += form->pad;
	*count += size;
}

void	ft_analyze_percent(t_item *form, int *count)
{
	form->pad = form->pad - 1;
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

void	ft_analyze_ls(wchar_t *str, t_item *form, int *count)
{
	wchar_t		*output;

	if (str == NULL)
		output = ft_strdupw(L"(null)");
	else if (form->zer != -1)
		output = ft_strsub_w(str, 0, form->zer);
	else
		output = ft_strdupw(str);
	form->pad = calculate_padding(ft_wstrlen(output), form);
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

void	ft_analyze_s(char *str, t_item *form, int *count)
{
	char *output;

	if (str == NULL && form->zer == -1)
		output = ft_strdup("(null)");
	else if (form->zer != -1)
		output = ft_strsub(str, 0, form->zer);
	else
		output = ft_strdup(str);
	form->pad = calculate_padding(ft_strlen(output), form);
	create_output(form);
	if (form->minus == false && form->pad > 0)
		ft_putstr(form->pad_str);
	if (!(str == NULL && form->zer != -1))
		ft_putstr(output);
	if (form->minus == true && form->pad > 0)
		ft_putstr(form->pad_str);
	if (form->pad >= 0)
		*count += form->pad;
	if (!(str == NULL && form->zer != -1))
	{
		*count += ft_strlen(output);
		ft_strdel(&output);
	}
}
