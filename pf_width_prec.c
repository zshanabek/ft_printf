#include "ft_printf.h"

int		get_width(const char *flags)
{
	int k;
	int len;
	int num;
	int i;

	num = 0;
	i = 0;
	while ((flags[i] && !(ft_isdigit(flags[i]))) || flags[i] == '0')
		i++;
	k = i;
	len = 0;
	if (flags[i - 1] == '.')
		return (num);
	while (ft_isdigit(flags[i]))
	{
		len++;
		i++;
	}
	num = ft_atoi(ft_strsub(flags, k, len));
	return (num);
}

int		get_precision(const char *flags)
{
	int len;
	int num;
	int k;
	int i;

	i = 0;
	num = 0;
	while (flags[i] && flags[i] != '.')
		i++;
	if (flags[i] == '.')
	{
		i++;
		k = i;
		len = 0;
		while (flags[i] && ft_isdigit(flags[i]))
		{
			len++;
			i++;
		}
		num = ft_atoi(ft_strsub(flags, k, len));
		return (num);
	}
	else
		return (-1);
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
