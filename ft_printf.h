/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zshanabe <zshanabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/26 21:48:23 by zshanabe          #+#    #+#             */
/*   Updated: 2018/04/27 14:41:57 by zshanabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF
# define FT_PRINTF
# include "libft/libft.h"
typedef struct	s_spec
{
	int width;
	int hyphen;
	int precision;
	char specifier;
}				t_spec;

#endif