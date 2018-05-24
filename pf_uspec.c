#include "ft_printf.h"

void	create_output_u(t_item *form)
{
	form->zer_str = ft_strnew(0);
	form->pad_str = ft_strnew(0);
	if (form->prec > 0)
		form->zer_str = ft_strfill(form->prec, '0');
	if (form->pad > 0 && form->zero == true)
		form->pad_str = ft_strfill(form->pad, '0');
	else if (form->pad > 0 && form->zero == false)
		form->pad_str = ft_strfill(form->pad, ' ');
}

void	ft_sign_order_u(t_item *form, int *count)
{
	if (form->hash && form->spec == 'o')
	{
		form->hex_sign = "0";
		(*count) += 1;
	}
	else if (form->hash)
	{
		form->hex_sign = "0x";
		if (form->spec == 'X')
			form->hex_sign = "0X";
		(*count) += 2;
	}
	if (form->hash)
	{
		if ((form->pad <= 0 && form->prec <= 0) ||
		(form->pad > 0 && form->prec <= 0 && form->zero == true) ||
		(form->prec > form->pad))
			form->order = 1;
		else if (form->pad > 0 && form->prec > 0)
			form->order = 2;
		else if (form->pad > 0 && form->prec <= 0)
			form->order = 3;
	}
}

void	make_output_u(t_item *form, char *output, int *count)
{
	if (form->order == 1)
		ft_putstr(form->hex_sign);
	if (ft_strlen(form->pad_str) > 0 && form->minus == false)
		ft_putstr(form->pad_str);
	if (form->order == 2)
		ft_putstr(form->hex_sign);
	if (ft_strlen(form->zer_str) > 0)
		ft_putstr(form->zer_str);
	if (form->order == 3)
		ft_putstr(form->hex_sign);
	ft_putstr(output);
	if (form->pad > 0 && form->minus == true)
		ft_putstr(form->pad_str);
	*count += (ft_strlen(form->pad_str) + ft_strlen(form->zer_str));
	*count += ft_strlen(output);
}

void	ft_analyze_u(uintmax_t num, t_item *form, char *flags, int *count)
{
	char *output;

	if (find_minus(flags))
		form->minus = true;
	else if (find_zero(flags))
		form->zero = true;
	if ((find_hash(flags) && num != 0) || (form->spec == 'p'))
		form->hash = true;
	if (form->spec == 'o' || form->spec == 'O')
		output = ft_itoa_base_u(num, 8);
	else if (form->spec == 'X' || form->spec == 'x' || form->spec == 'p')
		output = ft_itoa_base_u(num, 16);
	else
		output = ft_itoa_base_u(num, 10);
	if (form->spec == 'X')
		ft_strupcase(output);
	form->prec = calculate_zeros_u(ft_strlen(output), flags);
	form->pad = calculate_padding_u(ft_strlen(output), form, flags);
	create_output_u(form);
	ft_sign_order_u(form, count);
	make_output_u(form, output, count);
}
