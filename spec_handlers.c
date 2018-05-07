#include "ft_printf.h"

void calculate_padding(int num, t_item *form, char *flags)
{
	int		padding;
	int		width;	

	width = get_width(flags);
	if (ft_intlen(num) >= form->precision)
		padding = width - ft_intlen(num);
	else
		padding = width - form->precision;
	if (form->sign == '+' || form->sign == '-')
		padding--;
	form->padding = padding;
}

void calculate_zeros(int num, t_item *form, char *flags)
{
	int precision;
	
	precision = get_precision(flags);
	if (precision > 0)
	{
		if (num >= 0)
			precision = precision - ft_intlen(num);
		else
			precision = precision - ft_intlen(num) + 1;
		form->precision = precision;
	}
}

void create_output_d(int num, t_item *form)
{
	char 	*zeros_str;
	char 	*padding_str;
	char 	*output;
	
	if (form->padding > 0 && form->zero == false)
		padding_str = ft_strfill(form->padding, ' ');
	else if (form->padding > 0 && form->zero == true)
		padding_str = ft_strfill(form->padding, '0');

	zeros_str = ft_strfill(form->precision, '0');
	output = ft_strjoin(padding_str, zeros_str);
	ft_putendl(output);
}
