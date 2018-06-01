/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wstrsub.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zshanabe <zshanabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/19 13:26:52 by zshanabe          #+#    #+#             */
/*   Updated: 2018/06/01 19:20:10 by zshanabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

wchar_t		*ft_wstrsub(wchar_t const *s, unsigned int start, size_t len)
{
	wchar_t		*str;
	size_t		i;
	size_t		d;

	if (!s)
		return (0);
	i = 0;
	d = 0;
	str = (wchar_t *)malloc(sizeof(wchar_t) * (len + 1));
	if (str == NULL)
		return (0);
	while (s[start] && (i + ft_charlen(s[start + 1]) <= len))
	{
		str[d] = s[start];
		i += ft_charlen(s[start]);
		start++;
		d++;
	}
	str[d] = '\0';
	return (str);
}
