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

void make_output_d(intmax_t num, t_item *form, int *count)
{
	if (form->space)
	{
		ft_putchar(' ');
		(*count)++;
	}
	if (form->order == 1 && is_sign(form->sign))
		ft_putchar(form->sign);
	if (ft_strlen(form->pad_str) > 0 && form->minus == false)
		ft_putstr(form->pad_str);
	if (form->order == 2 && is_sign(form->sign))
		ft_putchar(form->sign);
	if (ft_strlen(form->zer_str) > 0)
		ft_putstr(form->zer_str);
	if (form->order == 3 && is_sign(form->sign))
		ft_putchar(form->sign);
	if (is_sign(form->sign))
		(*count)++;
	if (num == -9223372036854775808U)
	{
		ft_putstr(ft_strsub(ft_itoa(num), 1, 19));
		(*count)--;
	}
	else 
		ft_putstr(ft_itoa(num));
	if (ft_strlen(form->pad_str) > 0 && form->minus == true) 
		ft_putstr(form->pad_str);
	*count += (ft_strlen(form->pad_str) + ft_strlen(form->zer_str) + ft_intlen(num));	
}

void create_output_d(intmax_t num, t_item *form, int *count)
{
	form->pad_str = ft_strnew(0);
	form->zer_str = ft_strnew(0);
	if (form->zero == false && form->pad > 0)
		form->pad_str = ft_strfill(form->pad, ' ');
	else if (form->zero == true && form->pad > 0 )
		form->pad_str = ft_strfill(form->pad, '0');
	if (form->prec > 0)
		form->zer_str = ft_strfill(form->prec, '0');
}

void			ft_analyze_d(intmax_t num, t_item *form, char *flags, int *count)
{
	if (num < 0)
	{
		form->sign = '-';
		num = -num;
	}
	if (find_plus(flags) && form->sign != '-')
		form->sign = '+';
	else if (find_space(flags))
		form->space = true;
	form->prec = calculate_zeros(num, flags);	
	if (find_minus(flags))
		form->minus = true;
	else if (find_zero(flags) && form->prec == -1)
		form->zero = true;
	if (is_sign(form->sign) || form->pad > 0) 
		form->space = false;
	form->pad = calculate_padding(num, form, flags);
	create_output_d(num, form, count);
	ft_sign_order(form, form->pad_str, form->zer_str);	
	make_output_d(num, form, count);
}
