/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_u.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zshanabe <zshanabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/21 17:55:45 by zshanabe          #+#    #+#             */
/*   Updated: 2018/05/17 22:30:41 by zshanabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

uint64_t	ft_atoi_u(const char *str)
{
	int				i;
	uint64_t		res;

	res = 0;
	i = 0;
	while (ft_isws(str[i]) && str[i])
		i++;
	while (ft_isdigit(str[i]))
		res = res * 10 + (unsigned int)(str[i++] - '0');
	return (unsigned int)res;
}
