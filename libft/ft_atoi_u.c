/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_u.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zshanabe <zshanabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/21 17:55:45 by zshanabe          #+#    #+#             */
/*   Updated: 2018/05/17 00:35:50 by zshanabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

uintmax_t	ft_atoi_u(const char *str)
{
	int				i;
	uintmax_t		res;

	res = 0;
	i = 0;
	while (ft_isws(str[i]) && str[i])
		i++;
	while (ft_isdigit(str[i]))
		res = res * 10 + (unsigned int)(str[i++] - '0');
	return (unsigned int)res;
}
