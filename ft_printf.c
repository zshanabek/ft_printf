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

void	identify_specifier(t_item *form, va_list *ap, char *flags, int *count)
{
	int *num;
	unsigned int *unum;
	char *string;


	if (form->specifier == 'd')
	{
		unum = NULL;
		ft_analyze_d(va_arg(*ap, int), unum, form, flags, count);
	}
	else if (form->specifier == 's')
		ft_analyze_s(va_arg(*ap, char *), form, flags, count);
	else if (form->specifier == 'o')
		ft_analyze_o(va_arg(*ap, int), form, flags, count);
	else if (form->specifier == 'x')
		ft_analyze_x(va_arg(*ap, int), form, flags, count);
	// else if (form->specifier == 'p')
	// 	ft_analyze_p(va_arg(*ap, int), form, flags, count);
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
	// ft_printf("%d", 42);
	int a;
	a = 4;
	printf("%p",&"gfgfg");
}
