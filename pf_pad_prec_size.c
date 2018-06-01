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

uintmax_t	find_length_u(va_list ap, t_item *form)
{
	if (form->size == 'z')
		return (va_arg(ap, size_t));
	else if (form->size == 'j')
		return (va_arg(ap, uintmax_t));
	else if (form->size == 'l')
		return (va_arg(ap, unsigned long));
	else if (form->size == 'h' && form->doubled == 0)
		return ((unsigned short)va_arg(ap, unsigned int));
	else if (form->size == 'h' && form->doubled)
		return ((unsigned char)va_arg(ap, unsigned int));
	if (form->spec == 'p')
		return (va_arg(ap, unsigned long));
	else
		return (va_arg(ap, unsigned int));
}

intmax_t	find_length(va_list ap, t_item *form)
{
	if (form->size == 'z')
		return (va_arg(ap, size_t));
	else if (form->size == 'j')
		return (va_arg(ap, long));
	else if (form->size == 'l' || form->spec == 'D')
		return (va_arg(ap, long));
	else if (form->size == 'h' && form->doubled == 0)
		return ((short)va_arg(ap, int));
	else if (form->size == 'h' && form->doubled)
		return ((char)(va_arg(ap, int)));
	if (form->spec == 'D')
		return (va_arg(ap, long int));
	else
		return (va_arg(ap, int));
}

wint_t		find_length_c(va_list ap, t_item *form)
{
	if (form->size == 'l' || form->spec == 'C')
		return ((wchar_t)va_arg(ap, int));
	else
		return (va_arg(ap, unsigned int));
}
