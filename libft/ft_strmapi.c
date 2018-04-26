/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zshanabe <zshanabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/22 13:34:02 by zshanabe          #+#    #+#             */
/*   Updated: 2018/03/27 15:25:45 by zshanabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	len;
	size_t	i;
	char	*str;
	char	*p;

	if (!s)
		return (0);
	i = 0;
	len = ft_strlen(s);
	str = malloc(sizeof(char) * (len + 1));
	if (str == NULL)
		return (0);
	p = (char *)s;
	while (p[i])
	{
		str[i] = f(i, p[i]);
		i++;
	}
	str[i] = '\0';
	return (str);
}
