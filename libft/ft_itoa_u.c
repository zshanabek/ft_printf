/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_u.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zshanabe <zshanabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/14 21:17:57 by zshanabe          #+#    #+#             */
/*   Updated: 2018/05/17 22:30:41 by zshanabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*fill_arr(char *arr, uint64_t n, int len)
{
	int		flag;
	
	flag = 1;
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

char			*ft_itoa_u(uint64_t n)
{
	int		len;
	char	*arr;

	len = ft_intlen_u(n);
	arr = (char *)malloc(sizeof(char) * (len + 1));
	if (arr == NULL)
		return (0);
	return (fill_arr(arr, n, len));
}
