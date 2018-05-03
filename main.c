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

void parse_str(const char * restrict format, va_list *ap)
{
	int		i;
	int		k;
	int		num;
	t_item	*form;

	i = 0;
	while (format[i])
	{
		if (format[i] != '%')
			ft_putchar(format[i]);
		if (format[i] == '%')
		{
			form = (t_item *)malloc(sizeof(t_item));
			form->pls_spc = 0;
			form->min_zer = 0;
			form->width = 0;
			form->precision = 0;
			form->is_precision = 0;			
			form->hash = 0;	
			i += 1;
			if (format[i] == '-' || format[i] == '0')
			{
				if (format[i] == '-')
					form->min_zer = 1;
				else if (format[i] == '0')
					form->min_zer = 2;
				i++;
			}
			if (format[i] == '+' || format[i] == ' ')
			{
				if (format[i] == '+')
					form->pls_spc = 1;
				else if (format[i] == ' ')
					form->pls_spc = 2;
				i++;
			}
			if (format[i] == '#')
			{
				form->hash = 1;
				i++;
			}
			if (ft_isdigit(format[i]))
			{
				k = i;
				num = 0;
				while (format[i] && ft_isdigit(format[i]))
				{
					num++;
					i++;
				}
				form->width = ft_atoi(ft_strsub(format, k, num));
			}
			if (format[i] == '.')
			{
				form->is_precision = 1;				
				k = i;
				i++;
				num = 0;
				while (format[i] && ft_isdigit(format[i]))
				{
					num++;
					i++;
				}
				form->precision = ft_atoi(ft_strsub(format, k + 1, num));
			}
			if (is_specifier(format[i]))
				form->specifier = format[i];
			// print_struct_members(form);
			if (form->specifier == 'd')
				ft_integer(va_arg(*ap, int), form);
			free(form);	
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
	// ft_printf("%30.3d\n",42);
	// printf	 ("%30.3d\n",42);

	// ft_printf("%010.5d\n",42);
	// printf("%010.5d\n",42);

	// ft_printf("%-15.17d\n",1);	
	// printf("%-15.17d\n",1);

	// ft_printf("%015.17d\n",1);	
	// printf("%015.17d\n",1);

	// ft_printf("%+5.3d\n",4);		
	// printf("%+5.3d\n",4);		

	// ft_printf("%0+6.d\n",42);
	// printf	 ("%0+6.d\n",42);

	// ft_printf("%+06.d\n",42);
	// printf	 ("%+06.d\n",42);

	// ft_printf("%+6.4d\n",42);
	// printf("%+6.4d\n",42);

	// ft_printf("%+6.d\n",1);	
	// printf("%+6.d\n",1);	

	// ft_printf("%+19.20d\n",65655);		
	// printf("%+19.20d\n",76755);	
}