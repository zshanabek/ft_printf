/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_helpers.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zshanabe <zshanabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/01 21:54:27 by zshanabe          #+#    #+#             */
/*   Updated: 2018/06/01 21:55:17 by zshanabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		is_flag(char c)
{
	if (c == '-' || c == '0' || c == '+' || c == ' ' || c == '#')
		return (1);
	return (0);
}

int		is_modifier(char c)
{
	if (c == 'h' || c == 'l' || c == 'z' || c == 'j')
		return (1);
	return (0);
}

int		is_specifier(char c)
{
	if (c == 's' || c == 'S' || c == 'p' || c == 'd' ||
	c == 'D' || c == 'i' || c == 'o' || c == 'O' || c == 'u' ||
	c == 'U' || c == 'x' || c == 'X' || c == 'c' || c == 'C')
		return (1);
	return (0);
}