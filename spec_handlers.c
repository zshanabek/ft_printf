/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spec_handlers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zshanabe <zshanabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/30 17:46:50 by zshanabe          #+#    #+#             */
/*   Updated: 2018/04/30 17:49:08 by zshanabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void ft_integer(int num, t_item *form)
{
	int len;
	int width;
	int precision;
	int offset;
	int zero;

	// print_struct_members(form);	
	precision = form->precision - ft_intlen(num);
	width = form->width - form->precision;
	zero = 0;
	if (form->min_zer == 2 && offset > 0)
		zero = 1;
	if (offset > 0)
	{
		while(offset--)
		{
			if (zero)
				ft_putchar('0');
			else			
				ft_putchar(' ');
		}
	}
	if (num < 0)
	{
		ft_putchar('-');
		num *= -1;
	}
	if (precision > 0)
	{
		while(precision--)
			ft_putchar('0');
	}
}

void ft_character(char c, t_item *form)
{
	printf("char: %c\n", c);	
	print_struct_members(form);
}

void ft_string(char *str, t_item *form)
{
	printf("string: %s\n", str);		
	print_struct_members(form);
}

void ft_hex(int num, t_item *form)
{
	printf("hex: %x\n", num);		
	print_struct_members(form);
}
