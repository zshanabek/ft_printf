#include "ft_printf.h"

char	*get_inform(const char * restrict format, int i, t_item *form)
{
	int		k;
	int		len;
	char	*flags;
	
	k = i;
	len = 0;
	if (is_specifier(format[i]))
	{
		form->specifier = format[i];
		flags = ft_strnew(0);
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
	int num;
	char *string;

	if (form->specifier == 'd')
	{
		num = va_arg(*ap, int);
		num = ft_analyze_d(num, form, flags);
		create_output_d(num, form, count);
	}
	else if (form->specifier == 's')
		ft_analyze_s(va_arg(*ap, char *), form, flags, count);
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
	ft_printf	 ("%+20hd\n",434);
	printf	 ("%+20d\n",344);
	

	// ft_printf("1 |%d\n",0);
	// ft_printf("2 |%d\n",-7); 
	// ft_printf("3 |%d\n",1560133635);
	// ft_printf("4 |%d\n",-2035065302);
	// printf	 ("1 |%d\n",0);
	// printf	 ("2 |%d\n",-7);
	// printf	 ("3 |%d\n",1560133635);
	// printf	 ("4 |%d\n",-2035065302);
	
}
