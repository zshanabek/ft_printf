/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zshanabe <zshanabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/20 23:44:29 by zshanabe          #+#    #+#             */
/*   Updated: 2018/03/27 15:25:53 by zshanabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	size_t i;

	i = 0;
	while (src[i] && len)
	{
		if (!len--)
			return (dst);
		dst[i] = src[i];
		i++;
	}
	while (len--)
	{
		dst[i] = 0;
		i++;
	}
	return (dst);
}
