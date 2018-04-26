/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print2darr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zshanabe <zshanabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/29 15:20:16 by zshanabe          #+#    #+#             */
/*   Updated: 2018/04/03 11:02:14 by zshanabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_print2darr(char **matrix)
{
	int i;

	i = 0;
	while (matrix[i])
	{
		ft_putstr(matrix[i]);
		ft_putchar('\n');
		i++;
	}
}
