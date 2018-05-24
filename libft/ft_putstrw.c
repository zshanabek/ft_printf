/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstrw.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zshanabe <zshanabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/19 13:43:36 by zshanabe          #+#    #+#             */
/*   Updated: 2018/05/24 15:34:39 by zshanabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_putstrw(const wchar_t *str)
{
	int		i;
	int		size;

	size = 0;
	i = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		size += ft_putsymbol(str[i]);
		i++;
	}
	return (size);
}
