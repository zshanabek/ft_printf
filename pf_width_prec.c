#include "ft_printf.h"

int		calculate_zeros(int len, t_item *form)
{
	int precision;

	precision = form->zer;
	if (precision > 0)
		precision = precision - len;
	return (precision);
}

int		calculate_padding(int len, t_item *form)
{
	int		padding;
	int		width;

	padding = 0;
	width = form->pad;
	if (form->spec == 's' || form->spec == 'S')
		return (width - len);
	if (form->zer > 0)
		padding = width - (form->zer + len);
	else
		padding = width - len;
	if (form->sign == '+' || form->sign == '-' || form->space == true)
		padding--;
	if (form->hash == true && (form->spec == 'x' || form->spec == 'X'))
		padding -= 2;
	else if (form->spec == 'p')
		padding -= 2;
	else if (form->hash == true && (form->spec == 'o' || form->spec == 'O'))
		padding--;
	return (padding);
}
