#include "ft_printf.h"

void make_output_d(int num, t_item *form, char *padding_str, char *zeros_str)
{
	if (form->space)
		ft_putchar(' ');
	if (form->order == 1 && is_sign(form->sign))
		ft_putchar(form->sign);
	if (ft_strlen(padding_str) > 0 && form->minus == false) 
		ft_putstr(padding_str);
	if (form->order == 2 && is_sign(form->sign))
		ft_putchar(form->sign);
	if (ft_strlen(zeros_str) > 0)
		ft_putstr(zeros_str);
	if (form->order == 3 && is_sign(form->sign))
		ft_putchar(form->sign);
	ft_putnbr(num);
	if (ft_strlen(padding_str) > 0 && form->minus == true) 
		ft_putstr(padding_str);
}

void create_output_d(int num, t_item *form)
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
	make_output_d(num, form, padding_str, zeros_str);
}
