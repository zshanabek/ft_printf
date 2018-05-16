/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zshanabe <zshanabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/21 17:55:45 by zshanabe          #+#    #+#             */
/*   Updated: 2018/05/16 14:17:35 by zshanabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	int				i;
	long long int	res;
	int				sign;

	res = 0;
	sign = 1;
	i = 0;
	while (ft_isws(str[i]) && str[i])
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (ft_isdigit(str[i]) && res >= 0)
		res = res * 10 + (long long int)(str[i++] - '0');
	if (res < 0)
	{
		if (sign == -1)
			return (0);
		return (-1);
	}
	return ((int)res * (int)sign);
}
