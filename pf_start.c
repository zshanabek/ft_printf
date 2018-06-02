/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_start.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zshanabe <zshanabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/02 23:55:10 by zshanabe          #+#    #+#             */
/*   Updated: 2018/06/03 00:25:01 by zshanabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		identify_spec(t_item *form, va_list ap, int *count)
{
	if (form->spec == 'd' || form->spec == 'i' || form->spec == 'D')
		ft_analyze_d(find_length(ap, form), form, count);
	else if (form->spec == 'o' || form->spec == 'x' || form->spec == 'u')
		ft_analyze_u(find_length_u(ap, form), form, count);
	else if (form->spec == 'p' || form->spec == 'X')
		ft_analyze_u(find_length_u(ap, form), form, count);
	else if (form->spec == 'O' || form->spec == 'U')
		ft_analyze_u(va_arg(ap, unsigned long int), form, count);
	else if (form->spec == 'S' || (form->spec == 's' && form->size == 'l'))
		ft_analyze_ls(va_arg(ap, wchar_t *), form, count);
	else if (form->spec == 's')
		ft_analyze_s(va_arg(ap, char *), form, count);
	else if (form->spec == 'c' || form->spec == 'C')
		ft_analyze_c(find_length_c(ap, form), form, count);
	else if (form->spec == '%')
		ft_analyze_percent(form, count);
	else
		ft_analyze_c(form->spec, form, count);
}

int			ft_flags(const char *restrict format, int i, t_item *form)
{
	i++;
	while (is_flag(format[i]))
	{
		form->minus = (form->minus || format[i] == '-') ? 1 : 0;
		form->zero = ((form->zero || format[i] == '0')
		&& form->minus == 0) ? 1 : 0;
		form->plus = (form->plus || format[i] == '+') ? 1 : 0;
		form->space = ((form->space || format[i] == ' ')
		&& form->plus == 0) ? 1 : 0;
		form->prefix = (form->prefix || format[i] == '#') ? 1 : 0;
		i++;
	}
	return (i);
}

int			get_inform(const char *restrict format, int i, t_item *form)
{
	i = ft_flags(format, i, form);
	while (ft_isdigit(format[i]))
		form->pad = form->pad * 10 + (format[i++] - '0');
	if (format[i] == '.')
	{
		i++;
		form->zer = 0;
		while (ft_isdigit(format[i]))
			form->zer = form->zer * 10 + (format[i++] - '0');
	}
	if (is_modifier(format[i]))
	{
		form->size = format[i];
		i++;
	}
	if (!is_specifier(format[i]) && format[i] == form->size)
	{
		form->doubled = 1;
		i++;
	}
	form->spec = format[i];
	return (i);
}

int			go_str(int i, va_list ap, const char *restrict format, int *count)
{
	t_item		*form;

	form = create_struct();
	i = get_inform(format, i, form);
	if (form->spec == '\0')
		i = -2;
	if (i != -2)
		identify_spec(form, ap, count);
	if (*count == -1)
		i = -1;
	if (form->pad > 0)
		free(form->pad_str);
	if (form->zer > 0)
		free(form->zer_str);
	free(form);
	form = NULL;
	return (i);
}

int			ft_printf(const char *restrict format, ...)
{
	int			i;
	int			count;
	va_list		ap;

	i = 0;
	count = 0;
	va_start(ap, format);
	while (format[i])
	{
		if (format[i] != '%')
		{
			ft_putchar(format[i]);
			count++;
		}
		if (format[i] == '%')
		{
			if ((i = go_str(i, ap, format, &count)) == -1)
				return (-1);
			else if (i == -2)
				return (count);
		}
		i++;
	}
	va_end(ap);
	return (count);
}
