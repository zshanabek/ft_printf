/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zshanabe <zshanabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/23 17:52:06 by zshanabe          #+#    #+#             */
/*   Updated: 2018/03/27 15:24:16 by zshanabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	const char *str1 = "-2147483648";
	const char *str2 = "2147483647";

	if (n == -2147483648)
		ft_putstr_fd(str1, fd);
	else if (n == 2147483647)
		ft_putstr_fd(str2, fd);
	else
	{
		if (n < 0)
		{
			ft_putchar_fd('-', fd);
			ft_putnbr_fd(n * -1, fd);
		}
		else if (n >= 10)
		{
			ft_putnbr_fd(n / 10, fd);
			ft_putchar_fd(n % 10 + '0', fd);
		}
		else
			ft_putchar_fd(n + '0', fd);
	}
}
