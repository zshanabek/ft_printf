/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew_w.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zshanabe <zshanabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/19 13:35:24 by zshanabe          #+#    #+#             */
/*   Updated: 2018/05/19 14:10:18 by zshanabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

wchar_t	*ft_strnew_w(size_t size)
{
	wchar_t		*str;
	wchar_t		*p;
	size_t		i;

	str = (wchar_t *)malloc(sizeof(wchar_t) * (size + 1));
	if (str == NULL)
		return (NULL);
	i = 0;
	p = (wchar_t *)str;
	while (i < (size + 1))
	{
		p[i] = (wchar_t)('\0');
		i++;
	}
	return (str);
}
