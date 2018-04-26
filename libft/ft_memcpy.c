/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zshanabe <zshanabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/20 20:03:35 by zshanabe          #+#    #+#             */
/*   Updated: 2018/03/27 15:23:56 by zshanabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *str1, const void *str2, size_t n)
{
	size_t			i;
	unsigned char	*p1;
	unsigned char	*p2;

	i = 0;
	p1 = (unsigned char *)str1;
	p2 = (unsigned char *)str2;
	while (i < n)
	{
		p1[i] = p2[i];
		i++;
	}
	return (str1);
}
