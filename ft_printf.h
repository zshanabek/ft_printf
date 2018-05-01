/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zshanabe <zshanabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/26 21:48:23 by zshanabe          #+#    #+#             */
/*   Updated: 2018/05/01 14:42:55 by zshanabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include "libft/libft.h"
# include <stdio.h>
# include <unistd.h>
# include <stdarg.h>

typedef struct	s_item
{
	int pls_spc;
	int min_zer;	
	int width;		
	int hash;			
	int precision;
	char specifier;
	int percent;
}				t_item;

void print_struct_members(t_item *form);
void ft_integer(int num, t_item *form);


#endif