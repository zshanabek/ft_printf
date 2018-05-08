#include "ft_printf.h"

int calculate_zeros(int num, t_item *form, char *flags)
{
	int precision;
	
	precision = get_precision(flags);
	if (precision > 0)
	{
		if (num > 0)
			precision = precision - ft_intlen(num);
		else
			precision = precision - ft_intlen(num) + 1;
	}
	return precision;
}

int calculate_padding(int num, t_item *form, char *flags)
{
	int		padding;
	int		width;	

	width = get_width(flags);
	padding = width - form->precision;
	padding -= ft_intlen(num);
	if (form->sign == '+' || form->sign == '-')
		padding--;
	return (padding);
}

void create_output_d(int num, t_item *form)
{
	char 	*zeros_str;
	char 	*padding_str;
	char 	*output;
	
	padding_str = ft_strnew(0);
	zeros_str = ft_strnew(0);
	if (form->padding > 0 && form->zero == false)
		padding_str = ft_strfill(form->padding, ' ');
	else if (form->padding > 0 && form->zero == true)
		padding_str = ft_strfill(form->padding, '0');
	if (form->precision > 0)
		zeros_str = ft_strfill(form->precision, '0');
	if (form->space)
		ft_putchar(' ');
	if (ft_strlen(padding_str) > 0) 
		ft_putstr(padding_str);
	if (ft_strlen(zeros_str) > 0)
		ft_putstr(zeros_str);
	ft_putnbr(num);
}
