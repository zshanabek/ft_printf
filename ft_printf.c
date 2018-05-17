/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zshanabe <zshanabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/16 17:11:06 by zshanabe          #+#    #+#             */
/*   Updated: 2018/05/17 21:51:47 by zshanabe         ###   ########.fr       */
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

void find_length(intmax_t *n, va_list ap, char *flags)
{
	int i;
	int ok;

	i = 0;
	ok = 0;	
	while(flags[i])
	{
		if (flags[i-1] == 'h' && flags[i] == 'h')
		{
			*n = (char)(va_arg(ap, int));
			ok = 1;
		}
		else if ((flags[i-1] == 'l' && flags[i] == 'l') || flags[i] == 'l')
		{
			*n = (long)va_arg(ap, intmax_t);	
			ok = 1;
		}
		else if (flags[i] == 'h')
		{
			*n = (short)(va_arg(ap, intmax_t));
			ok = 1;
		}
		i++;
	}
	if (ok == 0)
		*n = va_arg(ap, intmax_t);
}


void find_length_u(uintmax_t *k, va_list ap, char *flags)
{
	int i;
	int ok;

	ok = 0;
	i = 0;
	while(flags[i])
	{
		if (flags[i-1] == 'h' && flags[i] == 'h')
		{
			*k = (char)(va_arg(ap, unsigned int));
			ok = 1;
		}
		else if ((flags[i-1] == 'l' && flags[i] == 'l') || flags[i] == 'l')
		{
			*k = (long)va_arg(ap, uintmax_t);
			ok = 1;
		}	
		else if (flags[i] == 'h')
		{
			*k = (short)(va_arg(ap, uintmax_t));
			ok = 1;
		}
		i++;
	}
	if (ok == 0)
		*k = va_arg(ap, uintmax_t);
}

void find_length_s(wchar_t *s, va_list ap, char *flags)
{
	int i;

	i = 0;
	while (flags[i])
	{
		if (flags[i] == 'l')
			*s = va_arg(ap, wchar_t);
		i++;
	}
}

void	identify_specifier(t_item *form, va_list ap, char *flags, int *count)
{

	intmax_t			n;	
	uintmax_t 			k;
	wchar_t				s;

	if (form->specifier == 'd' || form->specifier == 'i' || form->specifier == 'D')
		find_length(&n, ap, flags);
	if (form->specifier == 'o' || form->specifier == 'x' || form->specifier == 'X' || form->specifier == 'u' || form->specifier == 'p')
		find_length_u(&k, ap, flags);
	if (form->specifier == 's')
		find_length_s(&s, ap, flags);
	// =========================identify conversion===================
	if (form->specifier == 'd' || form->specifier == 'i')
		ft_analyze_d(n, form, flags, count);
	else if (form->specifier == 'o' || form->specifier == 'x' || form->specifier == 'u' || form->specifier == 'p' || form->specifier == 'X')
		ft_analyze_u(k, form, flags, count);
	else if (form->specifier == 's')
		ft_analyze_s(va_arg(ap, char *), form, flags, count);
	else if (form->specifier == 'c')
		ft_analyze_c(va_arg(ap, int), form, flags, count);
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


void ft_strupcase(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		str[i] = ft_toupper(str[i]);
		i++;
	}
}

int		main()
{
	ft_printf("1 |%12X\n", 45);
	ft_printf("2 |%012X\n", 45);
	ft_printf("3 |%#12X\n", 45);
	ft_printf("4 |%#012X\n", 45);
	ft_printf("5 |%-12X\n", 45);
	ft_printf("6 |%-#12X\n", 45);
	ft_printf("7 |%12.4X\n", 45);
	ft_printf("8 |%-#12.4X\n", 45); 
	ft_printf("======================\n");
	printf	 ("1 |%12X\n", 45);
	printf	 ("2 |%012X\n", 45);
	printf	 ("3 |%#12X\n", 45);
	printf	 ("4 |%#012X\n", 45);
	printf	 ("5 |%-12X\n", 45);
	printf	 ("6 |%-#12X\n", 45);
	printf	 ("7 |%12.4X\n", 45);
	printf	 ("8 |%-#12.4X\n", 45);
}