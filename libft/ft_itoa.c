/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zshanabe <zshanabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/23 15:09:21 by zshanabe          #+#    #+#             */
/*   Updated: 2018/05/20 18:02:43 by zshanabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*fill_arr(char *arr, int n, int len)
{
	int		flag;

	flag = 1;
	if (n < 0)
	{
		arr[0] = '-';
		flag = -1;
	}
	arr[len] = '\0';
	len--;
	if (n == 0)
		arr[len] = '0';
	while (len >= 0 && n != 0)
	{
		arr[len--] = flag * n % 10 + '0';
		n /= 10;
	}
	return (arr);
}

char			*ft_itoa(intmax_t n)
{
	int		len;
	char	*arr;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	len = ft_intlen(n);
	arr = (char *)malloc(sizeof(char) * (len + 1));
	if (arr == NULL)
		return (0);
	return (fill_arr(arr, n, len));
}
