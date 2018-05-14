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

void find_length(intmax_t *n, va_list *ap, char *flags)
{
	int i;

	i = 0;
	while(flags[i])
	{
		if (flags[i-1] == 'h' && flags[i] == 'h')
			*n = (char)(va_arg(*ap, int));
		else if ((flags[i-1] == 'l' && flags[i] == 'l') || flags[i] == 'l')
			*n = (long)va_arg(*ap, intmax_t);	
		else if (flags[i] == 'h')
			*n = (short)(va_arg(*ap, intmax_t));
		i++;
	}
}


void find_length_u(uintmax_t *k, va_list *ap, char *flags)
{
	int i;

	i = 0;
	while(flags[i])
	{
		if (flags[i-1] == 'h' && flags[i] == 'h')
			*k = (char)(va_arg(*ap, unsigned int));
		else if ((flags[i-1] == 'l' && flags[i] == 'l') || flags[i] == 'l')
			*k = (long)va_arg(*ap, uintmax_t);	
		else if (flags[i] == 'h')
			*k = (short)(va_arg(*ap, uintmax_t));
		i++;
	}
	*k = va_arg(*ap, uintmax_t);
}


void	identify_specifier(t_item *form, va_list *ap, char *flags, int *count)
{

	intmax_t			n;	
	uintmax_t 			k;

	if (form->specifier == 'd' || form->specifier == 'i')
		find_length(&n, ap, flags);
	if (form->specifier == 'u' || form->specifier == 'o' || form->specifier == 'x' || form->specifier == 'p' )
		find_length_u(&k, ap, flags);
	// =========================identify conversion===================
	if (form->specifier == 'd' && form->specifier == 'i')
		ft_analyze_d(n, form, flags, count);
	else if (form->specifier == 'o' || form->specifier == 'x' || form->specifier == 'u' || form->specifier == 'p' )	
		ft_analyze_u(k, form, flags, count);
	else if (form->specifier == 's')
		ft_analyze_s(va_arg(*ap, char *), form, flags, count);
	else if (form->specifier == 'c')
		ft_analyze_c(va_arg(*ap, int), form, flags, count);

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
	int a;

	a = 32;
	// ft_printf("ZSH: %lu\n", 3333333333333);	
	ft_printf("MY|%p\n",&a);
	printf("OR|%p\n",&a);		
	// ft_printf("ORG|%#2x\n",345);
	// ft_printf("ORG|%#2o\n",345);	
}
