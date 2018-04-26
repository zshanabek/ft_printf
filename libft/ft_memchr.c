/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zshanabe <zshanabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/20 22:45:35 by zshanabe          #+#    #+#             */
/*   Updated: 2018/03/27 15:23:46 by zshanabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *str, int c, size_t n)
{
	size_t			i;
	unsigned char	*p;

	p = (unsigned char *)str;
	i = 0;
	while (i < n)
	{
		if (*p == (unsigned char)c)
			return (p);
		p++;
		i++;
	}
	return (0);
}
