/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zshanabe <zshanabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/20 20:40:38 by zshanabe          #+#    #+#             */
/*   Updated: 2018/03/27 15:24:01 by zshanabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char		*ds;
	const unsigned char	*sr;

	ds = (unsigned char *)dst;
	sr = (const unsigned char *)src;
	if (sr < ds)
	{
		ds += len;
		sr += len;
		while (len--)
			*--ds = *--sr;
	}
	else
		while (len--)
			*ds++ = *sr++;
	return (dst);
}
