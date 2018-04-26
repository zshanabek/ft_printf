/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zshanabe <zshanabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/21 16:25:28 by zshanabe          #+#    #+#             */
/*   Updated: 2018/03/27 15:26:08 by zshanabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_exist(char *haystack, char *needle)
{
	while (*needle && *haystack == *needle)
	{
		haystack++;
		needle++;
	}
	if (*needle)
		return (0);
	return (1);
}

char		*ft_strstr(const char *str, const char *to_find)
{
	char *p1;
	char *p2;

	p1 = (char *)str;
	p2 = (char *)to_find;
	if (to_find[0] == '\0')
		return (p1);
	while (*p1)
	{
		if (*p1 == *p2)
		{
			if (is_exist(p1, p2))
				return (p1);
		}
		p1++;
	}
	return (0);
}
