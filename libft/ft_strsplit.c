/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zshanabe <zshanabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/22 21:00:24 by zshanabe          #+#    #+#             */
/*   Updated: 2018/03/27 15:26:05 by zshanabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_delimeters(char const *s, char c)
{
	int count;
	int i;

	i = 1;
	count = 0;
	if (ft_strcmp(s, "") == 0)
		return (count);
	if (s[0] != c)
		count++;
	while (s[i])
	{
		if (s[i] != c && s[i - 1] == c)
			count++;
		i++;
	}
	return (count);
}

static int	count_len(const char *s, int j, int c)
{
	int mlen;

	mlen = 0;
	while (s[j] != c && s[j])
	{
		j++;
		mlen++;
	}
	return (mlen);
}

char		**ft_strsplit(char const *s, char c)
{
	int		i;
	int		j;
	int		k;
	char	**arr;

	if (!s)
		return (NULL);
	if (!(arr = (char **)malloc(sizeof(char *) * (count_delimeters(s, c) + 1))))
		return (0);
	i = 0;
	j = 0;
	while (i < count_delimeters(s, c))
	{
		while (s[j] == c && s[j])
			j++;
		k = 0;
		if (!(arr[i] = (char *)malloc(sizeof(char) * (count_len(s, j, c) + 1))))
			return (0);
		while (s[j] && s[j] != c)
			arr[i][k++] = s[j++];
		arr[i][k] = '\0';
		i++;
	}
	arr[i] = 0;
	return (arr);
}
