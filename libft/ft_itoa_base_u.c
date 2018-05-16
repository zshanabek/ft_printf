/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base_u.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zshanabe <zshanabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/14 15:44:20 by zshanabe          #+#    #+#             */
/*   Updated: 2018/05/16 14:10:41 by zshanabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_itoa_base_u(uint64_t value, int base)
{
	int		len;
	uintmax_t	nbr;
	char	*pointer;
	char	*base_string = "0123456789abcdef";

	if (value == 0)
		return ("0");
	len = 0;
	nbr = value;
	while (nbr)
	{
		nbr /= base;
		len += 1;
	}
	nbr = value;
	if (!(pointer = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	pointer[len] = '\0';
	while (nbr)
	{
		pointer[--len] = base_string[nbr % base];
		nbr /= base;
	}
	return (pointer);
}
