/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wstrlen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zshanabe <zshanabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/01 19:21:10 by zshanabe          #+#    #+#             */
/*   Updated: 2018/06/01 19:27:12 by zshanabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_wstrlen(wchar_t *str)
{
	int len;
	int i;

	i = 0;
	len = 0;
	while (str[i] && (MB_CUR_MAX != 1))
	{
		len += ft_charlen(str[i]);
		i++;
	}
	return (len);
}
