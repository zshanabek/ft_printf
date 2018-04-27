/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zshanabe <zshanabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/27 20:20:41 by zshanabe          #+#    #+#             */
/*   Updated: 2018/04/27 22:05:26 by zshanabe         ###   ########.fr       */
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


void ft_printf(const char * restrict format)
{
	int i;
	char *precision;
	t_item form;	
	int num;
	int k;
	i = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			k = i;
			k++;
			while(format[k])
			{
				if (is_specifier(format[k]))
					form.specifier = format[k];
				k++;
			}
		}
		if (format[i] == '.')
		{
			k = i;
			k++;
			num = 0;
			while (format[k] && ft_isdigit(format[k]))
			{
				num++;
				k++;
			}
			form.precision = ft_atoi(ft_strsub(format, i + 1, num));
		}
		i++;
	}
	ft_putnbr(form.precision);
}

int main()
{
	int c;
	char *s = "zhunissali";
	printf ("Width trick: %5d \n", 10);
	// ft_printf ("floats: %34.33f\n");
}