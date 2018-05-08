#include "ft_printf.h"

int get_width(char *flags)
{
	int k;
	int len;
	int num;
	int i;

	num = 0;
	i = 0;
	while (flags[i] && !(ft_isdigit(flags[i])))
		i++;
	k = i;
	len = 0;
	while (ft_isdigit(flags[i]))
	{
		len++;
		i++;
	}
	num = ft_atoi(ft_strsub(flags, k, len));
	return (num);
}

int get_precision(char *flags)
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

int calculate_zeros(int num, char *flags)
{
	int precision;

	precision = get_precision(flags);
	if (precision > 0)
		precision = precision - ft_intlen(num);
	return precision;
}

int calculate_padding(int num, t_item *form, char *flags)
{
	int		padding;
	int		width;	

	width = get_width(flags);
	if (form->precision >= 0)
	{
		padding = width - (form->precision + ft_intlen(num));
		if (form->sign == '+' || form->sign == '-')
			padding--;
		return (padding);		
	}
	else
	{
		padding = width -  ft_intlen(num);
		if (form->sign == '+' || form->sign == '-')
			padding--;
		return (padding);	
	}
	return (0);
}
