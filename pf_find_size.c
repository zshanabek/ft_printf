#include "ft_printf.h"

uintmax_t	find_length_u(va_list ap, const char *flags, t_item *form)
{
	int i;

	i = 0;
	while (flags[i])
	{
		if (flags[i] == 'z')
			return (va_arg(ap, size_t));
		else if (flags[i] == 'j')
			return (va_arg(ap, uintmax_t));
		else if (flags[i] == 'l')
			return (va_arg(ap, unsigned long));
		else if (flags[i] == 'h' && flags[i + 1] != 'h')
			return ((unsigned short)va_arg(ap, unsigned int));
		else if (flags[i] == 'h' && flags[i + 1] == 'h')
			return ((unsigned char)va_arg(ap, unsigned int));
		i++;
	}
	if (form->spec == 'p')
		return (va_arg(ap, unsigned long));
	else
		return (va_arg(ap, unsigned int));
}

intmax_t	find_length(va_list ap, const char *flags, t_item *form)
{
	int i;

	i = 0;
	while (flags[i])
	{
		if (flags[i] == 'z')
			return (va_arg(ap, size_t));
		else if (flags[i] == 'j')
			return (va_arg(ap, long));
		else if (flags[i] == 'l' || form->spec == 'D')
			return (va_arg(ap, long));
		else if (flags[i] == 'h' && flags[i + 1] != 'h')
			return ((short)va_arg(ap, int));
		else if (flags[i] == 'h' && flags[i + 1] == 'h')
			return ((char)(va_arg(ap, int)));
		i++;
	}
	if (form->spec == 'D')
		return (va_arg(ap, long int));
	else
		return (va_arg(ap, int));
}

int			find_length_s(const char *flags)
{
	int i;

	i = 0;
	while (flags[i])
	{
		if (flags[i] == 'l')
			return (1);
		i++;
	}
	return (0);
}

wint_t		find_length_c(va_list ap, const char *flags, t_item *form)
{
	int i;

	i = 0;
	while (flags[i])
	{
		if (flags[i] == 'l' || form->spec == 'C')
		{
			form->l = true;
			return ((wchar_t)va_arg(ap, int));
		}
		i++;
	}
	return (va_arg(ap, unsigned int));
}
