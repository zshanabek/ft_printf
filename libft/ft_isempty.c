/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isempty.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zshanabe <zshanabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/25 16:32:43 by zshanabe          #+#    #+#             */
/*   Updated: 2018/04/19 17:11:43 by zshanabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_isempty(char const *str)
{
	char *p;

	p = (char *)str;
	while (*p != '\0')
	{
		if (!((unsigned char)*p <= 32))
			return (0);
		p++;
	}
	return (1);
}