#include "ft_printf.h"

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
	return (flags);
}

void	ft_analyze_d(int num, t_item *form, char *flags)
{
	if (find_minus(flags))
		form->minus = true;
	else if (find_zero(flags) && form->precision == -1)
		form->zero = true;
	if (find_plus(flags))
		form->plus = true;
	else if (find_space(flags))
		form->space = true;
	if (num < 0)
		form->sign = '-';
	else if (form->plus)
		form->sign = '+';
	if (form->sign == '+' || form->sign == '-')
		form->space = false;
	form->precision = calculate_zeros(num, form, flags);
	form->padding = calculate_padding(num, form, flags);
}

void identify_specifier(t_item *form, va_list *ap, char *flags)
{
	int num;

	if (form->specifier == 'd')
	{
		num = va_arg(*ap, int);
		ft_analyze_d(num, form, flags);
		create_output_d(num, form);
	}
}

void parse_str(const char * restrict format, va_list *ap)
{
	int		i;
	char 	*flags;
	t_item	*form;
	int num;

	i = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			i += 1;			
			form = create_struct();
			flags = get_inform(format, i, form);
			identify_specifier(form, ap, flags);
			free(form);
		}
		i++;
	}
}

void ft_printf(const char * restrict format, ...)
{
	va_list ap;
    va_start(ap, format);
	parse_str(format, &ap);
}

int main()
{
	ft_printf("%4.3d\n", 12);
	ft_putchar('\n');
	printf("%4.3d\n", 12);	
}
