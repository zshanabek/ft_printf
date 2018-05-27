/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_max.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zshanabe <zshanabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/23 20:48:10 by zshanabe          #+#    #+#             */
/*   Updated: 2018/05/27 18:13:38 by zshanabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*fill_arr(char *arr, intmax_t n, int len)
{
	if (n < 0)
		arr[0] = '-';
	arr[len] = '\0';
	len--;
	if (n == 0)
		arr[len] = '0';
	while (len >= 0 && n != 0)
	{
		arr[len--] = (n % 10) > 0 ? n % 10 + '0' : -(n % 10) + '0';
		n /= 10;
	}
	return (arr);
}

char			*ft_itoa_max(intmax_t n)
{
	int		len;
	char	*arr;

	len = ft_intlen(n);
	arr = (char *)malloc(sizeof(char) * (len + 1));
	if (arr == NULL)
		return (0);
	return (fill_arr(arr, n, len));
}
