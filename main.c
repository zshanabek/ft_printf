/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zshanabe <zshanabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/25 14:17:14 by zshanabe          #+#    #+#             */
/*   Updated: 2018/04/26 13:51:24 by zshanabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

void ft_printf(char *str, char c)
{
    int i;

    i = 0;
    while (str[i])
    {
        if(str[i - 1] == '%' && str[i] == 'c')
        {
            write()
        }
        i++;
    }
}

int main()
{
    ft_printf("ok. %c", 'a');
}