#include "ft_printf.h"

intmax_t	find_length(va_list ap, char *flags, t_item *form)
{
	int i;

	i = 0;
	while (flags[i])
	{
		if (flags[i] == 'h' && flags[i + 1] == 'h')
			return ((char)(va_arg(ap, int)));
		else if (flags[i] == 'l')
			return (va_arg(ap, long));
		else if (flags[i] == 'h')
			return ((short)va_arg(ap, int));
		else if (flags[i] == 'j')
			return (va_arg(ap, long));
		else if (flags[i] == 'z')
			return (va_arg(ap, size_t));
		i++;
	}
	if (form->spec == 'D')
		return (va_arg(ap, long int));
	else
		return (va_arg(ap, int));
}

uintmax_t	find_length_u(va_list ap, char *flags)
{
	int i;

	i = 0;
	while (flags[i])
	{
		if (flags[i] == 'h' && flags[i + 1] == 'h')
			return ((unsigned char)va_arg(ap, unsigned int));
		else if (flags[i] == 'l')
			return (va_arg(ap, unsigned long));
		else if (flags[i] == 'h')
			return ((short)va_arg(ap, unsigned int));
		else if (flags[i] == 'j')
			return (va_arg(ap, uintmax_t));
		else if (flags[i] == 'z')
			return (va_arg(ap, size_t));
		i++;
	}
	return (va_arg(ap, unsigned int));
}

void		identify_spec(t_item *form, va_list ap, char *flags, int *count)
{
	if (form->spec == 'd' || form->spec == 'i' || form->spec == 'D')
		ft_analyze_d(find_length(ap, flags, form), form, flags, count);
	else if (form->spec == 'o' || form->spec == 'x' || form->spec == 'u')
		ft_analyze_u(find_length_u(ap, flags), form, flags, count);
	else if (form->spec == 'p' || form->spec == 'X')
		ft_analyze_u(find_length_u(ap, flags), form, flags, count);
	else if (form->spec == 'O' || form->spec == 'U')
		ft_analyze_u(va_arg(ap, unsigned long int), form, flags, count);
	else if (form->spec == 'S' || (form->spec == 's' && find_length_s(flags)))
		ft_analyze_ls(va_arg(ap, wchar_t *), form, flags, count);
	else if (form->spec == 's')
		ft_analyze_s(va_arg(ap, char *), form, flags, count);
	else if (form->spec == 'c' || form->spec == 'C')
		ft_analyze_c(find_length_c(ap, flags, form), form, flags, count);
	else if (form->spec == '%')
		ft_analyze_percent(form, flags, count);
	free(form);
}

int			go_str(int i, va_list ap, const char *restrict format, int *count)
{
	t_item		*form;

	i += 1;
	form = create_struct();
	identify_spec(form, ap, get_inform(format, i, form), count);
	while (!is_specifier(format[i]))
		i++;
	return (i);
}

int			ft_printf(const char *restrict format, ...)
{
	int			i;
	int			count;
	va_list		ap;

	i = 0;
	count = 0;
	va_start(ap, format);
	while (format[i])
	{
		if (format[i] != '%')
		{
			ft_putchar(format[i]);
			count++;
		}
		if (format[i] == '%')
			i = go_str(i, ap, format, &count);
		i++;
	}
	va_end(ap);
	return (count);
}

// int main()
// {
// 	ft_printf("%#X", 42);
// }