/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zshanabe <zshanabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/22 17:56:38 by zshanabe          #+#    #+#             */
/*   Updated: 2018/03/27 15:26:12 by zshanabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_iswhitespace(char c)
{
	if (c == '\n' || c == '\t' || c == ' ')
		return (1);
	return (0);
}

char		*ft_strtrim(char const *str)
{
	int		i;
	int		begin;
	int		end;
	char	*new;

	if (!str)
		return (0);
	begin = 0;
	end = ft_strlen(str) - 1;
	while (ft_iswhitespace(str[begin]))
		begin++;
	while (ft_iswhitespace(str[end]) && (end + 1 >= begin))
		end--;
	new = ft_strnew(end - begin + 1);
	if (!new)
		return (NULL);
	i = 0;
	while (begin <= end)
		new[i++] = str[begin++];
	new[i] = '\0';
	return (new);
}
