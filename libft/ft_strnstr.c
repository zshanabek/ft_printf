/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zshanabe <zshanabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/21 16:25:28 by zshanabe          #+#    #+#             */
/*   Updated: 2018/03/27 15:26:00 by zshanabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_exist(char *haystack, char *needle, size_t i, size_t len)
{
	while (*haystack == *needle && *needle && i < len)
	{
		haystack++;
		needle++;
		i++;
	}
	if (i <= len && *needle)
		return (0);
	if (i <= len)
		return (1);
	return (0);
}

char		*ft_strnstr(const char *str, const char *to_find, size_t len)
{
	char	*p1;
	char	*p2;
	size_t	i;

	i = 0;
	p1 = (char *)str;
	p2 = (char *)to_find;
	if (to_find[0] == 0)
		return (p1);
	while (*p1 && i < len)
	{
		if (*p1 == *p2)
		{
			if (is_exist(p1, p2, i, len))
				return (p1);
		}
		p1++;
		i++;
	}
	return (0);
}
