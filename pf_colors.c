/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_colors.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zshanabe <zshanabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/03 23:04:18 by zshanabe          #+#    #+#             */
/*   Updated: 2018/06/03 23:04:38 by zshanabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		put_color(char *color)
{
	if (ft_strequ(color, "red"))
		ft_putstr("\x1b[31m");
	else if (ft_strequ(color, "green"))
		ft_putstr("\x1b[32m");
	else if (ft_strequ(color, "yellow"))
		ft_putstr("\x1b[33m");
	else if (ft_strequ(color, "blue"))
		ft_putstr("\x1b[34m");
	else if (ft_strequ(color, "magenta"))
		ft_putstr("\x1b[35m");
	else if (ft_strequ(color, "cyan"))
		ft_putstr("\x1b[36m");
	else if (ft_strequ(color, "eoc"))
		ft_putstr("\x1b[0m");
	else
		return (0);
	return (1);
}

int		identify_color(const char *restrict s, int i)
{
	int		len;
	int		k;
	char	*color;

	len = 0;
	k = i;
	while (s[i] && s[i] != '}')
	{
		i++;
		len++;
	}
	color = ft_strsub(s, k + 1, len - 1);
	if (put_color(color) == 0)
	{
		ft_putchar('{');
		i = k;
	}
	free(color);
	return (i);
}
