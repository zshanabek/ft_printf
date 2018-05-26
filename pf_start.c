#include "ft_printf.h"

void		identify_spec(t_item *form, va_list ap, const char *flags, int *count)
{
	if (form->spec == 'd' || form->spec == 'i' || form->spec == 'D')
		ft_analyze_d(find_length(ap, flags, form), form, flags, count);
	else if (form->spec == 'o' || form->spec == 'x' || form->spec == 'u')
		ft_analyze_u(find_length_u(ap, flags, form), form, flags, count);
	else if (form->spec == 'p' || form->spec == 'X')
		ft_analyze_u(find_length_u(ap, flags, form), form, flags, count);
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
	form_del(form);	
}

int			go_str(int i, va_list ap, const char *restrict format, int *count)
{
	t_item		*form;
	char		*flags;

	form = create_struct();
	get_inform(format, i, form);
	identify_spec(form, ap, flags, count);
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
