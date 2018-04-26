/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zshanabe <zshanabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/21 15:15:49 by zshanabe          #+#    #+#             */
/*   Updated: 2018/03/27 15:41:29 by zshanabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcat(char *dest, const char *src)
{
	int len;
	int i;

	i = 0;
	len = 0;
	while (dest[len] != '\0')
		len++;
	while (src[i])
	{
		dest[i + len] = src[i];
		i++;
	}
	dest[i + len] = '\0';
	return (dest);
}
