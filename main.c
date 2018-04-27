/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zshanabe <zshanabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/25 14:17:14 by zshanabe          #+#    #+#             */
/*   Updated: 2018/04/27 18:55:54 by zshanabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
#include <unistd.h>

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
			i++;
			while(format[i])
			{
				if (is_specifier(format[i]))
					form.specifier = format[i];
				i++;
			}
		}
		else if (format[i] == '.')
		{
			i++;
			k = i;
			num = 0;
			while (format[i] && is_digit(format[i]))
			{
				num++;
				i++;
			}
		}
		i++;
	}
	ft_putchar(form.specifier);
}

int main()
{
	int c;
	char *s = "zhunissali";
	c = printf("%s\n", s);
}