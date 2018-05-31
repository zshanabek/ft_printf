#include "ft_printf.h"

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
