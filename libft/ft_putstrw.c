/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstrw.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zshanabe <zshanabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/19 13:43:36 by zshanabe          #+#    #+#             */
/*   Updated: 2018/05/19 13:54:32 by zshanabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstrw(const wchar_t *str)
{
	int i;

	i = 0;
	if (!str)
		return ;
	while (str[i])
	{
		ft_putsymbol(str[i]);
		i++;
	}
}
