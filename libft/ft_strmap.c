/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zshanabe <zshanabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/22 12:44:47 by zshanabe          #+#    #+#             */
/*   Updated: 2018/03/27 15:25:43 by zshanabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	size_t	len;
	size_t	i;
	char	*str;
	char	*p;

	if (!s)
		return (0);
	i = 0;
	len = ft_strlen(s);
	str = malloc(sizeof(char) * len + 1);
	if (str == NULL)
		return (0);
	p = (char *)s;
	while (p[i])
	{
		str[i] = f(p[i]);
		i++;
	}
	str[i] = '\0';
	return (str);
}
