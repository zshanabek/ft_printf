/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_uspec.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zshanabe <zshanabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/02 23:55:34 by zshanabe          #+#    #+#             */
/*   Updated: 2018/06/02 23:55:35 by zshanabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_prefix(t_item *form, int num)
{
	if ((form->spec == 'o' || form->spec == 'O') &&
		form->prefix && (num == 0 && form->zer != 0))
		form->hash = false;
	else if ((form->spec == 'o' || form->spec == 'O') && (form->prefix))
		form->hash = true;
	else if ((form->prefix && num != 0) || (form->spec == 'p'))
		form->hash = true;
	if ((form->spec == 'o' || form->spec == 'O') && form->zer > 0)
		form->hash = false;
	if (form->hash)
	{
		if (form->spec == 'o' || form->spec == 'O')
			form->hex_sign = "0";
		else
		{
			form->hex_sign = "0x";
			if (form->spec == 'X')
				form->hex_sign = "0X";
		}
	}
}

void	make_output_u(t_item *form, int num, char *output)
{
	if (form->order == 1)
		ft_putstr(form->hex_sign);
	if (form->pad > 0 && form->minus == false)
		ft_putstr(form->pad_str);
	if (form->order == 2)
		ft_putstr(form->hex_sign);
	if (form->zer > 0)
		ft_putstr(form->zer_str);
	if (form->order == 3)
		ft_putstr(form->hex_sign);
	if (num != 0 || form->zer != 0)
		ft_putstr(output);
	if (form->pad > 0 && form->minus == true)
		ft_putstr(form->pad_str);
}

void	ft_analyze_u(uintmax_t num, t_item *form, int *count)
{
	char *output;

	if (form->spec == 'o' || form->spec == 'O')
		output = ft_itoa_base_u(num, 8);
	else if (form->spec == 'X' || form->spec == 'x' || form->spec == 'p')
		output = ft_itoa_base_u(num, 16);
	else
		output = ft_itoa_base_u(num, 10);
	if (form->spec == 'X')
		ft_strupcase(output);
	ft_prefix(form, num);
	form->zer = calculate_zeros(ft_strlen(output), form);
	form->pad = calculate_padding(ft_strlen(output), form);
	if (form->zer == 0 && num == 0 && form->pad > 0)
		form->pad++;
	if (form->hash)
		ft_sign_order(form, count);
	create_output(form);
	make_output_u(form, num, output);
	count_return_value(form, num, ft_strlen(output), count);
	free(output);
}
