/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putsymbol.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zshanabe <zshanabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/19 13:50:28 by zshanabe          #+#    #+#             */
/*   Updated: 2018/05/24 15:39:18 by zshanabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_putunicode(wchar_t c, int len)
{
	int size;

	size = 0;
	if (len <= 11)
	{
		ft_putchar((c >> 6) + 0b11000000);
		ft_putchar((c & 0b111111) + 0b10000000);
		size = 2;
	}
	else if (len <= 16)
	{
		ft_putchar((c >> 12) + 0b11100000);
		ft_putchar(((c >> 6) & 0b111111) + 0b10000000);
		ft_putchar((c & 0b111111) + 0b10000000);
		size = 3;
	}
	else
	{
		ft_putchar((c >> 18) + 0b11110000);
		ft_putchar(((c >> 12) & 0b111111) + 0b10000000);
		ft_putchar(((c >> 6) & 0b111111) + 0b10000000);
		ft_putchar((c & 0b111111) + 0b10000000);
		size = 4;
	}
	return (size);
}

int			ft_putsymbol(wchar_t c)
{
	char	*s;
	int		len;
	int		size;

	size = 0;
	s = ft_itoa_base(c, 2);
	len = ft_strlen(s);
	if (MB_CUR_MAX != 1)
	{
		if (len <= 7)
		{
			ft_putchar(c);
			size = 1;
		}
		else
			size = ft_putunicode(c, len);
	}
	return (size);
}
