/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdupw.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zshanabe <zshanabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/19 16:12:03 by zshanabe          #+#    #+#             */
/*   Updated: 2018/05/20 13:58:00 by zshanabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

wchar_t		*ft_strdupw(const wchar_t *src)
{
	int		len;
	wchar_t	*dup;
	int		i;

	len = ft_strlen_w(src);
	dup = (wchar_t *)malloc(sizeof(wchar_t) * (len + 1));
	if (dup == NULL)
		return (0);
	i = 0;
	while (src[i])
	{
		dup[i] = src[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}
