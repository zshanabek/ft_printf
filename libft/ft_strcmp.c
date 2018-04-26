/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zshanabe <zshanabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/21 17:54:47 by zshanabe          #+#    #+#             */
/*   Updated: 2018/03/27 15:24:38 by zshanabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_strcmp(const char *s1, const char *s2)
{
	unsigned char *p1;
	unsigned char *p2;

	p1 = (unsigned char *)s1;
	p2 = (unsigned char *)s2;
	while (*p1 && *p1 == *p2)
	{
		++p1;
		++p2;
	}
	return (*p1 - *p2);
}
