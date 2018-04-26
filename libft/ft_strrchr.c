/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zshanabe <zshanabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/23 18:46:42 by zshanabe          #+#    #+#             */
/*   Updated: 2018/04/19 17:09:43 by zshanabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		len;
	char	*p;

	p = (char *)s;
	len = ft_strlen(s);
	while (p[len] != (char)c && len)
		len--;
	if ((char)c == p[len])
		return ((char *)&p[len]);
	return (0);
}
