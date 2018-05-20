/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zshanabe <zshanabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/16 17:11:06 by zshanabe          #+#    #+#             */
/*   Updated: 2018/05/20 15:56:56 by zshanabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*get_inform(const char * restrict format, int i, t_item *form)
{
	int		k;
	int		len;
	char	*flags;

	flags = ft_strnew(0);	
	k = i;
	len = 0;
	if (is_specifier(format[i]))
	{
		form->specifier = format[i];
		return (flags);
	}
	while (!(is_specifier(format[i])))
	{
		i++;
		len++;
	}
	form->specifier = format[i];	
	flags = ft_strsub(format, k, len);
	return (flags);
}

int64_t		find_length(va_list ap, char *flags)
{
	int i;

	i = 0;
	while (flags[i])
	{
		if (flags[i-1] == 'h' && flags[i] == 'h')
			return ((char)(va_arg(ap, int)));
		else if ((flags[i-1] == 'l' && flags[i] == 'l') || flags[i] == 'l')
			return ((long)va_arg(ap, int64_t));	
		else if (flags[i] == 'h')
			return (short)(va_arg(ap, int64_t));
		i++;
	}
	return (va_arg(ap, int));
}


uint64_t	find_length_u(va_list ap, char *flags)
{
	int i;

	i = 0;
	while(flags[i])
	{
		if (flags[i-1] == 'h' && flags[i] == 'h')
			return ((unsigned char)va_arg(ap, unsigned int));
		else if ((flags[i-1] == 'l' && flags[i] == 'l') || flags[i] == 'l')
			return (va_arg(ap, unsigned long));
		else if (flags[i] == 'h')
			return ((short)va_arg(ap, unsigned int));
		else if (flags[i] == 'j')
			return (va_arg(ap, uintmax_t));
		i++;
	}
	return (va_arg(ap, unsigned int));		
}

int find_length_s(va_list ap, char *flags)
{
	int i;

	i = 0;
	while (flags[i])
	{
		if (flags[i] == 'l')
			return (1);
		i++;
	}
	return (0);
}

wint_t	find_length_c(va_list ap, char *flags)
{
	int i;

	i = 0;
	while (flags[i])
	{
		if (flags[i] == 'l')
			return (va_arg(ap, wint_t));
		i++;
	}
	return (va_arg(ap, int));
}

void	identify_specifier(t_item *form, va_list ap, char *flags, int *count)
{
	if (form->specifier == 'd' || form->specifier == 'i' || form->specifier == 'D')
		ft_analyze_d(find_length(ap, flags), form, flags, count);
	else if (form->specifier == 'o' || form->specifier == 'x' || form->specifier == 'u' || form->specifier == 'p' || form->specifier == 'X')
	{
		ft_analyze_u(find_length_u(ap, flags), form, flags, count);
	}
	else if (form->specifier == 'S' || (form->specifier == 's' && find_length_s(ap, flags) == 1))
		ft_analyze_ls(va_arg(ap, wchar_t *), form, flags, count);
	else if (form->specifier == 's')
		ft_analyze_s(va_arg(ap, char *), form, flags, count);
	else if (form->specifier == 'c')
		ft_analyze_c(find_length_c(ap, flags), form, flags, count);
	else if (form->specifier == 'C')
		ft_analyze_c(va_arg(ap, wint_t), form, flags, count);
	else if (form->specifier == '%')
		ft_analyze_percent(form, flags, count);
}

int	ft_printf(const char * restrict format, ...)
{
	int			i;
	int			count;
	char		*flags;
	t_item		*form;
	va_list		ap;

	count = 0;
    va_start(ap, format);
	i = 0;
	while (format[i])
	{
		if (format[i] != '%')
		{
			ft_putchar(format[i]);
			count++;
		}
		if (format[i] == '%')
		{
			i += 1;
			form = create_struct();
			flags = get_inform(format, i, form);
			identify_specifier(form, ap, flags, &count);
			while (!is_specifier(format[i]))
				i++;
			free(form);
		}
		i++;
	}
	va_end(ap);
	return (count);
}

// int		main()
// {
// 	wchar_t c;

// 	char *s;
// 	int len;
// 	setlocale(LC_ALL, "");
// 	c = L'€';

// 	ft_printf("g: %#x\n", 0); 
// 	printf("o: %#x\n", 0); 	

// }