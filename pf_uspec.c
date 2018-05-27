#include "ft_printf.h"

void	ft_prefix(t_item *form, int *count)
{
	form->hex_sign = ft_strnew(2);
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
	if (form->pad > 0 && form->minus == false)
		ft_putstr(form->pad_str);
	if (form->order == 2)
		ft_putstr(form->hex_sign);
	if (form->zer > 0)
		ft_putstr(form->zer_str);
	if (form->order == 3)
		ft_putstr(form->hex_sign);
	ft_putstr(output);
	if (form->pad > 0 && form->minus == true)
		ft_putstr(form->pad_str);
	if (form->zer >= 0)
		*count += form->zer;
	if (form->pad >= 0)
		*count += form->pad;
	if (form->order != 0)
		ft_strdel(&form->hex_sign);		
	*count += ft_strlen(output);
	ft_strdel(&output);
}

void	ft_analyze_u(uintmax_t num, t_item *form, char *flags, int *count)
{
	char *output;

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
	form->zer = calculate_zeros(ft_strlen(output), flags);
	form->pad = calculate_padding(ft_strlen(output), form, flags);
	create_output(form);
	ft_prefix(form, count);
	make_output_u(form, output, count);
}
