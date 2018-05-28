#include "ft_printf.h"

void	make_output_d(intmax_t num, t_item *form, int *count)
{
	char *str;
	if (form->space)
	{
		ft_putchar(' ');
		(*count)++;
	}
	if (form->order == 1)
		ft_putchar(form->sign);
	if (form->pad > 0 && form->minus == false)
		ft_putstr(form->pad_str);
	if (form->order == 2)
		ft_putchar(form->sign);
	if (form->zer > 0)
		ft_putstr(form->zer_str);
	if (form->order == 3)
		ft_putchar(form->sign);
	str = ft_itoa_max(num);
	if (num < 0)
		ft_putstr(str + 1);
	else
		ft_putstr(str);
	ft_strdel(&str);
	if (form->pad > 0 && form->minus == true)
		ft_putstr(form->pad_str);
}

void	ft_count(intmax_t num, int *count, t_item *form)
{
	if (form->zer > 0)
	{
		*count += form->zer;
		free(form->zer_str);
	}
	if (form->pad > 0)
	{
		*count += form->pad;
		free(form->pad_str);		
	}
	*count += ft_intlen(num);
}

void	ft_analyze_d(intmax_t num, t_item *form, char *flags, int *count)
{
	int len;

	len = ft_intlen(num);
	if (num < 0)
	{
		len--;
		form->sign = '-';	
	}
	if (find_plus(flags) && form->sign != '-')
		form->sign = '+';
	else if (find_space(flags))
		form->space = true;
	form->zer = calculate_zeros(len, flags);
	if (find_minus(flags))
		form->minus = true;
	else if (find_zero(flags) && form->zer == -1)
		form->zero = true;
	if (is_sign(form->sign))
		form->space = false;
	form->pad = calculate_padding(len, form, flags);
	create_output(form);
	if (is_sign(form->sign))
		ft_sign_order(form, count);
	make_output_d(num, form, count);
	ft_count(num, count, form);
}
