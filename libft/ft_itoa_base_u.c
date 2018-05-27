/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base_u.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zshanabe <zshanabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/14 15:44:20 by zshanabe          #+#    #+#             */
/*   Updated: 2018/05/27 18:30:01 by zshanabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_itoa_base_u(uintmax_t value, int base)
{
	int			len;
	char		*pointer;
	char		*base_string;
	uintmax_t	nbr;

	base_string = "0123456789abcdef";

	len = 0;
	nbr = value;
	if (nbr != 0)
	{
		while (nbr)
		{
			nbr /= base;
			len += 1;
		}
	}
	else
		len = 1;
	nbr = value;
	if (!(pointer = ft_strnew(len)))
		return (NULL);
	pointer[len] = '\0';
	if (nbr == 0)
	{
		pointer[0] = '0';
		return (pointer);
	}
	while (nbr)
	{
		pointer[--len] = base_string[nbr % base];
		nbr /= base;
	}
	return (pointer);
}
