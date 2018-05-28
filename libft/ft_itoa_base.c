/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zshanabe <zshanabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/11 14:47:25 by zshanabe          #+#    #+#             */
/*   Updated: 2018/05/28 18:49:46 by zshanabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*fill_arr(intmax_t value, long nbr, int base, int len)
{
	char	*arr;
	char	*base_string;

	base_string = "0123456789abcdef";
	if (!(arr = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	arr[len] = '\0';
	if (value == 0)
		arr[0] = '0';
	while (len)
	{
		arr[--len] = base_string[nbr % base];
		nbr /= base;
	}
	if (value < 0 && base == 10)
		arr[0] = '-';
	return (arr);
}

char			*ft_itoa_base(intmax_t value, int base)
{
	int		len;
	long	nbr;
	char	*arr;

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
	if (nbr < 0)
	{
		if (base == 10)
			len += 1;
		nbr *= -1;
	}
	arr = fill_arr(value, nbr, base, len);
	return (arr);
}
