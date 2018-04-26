/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstaddend.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zshanabe <zshanabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/26 19:12:25 by zshanabe          #+#    #+#             */
/*   Updated: 2018/03/27 15:23:20 by zshanabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstaddend(t_list *head)
{
	t_list *current;
	t_list *object;

	current = head;
	while (current->next != NULL)
		current = current->next;
	current->next = malloc(sizeof(t_list));
	object = current->next;
	object->next = NULL;
	return (object);
}
