/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base_u.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zshanabe <zshanabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/14 15:44:20 by zshanabe          #+#    #+#             */
/*   Updated: 2018/06/02 21:48:58 by zshanabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*fill_array(uintmax_t value, uintmax_t nbr, int base, int len)
{
	char	*arr;
	char	*base_string;

	base_string = "0123456789abcdef";
	if (!(arr = ft_strnew(len)))
		return (NULL);
	arr[len] = '\0';
	if (value == 0)
		arr[0] = '0';
	while (len)
	{
		arr[--len] = base_string[nbr % base];
		nbr /= base;
	}
	return (arr);
}

char			*ft_itoa_base_u(uintmax_t value, int base)
{
	int			len;
	uintmax_t	nbr;
	char		*arr;

	len = 0;
	if (value == 0)
		len++;
	nbr = value;
	while (nbr)
	{
		nbr /= base;
		len += 1;
	}
	nbr = value;
	arr = fill_array(value, nbr, base, len);
	return (arr);
}
