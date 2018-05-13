#include "ft_printf.h"

char	*get_inform(const char * restrict format, int i, t_item *form)
{
	int		k;
	int		len;
	char	*flags;

	flags = ft_strnew(0);	
	k = i;
	len = 0;
	if (is_specifier(format[i]))
	{
		form->specifier = format[i];
		return (flags);
	}
	while (!(is_specifier(format[i])))
	{
		i++;
		len++;
	}
	form->specifier = format[i];	
	flags = ft_strsub(format, k, len);
	return (flags);
}

void find_modifiers(char *flags)
{
	int i;
	enum modifiers floor;

	i = 0;
	while(flags[i])
	{
		if (flags[i-1] == 'h' && flags[i] == 'h')
			floor = hh;
		if (flags[i-1] == 'l' && flags[i] == 'l')
			floor = ll;
		if (flags[i] == 'h')
			floor = l;
		if (flags[i] == 'l')
			floor = h;
		i++;
	}
}

void	identify_specifier(t_item *form, va_list *ap, char *flags, int *count)
{
	int				*num;
	unsigned int	*unum;
	char			*string;
	int64_t			address;

	find_modifiers(flags);
	if (form->specifier == 'd')
	{
		unum = NULL;
		ft_analyze_d(va_arg(*ap, int), unum, form, flags, count);
	}
	else if (form->specifier == 's')
		ft_analyze_s(va_arg(*ap, char *), form, flags, count);
	else if (form->specifier == 'c')
		ft_analyze_c(va_arg(*ap, int), form, flags, count);
	else if (form->specifier == 'o')
		ft_analyze_o(va_arg(*ap, int), form, flags, count);
	else if (form->specifier == 'x')
		ft_analyze_x(va_arg(*ap, int), form, flags, count);
	else if (form->specifier == 'p')
	{
		address = va_arg(*ap,int);
		ft_analyze_x(address, form, flags, count);
	}
	else if (form->specifier == 'u')
	{
		num = NULL;
		// ft_analyze_d(num, va_arg(*ap, unsigned int), form, flags, count);
	}
}

int	ft_printf(const char * restrict format, ...)
{
	int			i;
	int			count;
	char		*flags;
	t_item		*form;
	va_list		ap;

	count = 0;
    va_start(ap, format);
	i = 0;
	while (format[i])
	{
		if (format[i] != '%')
		{
			ft_putchar(format[i]);
			count++;
		}
		if (format[i] == '%')
		{
			i += 1;
			form = create_struct();
			flags = get_inform(format, i, form);
			identify_specifier(form, &ap, flags, &count);
			while (is_specifier(format[i]) != 1)
				i++;
			free(form);
		}
		i++;
	}
	return (count);
}


int		main()
{
	ft_printf ("Characters: %c %c \n", 'a', 65);
	ft_printf ("Decimals: %d %ld\n", 1977, 650000L);
	ft_printf ("Preceding with blanks: %10d \n", 1977);
	ft_printf ("Preceding with zeros: %010d \n", 1977);
	ft_printf ("Some different radices: %d %x %o %#x %#o \n", 100, 100, 100, 100, 100);
	ft_printf ("floats: %4.2f %+.0e %E \n", 3.1416, 3.1416, 3.1416);
	ft_printf ("Width trick: %*d \n", 5, 10);
	ft_printf ("%s \n", "A string");
}
