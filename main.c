/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zshanabe <zshanabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/27 20:20:41 by zshanabe          #+#    #+#             */
/*   Updated: 2018/04/30 17:48:00 by zshanabe         ###   ########.fr       */
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

void print_struct_members(t_item *form)
{
	if (form->pls_spc == 2)
		printf("pls_spc: %s\n", "space");
	else if (form->pls_spc == 1)
		printf("pls_spc: %c\n", '+');
	else
		printf("pls_spc: %s\n", "null");
	if (form->min_zer == 2)
		printf("min_zero: %d\n", 0);
	else if (form->min_zer == 1)
		printf("min_zero: %c\n", '-');
	else
		printf("min_zero: %s\n", "null");		
	printf("hash: %d\n", form->hash);	
	printf("width: %d\n", form->width);
	printf("precision: %d\n", form->precision);	
	printf("specifier: %c\n", form->specifier);
	printf("=====================\n");	
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
			if (form->specifier == 'd')
				ft_integer(va_arg(ap, int), form);
			else if (form->specifier == 'c')
				ft_character(va_arg(ap, int), form);
			else if (form->specifier == 's')
				ft_string(va_arg(ap, char*), form);
			else if (form->specifier == 'x')
				ft_hex(va_arg(ap, int), form);
			free(form);	
		}
		i++;
	}
}

int main()
{
	// ft_printf ("%010.5d %10c %-10s", 4, 'c', "ok");
	// ft_printf ("%-07.17d %#10.15x %-10s", 55, 11, "ok");
	printf ("%5.4d\n", 25);	
	// ft_printf ("%5.3d\n", -25);		
	// ft_printf ("ok%10.5d ok\n", 445);		
}