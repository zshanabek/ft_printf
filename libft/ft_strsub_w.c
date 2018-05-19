/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub_w.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zshanabe <zshanabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/19 13:26:52 by zshanabe          #+#    #+#             */
/*   Updated: 2018/05/19 13:28:43 by zshanabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

wchar_t		*ft_strsub_w(wchar_t const *s, unsigned int start, size_t len)
{
	wchar_t		*str;
	size_t		i;

	if (!s)
		return (0);
	i = 0;
	str = (wchar_t *)malloc(sizeof(wchar_t) * (len + 1));
	if (str == NULL)
		return (0);
	while (s[start] && i < len)
	{
		str[i] = s[start];
		start++;
		i++;
	}
	str[i] = '\0';
	return (str);
}
