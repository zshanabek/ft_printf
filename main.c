/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zshanabe <zshanabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/27 20:20:41 by zshanabe          #+#    #+#             */
/*   Updated: 2018/04/28 15:44:58 by zshanabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include "ft_printf.h"

int is_specifier(char c)
{
	int i;	
	const char flags[] = "sSpdDioOuUxXcC";

	i = 0;
	while (flags[i])
	{
		if (flags[i] == c)
			return (1);
		i++;
	}
	return (0);
}

void print_struct_members(t_item *form)
{
	printf("sign: %d\n", form->pls_spc);
	printf("min_zero: %d\n", form->min_zer);	
	printf("width: %d\n", form->width);
	printf("precision: %d\n", form->precision);	
	printf("specifier: %c\n", form->specifier);
}

void ft_printf(const char * restrict format)
{
	int		i;
	int		k;
	int		num;
	char	*precision;
	t_item	form;

	form.pls_spc = 0;
	form.min_zer = 0;
	form.width = 0;
	form.precision = 0;
	i = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			i += 1;
			if (format[i] == '-' || format[i] == '0')
			{
				if (format[i] == '-')
					form.pls_spc = 1;
				else if (format[i] == '0')
					form.pls_spc = 2;
				i++;
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
				form.precision = ft_atoi(ft_strsub(format, k + 1, num));
			}
			if (is_specifier(format[i]))
				form.specifier = format[i];
		}
		i++;
	}
	print_struct_members(&form);
}

int main()
{
	ft_printf ("floats: %034.33f\n");
	// printf ("floats: %-.5f\n", 44.43);	
}