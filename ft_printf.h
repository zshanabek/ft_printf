/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zshanabe <zshanabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/26 21:48:23 by zshanabe          #+#    #+#             */
/*   Updated: 2018/04/28 14:54:59 by zshanabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF
# define FT_PRINTF
# include "libft/libft.h"
typedef struct	s_item
{
	int pls_spc;
	int min_zer;	
	int width;		
	int precision;
	char specifier;
}				t_item;

#endif