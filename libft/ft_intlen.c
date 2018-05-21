/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zshanabe <zshanabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/26 19:55:56 by zshanabe          #+#    #+#             */
/*   Updated: 2018/05/21 19:00:33 by zshanabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_intlen(intmax_t n)
{
	int len;
	intmax_t num;

	num = n;
	len = 1;
	if (n < 0)
		n = n * -1;
	if (n > 0)
	{
		len = 0;
		while (n > 0)
		{
			n = n / 10;
			len++;
		}
	}
	if (num < 0)
		len += 1;
	return (len);
}
