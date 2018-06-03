/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_spec_handlers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zshanabe <zshanabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/02 23:55:37 by zshanabe          #+#    #+#             */
/*   Updated: 2018/06/03 15:23:22 by zshanabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_analyze_c(wint_t c, t_item *form, int *count)
{
	int		size;
	int		flag;

	flag = 1;
	size = 1;
	if (c != 0 && (form->spec == 'C' || form->size == 'l'))
		size = ft_charlen(c);
	form->pad = form->pad - size;
	create_output(form);
	if (form->minus == false && form->pad > 0)
		ft_putstr(form->pad_str);
	if (form->spec != 'C' && form->size != 'l')
		ft_putchar(c);
	else if ((flag = ft_putsymbol(c)) == -1)
		*count = -1;
	if (form->minus == true && form->pad > 0)
		ft_putstr(form->pad_str);
	if (flag != -1)
	{
		if (form->pad >= 0)
			*count += form->pad;
		*count += size;
	}
}

void	ft_analyze_percent(t_item *form, int *count)
{
	form->pad = form->pad - 1;
	create_output(form);
	if (form->minus == false && form->pad > 0)
		ft_putstr(form->pad_str);
	ft_putchar('%');
	if (form->minus == true && form->pad > 0)
		ft_putstr(form->pad_str);
	if (form->pad >= 0)
		*count += form->pad;
	*count += 1;
}

void	ft_analyze_ls(wchar_t *str, t_item *form, int *count)
{
	wchar_t		*output;
	int			flag;

	flag = 1;
	if (str == NULL)
		output = ft_wstrdup(L"(null)");
	else if (form->zer >= 0)
		output = ft_wstrsub(str, 0, form->zer);
	else
		output = ft_wstrdup(str);
	form->pad = calculate_padding(ft_wstrlen(output), form);
	create_output(form);
	if (form->minus == false && form->pad > 0)
		ft_putstr(form->pad_str);
	if ((flag = ft_putstrw(output)) == -1)
		*count = -1;
	if (form->minus == true && form->pad > 0)
		ft_putstr(form->pad_str);
	if (flag != -1)
	{
		if (form->pad >= 0)
			*count += form->pad;
		*count += ft_wstrlen(output);
	}
	free(output);
}

void	ft_analyze_s(char *str, t_item *form, int *count)
{
	char *output;

	output = NULL;
	if (str == NULL && form->zer == -1)
		output = ft_strdup("(null)");
	else if (form->zer >= 0)
		output = ft_strsub(str, 0, form->zer);
	else
		output = ft_strdup(str);
	if (output != NULL)
		form->pad = calculate_padding(ft_strlen(output), form);
	create_output(form);
	if (form->minus == false && form->pad > 0)
		ft_putstr(form->pad_str);
	if (!(str == NULL && form->zer != -1))
		ft_putstr(output);
	if (form->minus == true && form->pad > 0)
		ft_putstr(form->pad_str);
	if (form->pad >= 0)
		*count += form->pad;
	if (!(str == NULL && form->zer != -1))
	{
		*count += ft_strlen(output);
		free(output);
	}
}
