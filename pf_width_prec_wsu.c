#include "ft_printf.h"

int		calculate_zeros_u(int len, char *flags)
{
	int precision;

	precision = get_precision(flags);
	if (precision > 0)
		precision = precision - len;
	return (precision);
}

int		calculate_padding_u(int len, t_item *form, char *flags)
{
	int		padding;
	int		width;

	width = get_width(flags);
	if (form->prec > 0)
	{
		padding = width - (form->prec + len);
		if (form->hash == true && (form->spec == 'x' || form->spec == 'X'))
			padding -= 2;
		else if (form->hash == true)
			padding--;
		return (padding);
	}
	else
	{
		padding = width - len;
		if (form->hash == true && (form->spec == 'x' || form->spec == 'X'))
			padding -= 2;
		else if (form->hash == true)
			padding--;
		return (padding);
	}
	return (0);
}

int		calculate_padding_ws(wchar_t *str, char *flags)
{
	int width;
	int padding;

	width = get_width(flags);
	padding = width - ft_strlen_w(str) - ft_strlen_w(str);
	return (padding);
}

int		calculate_padding_s(char *str, char *flags)
{
	int width;
	int padding;

	width = get_width(flags);
	padding = width - ft_strlen(str);
	return (padding);
}
