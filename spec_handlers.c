/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spec_handlers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zshanabe <zshanabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/30 17:46:50 by zshanabe          #+#    #+#             */
/*   Updated: 2018/05/01 12:26:50 by zshanabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void ft_integer(int num, t_item *form)
{
	int len;
	int width;
	int precision;
	int offset;
	int prec2;

	if (num >= 0)
		precision = form->precision - ft_intlen(num);
	else
		precision = form->precision - ft_intlen(num) + 1;	
	if (ft_intlen(num) > form->precision)
		width = form->width - ft_intlen(num);		
	else
		width = form->width - form->precision;
	offset = width;	
	prec2 = precision;
	if (form->min_zer != 1 && width > 0)
	{
		if (form->pls_spc == 1)
			width--;
		while(width--)
		{
			if (form->min_zer == 2 || (offset > prec2 && prec2 > 0) || form->pls_spc == 1)
				ft_putchar(' ');				
			else 
				ft_putchar('0');
		}
	}
	if (num < 0)
	{
		ft_putchar('-');
		num *= -1;
	}
	if (form->pls_spc == 1)
		ft_putchar('+');
	if (precision > 0)
	{
		while(precision--)
			ft_putchar('0');
	}
	ft_putnbr(num);
	if (form->min_zer == 1 && width > 0)
	{
		while(width--)
			ft_putchar(' ');
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
