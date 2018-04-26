/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zshanabe <zshanabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/21 15:25:36 by zshanabe          #+#    #+#             */
/*   Updated: 2018/03/27 15:25:48 by zshanabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *dest, const char *src, size_t n)
{
	size_t i;
	size_t j;
	size_t len;

	i = 0;
	j = 0;
	len = 0;
	while (dest[len] != '\0')
		len++;
	while (src[i] && j < n)
	{
		dest[i + len] = src[j];
		i++;
		j++;
	}
	dest[i + len] = '\0';
	return (dest);
}
