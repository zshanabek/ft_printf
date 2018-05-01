/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spec_handlers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zshanabe <zshanabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/30 17:46:50 by zshanabe          #+#    #+#             */
/*   Updated: 2018/05/01 15:22:48 by zshanabe         ###   ########.fr       */
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
	// printf("w: %d\n", width);
	// printf("p: %d\n", precision);
	// print_struct_members(form);
	if (form->pls_spc == 1 && form->min_zer != 2)
		ft_putchar('+');	
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
	if (form->pls_spc == 1 && form->min_zer == 2)
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