#include "ft_printf.h"

int is_specifier(char c)
{
	int i;
	const char flags[] = "sSpdDioOuUxXcCfF";

	i = 0;
	while (flags[i])
	{
		if (flags[i] == c)
			return (1);
		i++;
	}
	return (0);
}


t_item *create_struct()
{
	t_item *form;

	form = (t_item *)malloc(sizeof(t_item));
	if (form == NULL)
		return (NULL);
	form->plus = false;
	form->minus = false;
	form->space = false;
	form->zero = false;			
	form->hash = false;
	form->width = 0;
	form->precision = 0;
	return (form);
}

char  *get_inform(const char * restrict format, int i, t_item *form)
{
	int		k;
	int		len;
	char	*flags;

	k = i;
	len = 0;
	while (!(is_specifier(format[i])))
	{
		i++;
		form->specifier = format[i];
		len++;
	}
	flags = ft_strsub(format, k, len);
	return flags;
}

t_item *analyze(t_item *form, char *flags)
{
	int		precision;

	form->width = get_width(flags);
	form->precision = get_precision(flags);
	if (find_minus(flags))
		form->minus = true;
	else if (find_zero(flags) && form->precision == -1)
		form->zero = true;
	if (find_plus(flags))
		form->plus = true;
	else if (find_space(flags))
		form->space = true;
	print_struct(form);
	return form;
}

void parse_str (const char * restrict format, va_list *ap)
{
	int		i;
	int		precision;
	char 	*flags;
	t_item	*form;

	i = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			form = create_struct();
			i += 1;
			flags = get_inform(format, i, form);
			analyze(form, flags);
			free(form);
			i += 1;
		}
		i++;
	}
}

void ft_printf(const char * restrict format, ...)
{
	int		i;
	int		k;
	int		num;
	t_item	*form;

	va_list ap;
    va_start(ap, format);
	parse_str(format, &ap);
}

int main()
{
	
	ft_printf("%044.12d", 12);

	// printf("%044.d", 12);
	
}
