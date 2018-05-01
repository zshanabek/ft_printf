/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zshanabe <zshanabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/27 20:20:41 by zshanabe          #+#    #+#             */
/*   Updated: 2018/05/01 15:17:46 by zshanabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

void ft_printf(const char * restrict format, ...)
{
	int		i;
	int		k;
	int		num;
	t_item	*form;

	va_list ap;
    va_start(ap, format);	
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
			if (format[i] == '-' || format[i] == '0')
			{
				if (format[i] == '-')
					form->min_zer = 1;
				else if (format[i] == '0')
					form->min_zer = 2;
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
				ft_integer(va_arg(ap, int), form);
			free(form);	
		}
		i++;
	}
}

int main()
{
	// ft_printf("%+06d\n",42);	
	printf("%030.0d\n",42);

	// ft_printf("%0+6.d\n",42);	
	// printf("%0+6.d\n",42);

	// printf("%+6.d\n",1);
	// ft_printf("%+6.d\n",1);	
	// ft_printf("%+1.d\n",4);		
}