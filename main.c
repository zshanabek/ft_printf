/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zshanabe <zshanabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/25 14:17:14 by zshanabe          #+#    #+#             */
/*   Updated: 2018/04/27 16:00:22 by zshanabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
#include <unistd.h>

int define_specifier(char c)
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
	t_item form;

	i = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			while(format[i])
			{
				if (define_specifier(format[i]))
					form.specifier = format[i];
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