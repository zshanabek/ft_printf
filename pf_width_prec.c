#include "ft_printf.h"

int		get_width(const char *flags, int i, t_item *form)
{
	int k;
	int len;

	while ((flags[i] && !(ft_isdigit(flags[i]))) || flags[i] == '0')
		i++;
	k = i;
	len = 0;
	if (flags[i - 1] == '.')
		form->pad = 0;
	while (ft_isdigit(flags[i]))
	{
		len++;
		i++;
	}
	form->pad = ft_atoi(ft_strsub(flags, k, len));
	return (i);
}

void	get_precision(const char *format, int i, t_item *form)
{
	int len;
	int num;
	int k;
	char *arr;

	num = 0;
	while (format[i] && format[i] != '.')
		i++;
	if (format[i] == '.')
	{
		i++;
		k = i;
		len = 0;
		while (format[i] && ft_isdigit(format[i]))
		{
			len++;
			i++;
		}
		arr = ft_strsub(format, k, len);
		num = ft_atoi(arr);
		form->prec = num;
	}
	else
		form->prec = -1;
}

int		calculate_zeros(int len, const char *flags)
{
	int precision;

	precision = get_precision(flags);
	if (precision > 0)
		precision = precision - len;
	return (precision);
}

int		calculate_padding(int len, t_item *form, const char *flags)
{
	int		padding;
	int		width;

	padding = 0;
	width = get_width(flags);

	if (form->spec == 's' || form->spec == 'S')
		return (width - len);
	if (form->prec > 0)
		padding = width - (form->prec + len);
	else
		padding = width - len;
	if (form->sign == '+' || form->sign == '-' || form->space == true)
		padding--;
	if (form->hash == true && (form->spec == 'x' || form->spec == 'X'))
		padding -= 2;
	else if (form->spec == 'p')
		padding -= 2;
	else if (form->hash == true && (form->spec == 'o' || form->spec == 'O'))
		padding--;
	return (padding);
}
