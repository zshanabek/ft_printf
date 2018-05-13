#include "ft_printf.h"

void ft_sign_order(t_item *form, char *padding_str, char *zeros_str)
{
	if (is_sign(form->sign))
	{
		if ((ft_strlen(padding_str) <= 0 && ft_strlen(zeros_str) <= 0) || (ft_strlen(padding_str) > 0 && ft_strlen(zeros_str) <= 0 && form->zero == true) 
		|| (ft_strlen(zeros_str) > ft_strlen(padding_str)))
			form->order = 1;
		else if (ft_strlen(padding_str) > 0 && ft_strlen(zeros_str) > 0)	
			form->order = 2;
		else if (ft_strlen(padding_str) > 0 && ft_strlen(zeros_str) <= 0)		
			form->order = 3;
	}
}

void			ft_analyze_d(intmax_t num, t_item *form, char *flags, int *count)
{
	if (num < 0)
	{
		form->sign = '-';
		num *= -1;
	}
	if (find_plus(flags) && form->sign != '-')
		form->sign = '+';
	else if (find_space(flags))
		form->space = true;
	form->precision = calculate_zeros(num, flags);	
	if (find_minus(flags))
		form->minus = true;
	else if (find_zero(flags) && form->precision == -1)
		form->zero = true;
	if (is_sign(form->sign) || form->padding > 0) 
		form->space = false;
	form->padding = calculate_padding(num, form, flags);
	create_output_d(num, form, count);
}


void make_output_d(intmax_t num, t_item *form, char *padding_str, char *zeros_str, int *count)
{
	int len;

	if (form->space)
	{
		ft_putchar(' ');
		(*count)++;
	}
	if (form->order == 1 && is_sign(form->sign))
	{
		ft_putchar(form->sign);
		(*count)++;		
	}
	if (ft_strlen(padding_str) > 0 && form->minus == false)
		ft_putstr(padding_str);
	if (form->order == 2 && is_sign(form->sign))
	{
		ft_putchar(form->sign);
		(*count)++;		
	}
	if (ft_strlen(zeros_str) > 0)
		ft_putstr(zeros_str);
	if (form->order == 3 && is_sign(form->sign))
	{
		ft_putchar(form->sign);
		(*count)++;		
	}
	ft_putnbr(num);
	if (ft_strlen(padding_str) > 0 && form->minus == true) 
		ft_putstr(padding_str);

	*count += (ft_strlen(padding_str) + ft_strlen(zeros_str) + ft_intlen(num));	
}

void create_output_d(intmax_t num, t_item *form, int *count)
{
	char 	*zeros_str;
	char 	*padding_str;

	padding_str = ft_strnew(0);
	zeros_str = ft_strnew(0);
	if (form->zero == false && form->padding > 0)
		padding_str = ft_strfill(form->padding, ' ');
	else if (form->zero == true && form->padding > 0 )
		padding_str = ft_strfill(form->padding, '0');
	if (form->precision > 0)
		zeros_str = ft_strfill(form->precision, '0');
	ft_sign_order(form, padding_str, zeros_str);
	make_output_d(num, form, padding_str, zeros_str, count);
}

