/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zshanabe <zshanabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/22 16:51:48 by zshanabe          #+#    #+#             */
/*   Updated: 2018/03/27 15:25:36 by zshanabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	size_t	len;
	size_t	i;

	if (!s2)
		return ((char *)s1);
	else if (!s1)
		return ((char *)s2);
	len = ft_strlen(s1) + ft_strlen(s2);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (str == NULL)
		return (0);
	len = 0;
	while (s1[len] != '\0')
	{
		str[len] = s1[len];
		len++;
	}
	i = 0;
	while (s2[i])
		str[len++] = s2[i++];
	str[len] = '\0';
	return (str);
}
