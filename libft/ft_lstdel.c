/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zshanabe <zshanabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/26 17:02:56 by zshanabe          #+#    #+#             */
/*   Updated: 2018/03/27 15:23:24 by zshanabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list *temp;

	if (!alst)
		return ;
	while (*alst)
	{
		temp = (*alst)->next;
		del((*alst)->content, (*alst)->content_size);
		ft_memdel((void **)alst);
		*alst = temp;
	}
	*alst = NULL;
}
