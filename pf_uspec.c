#include "ft_printf.h"

void	ft_prefix(t_item *form, int *count)
{
	if (form->hash && (form->spec == 'o' || form->spec == 'O'))
	{
		form->hex_sign[0] = '0';
		(*count) += 1;
	}
	else if (form->hash)
	{
		form->hex_sign[0] = '0';
		form->hex_sign[1] = 'x';
		if (form->spec == 'X')
			form->hex_sign[1] = 'X';
		(*count) += 2;
	}
	if (form->hash)
		ft_sign_order(form);
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

	output = ft_strnew(1);
	ft_basic_analyze(flags, form);
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
	form->prec = calculate_zeros(ft_strlen(output), flags);
	form->pad = calculate_padding(ft_strlen(output), form, flags);
	create_output(form);
	ft_prefix(form, count);
	make_output_u(form, output, count);
}
