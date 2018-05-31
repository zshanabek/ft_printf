/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putsymbol.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zshanabe <zshanabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/19 13:50:28 by zshanabe          #+#    #+#             */
/*   Updated: 2018/05/28 19:04:53 by zshanabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		ft_putunicode(wchar_t c, int size)
{
	if (size == 2)
	{
		ft_putchar((c >> 6) + 0b11000000);
		ft_putchar((c & 0b111111) + 0b10000000);
	}
	else if (size == 3)
	{
		ft_putchar((c >> 12) + 0b11100000);
		ft_putchar(((c >> 6) & 0b111111) + 0b10000000);
		ft_putchar((c & 0b111111) + 0b10000000);
	}
	else
	{
		ft_putchar((c >> 18) + 0b11110000);
		ft_putchar(((c >> 12) & 0b111111) + 0b10000000);
		ft_putchar(((c >> 6) & 0b111111) + 0b10000000);
		ft_putchar((c & 0b111111) + 0b10000000);
	}
}

void			ft_putsymbol(wchar_t c)
{
	int		size;

	size = ft_charlen(c);
	if (MB_CUR_MAX != 1)
	{
		if (size == 1)
			ft_putchar(c);
		else
			ft_putunicode(c, size);
	}
}
