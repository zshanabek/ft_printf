/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_charlen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zshanabe <zshanabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/02 23:47:53 by zshanabe          #+#    #+#             */
/*   Updated: 2018/06/02 23:48:03 by zshanabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_charlen(wchar_t c)
{
	int		size;

	size = 0;
	if (c <= 127)
		size = 1;
	else if (c <= 2047)
		size = 2;
	else if (c <= 65535)
		size = 3;
	else
		size = 4;
	return (size);
}
