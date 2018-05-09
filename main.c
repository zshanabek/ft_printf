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

void ft_sign_order(t_item *form, char *padding_str, char *zeros_str)
{
	// ft_putchar(form->sign);
	if (is_sign(form->sign))
	{
		if ((ft_strlen(padding_str) <= 0 && ft_strlen(zeros_str) <= 0) || (ft_strlen(padding_str) > 0 && ft_strlen(zeros_str) <= 0 && form->zero == true))
		{
			// ft_putchar('0');
			form->order = 1;
		}
		else if (ft_strlen(padding_str) > 0 && ft_strlen(zeros_str) > 0)
		{
			// ft_putchar('1');			
			form->order = 2;
		}
		else if (ft_strlen(padding_str) > 0 && ft_strlen(zeros_str) <= 0)
		{
			// ft_putchar('2');			
			form->order = 3;
		}
	}
}
int	ft_analyze_d(int num, t_item *form, char *flags)
{
	if (num < 0)
	{
		form->sign = '-';
		num *= -1;
	}
	if (find_plus(flags) && form->sign != '-')
		form->sign = '+';
	else if (find_space(flags))
		form->space = true;
	form->precision = calculate_zeros(num, flags);	
	if (find_minus(flags))
		form->minus = true;
	else if (find_zero(flags) && form->precision == -1)
		form->zero = true;

	if (is_sign(form->sign) || form->padding > 0) 
		form->space = false;
	form->padding = calculate_padding(num, form, flags);
	
	return (num);
}

void	identify_specifier(t_item *form, va_list *ap, char *flags)
{
	int num;

	if (form->specifier == 'd')
	{
		num = va_arg(*ap, int);
		num = ft_analyze_d(num, form, flags);
		create_output_d(num, form);
	}
}

void	parse_str(const char * restrict format, va_list *ap)
{
	int		i;
	char 	*flags;
	t_item	*form;

	i = 0;
	while (format[i])
	{
		if (format[i] != '%')
			ft_putchar(format[i]);
		if (format[i] == '%')
		{
			i += 1;
			form = create_struct();
			flags = get_inform(format, i, form);
			identify_specifier(form, ap, flags);
			while (is_specifier(format[i]) != 1)
				i++;
			free(form);
		}
		i++;
	}
}

void	ft_printf(const char * restrict format, ...)
{
	va_list ap;
    va_start(ap, format);
	parse_str(format, &ap);
}

int		main()
{
	ft_printf("1 |% 05d\n",0);
	ft_printf("2 |% 05d\n",-7); 
	ft_printf("3 |% 05d\n",1560133635);
	ft_printf("4 |% 05d\n",-2035065302);
	printf	 ("1 |% 05d\n",0);
	printf	 ("2 |% 05d\n",-7);
	printf	 ("3 |% 05d\n",1560133635);
	printf	 ("4 |% 05d\n",-2035065302);
}
