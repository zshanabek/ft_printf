/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zshanabe <zshanabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/20 19:42:40 by zshanabe          #+#    #+#             */
/*   Updated: 2018/03/27 15:24:04 by zshanabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *str, int c, size_t n)
{
	size_t	i;
	char	*p;

	i = 0;
	p = (char *)str;
	while (i < n)
	{
		p[i] = (char)c;
		i++;
	}
	return (str);
}
