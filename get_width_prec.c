#include "ft_printf.h"

int get_width(char *flags)
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

int calculate_zeros(int64_t num, char *flags)
{
	int precision;

	precision = get_precision(flags);
	if (precision > 0)
		precision = precision - ft_intlen(num);
	return precision;
}

int calculate_padding(int64_t num, t_item *form, char *flags)
{
	int		padding;
	int		width;	

	width = get_width(flags);
	
	if (form->precision > 0)
	{
		padding = width - (form->precision + ft_intlen(num));
		if (form->sign == '+' || form->sign == '-' || form->space == true )
			padding--;
		return (padding);		
	}
	else
	{
		padding = width - ft_intlen(num);
		if (form->sign == '+' || form->sign == '-' || form->space == true  )
			padding--;
		return (padding);	
	}
	return (0);
}


int calculate_zeros_u(uint64_t num, char *flags)
{
	int precision;

	precision = get_precision(flags);
	if (precision > 0)
		precision = precision - ft_intlen_u(num);
	return precision;
}

int calculate_padding_u(uint64_t num, t_item *form, char *flags)
{
	int		padding;
	int		width;	
	int		len;

	width = get_width(flags);	
	if (form->precision > 0)
	{
		if (form->specifier == 'x' || form->specifier == 'X')
			len = ft_strlen(ft_itoa_base_u(num, 16));
		else
			len = ft_intlen_u(num);
		padding = width - (form->precision + len);
		if (form->hash == true && (form->specifier == 'x' || form->specifier == 'X'))
			padding -= 2;
		else if (form->hash == true)
			padding--;
		return (padding);				
	}
	else
	{
		// printf("h: %s\n", ft_itoa_base_u(num, 16));
		if (form->specifier == 'x' || form->specifier == 'X')
			len = ft_strlen(ft_itoa_base_u(num, 16));
		else
			len = ft_intlen_u(num);
		padding = width - ft_intlen_u(num);
		if (form->hash == true && (form->specifier == 'x' || form->specifier == 'X'))
			padding -= 2;
		else if (form->hash == true)
			padding--;
		return (padding);	
	}

	return (0);
}

int calculate_padding_s(char *str, t_item *form, char *flags)
{
	int width;
	int padding;

	width = get_width(flags);
	padding = width - ft_strlen(str); 
	return (padding);
}
