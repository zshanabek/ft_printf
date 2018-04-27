/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zshanabe <zshanabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/27 20:20:41 by zshanabe          #+#    #+#             */
/*   Updated: 2018/04/27 21:50:19 by zshanabe         ###   ########.fr       */
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
	int		i;
	int		k;
	int		num;
	char	*precision;
	t_item	form;

	i = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			i += 1;
			num = 0;			
			while (ft_isdigit(format[i]))
			{
				num++;
				k++;
			}
			form.width = ft_atoi(ft_strsub(format, i, num));
			while (format[k])
			{
				if (is_specifier(format[k]))
					form.specifier = format[k];
				k++;
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
		}
		i++;
	}
	printf("prec: %d\n", form.precision);
}

int main()
{
	int c;
	char *s = "zhunissali";
	ft_printf ("floats: %34.45f\n");
}