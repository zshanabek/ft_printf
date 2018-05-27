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
	if (num == -9223372036854775808U)
	{
		str = ft_itoa_max(num);
		ft_putstr(ft_strsub(str, 1, 19));
		free(str);		
		(*count)--;
	}
	else
	{
		str = ft_itoa_max(num);
		ft_putstr(str);
		ft_strdel(&str);
	}
	if (form->pad > 0 && form->minus == true)
		ft_putstr(form->pad_str);
}

void	ft_analyze_d(intmax_t num, t_item *form, char *flags, int *count)
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
	form->zer = calculate_zeros(ft_intlen(num), flags);
	if (find_minus(flags))
		form->minus = true;
	else if (find_zero(flags) && form->zer == -1)
		form->zero = true;
	if (is_sign(form->sign))
		form->space = false;
	form->pad = calculate_padding(ft_intlen(num), form, flags);
	if (num == -9223372036854775808U)
		form->pad++;
	create_output(form);
	if (is_sign(form->sign))
	{
		ft_sign_order(form);
		(*count)++;
	}
	make_output_d(num, form, count);
	if (form->zer >= 0)
		*count += form->zer;
	if (form->pad >= 0)
		*count += form->pad;
	*count += ft_intlen(num);
}
