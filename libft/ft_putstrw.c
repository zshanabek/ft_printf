/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstrw.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zshanabe <zshanabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/19 13:43:36 by zshanabe          #+#    #+#             */
/*   Updated: 2018/06/02 23:47:33 by zshanabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_putstrw(const wchar_t *str)
{
	int		i;
	int		flag;

	flag = 1;
	i = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		flag = ft_putsymbol(str[i]);
		if (flag == -1)
			return (flag);
		i++;
	}
	return (flag);
}
