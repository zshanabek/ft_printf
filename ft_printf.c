/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zshanabe <zshanabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/16 17:11:06 by zshanabe          #+#    #+#             */
/*   Updated: 2018/05/18 00:25:41 by zshanabe         ###   ########.fr       */
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
			return ((char)(va_arg(ap, unsigned int)));
		else if ((flags[i-1] == 'l' && flags[i] == 'l') || flags[i] == 'l')
			return ((long)va_arg(ap, uint64_t));
		else if (flags[i] == 'h')
			return ((short)(va_arg(ap, uint64_t)));
		i++;
	}
	return (va_arg(ap, uint64_t));		
}

wchar_t *find_length_s(va_list ap, char *flags)
{
	int i;

	i = 0;
	while (flags[i])
	{
		if (flags[i] == 'l')
			return (va_arg(ap, wchar_t *));
		i++;
	}
	return (va_arg(ap, wchar_t *));
}

void	identify_specifier(t_item *form, va_list ap, char *flags, int *count)
{
	if (form->specifier == 'd' || form->specifier == 'i' || form->specifier == 'D')
		ft_analyze_d(find_length(ap, flags), form, flags, count);
	else if (form->specifier == 'o' || form->specifier == 'x' || form->specifier == 'u' || form->specifier == 'p' || form->specifier == 'X')
		ft_analyze_u(find_length_u(ap, flags), form, flags, count);
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

// int		main()
// {
// 		printf ("number 1|%d\n", ft_printf("1 |%12X\n", 45));
// 		printf ("number 2|%d\n", ft_printf("2 |%012X\n", 45));
// 		printf ("number 3|%d\n", ft_printf("3 |%#12X\n", 45));
// 		printf ("number 4|%d\n", ft_printf("4 |%#012X\n", 45));
// 		printf ("number 5|%d\n", ft_printf("5 |%-12X\n", 45));
// 		printf ("number 6|%d\n", ft_printf("6 |%-#12X\n", 45));
// 		printf ("number 7|%d\n", ft_printf("7 |%12.4X\n", 45));
// 		printf ("number 8|%d\n", ft_printf("8 |%-#12.4X\n", 45)); 
// 		printf ("number 1|%d\n", printf	 ("1 |%12X\n", 45));
// 		printf ("number 2|%d\n", printf	 ("2 |%012X\n", 45));
// 		printf ("number 3|%d\n", printf	 ("3 |%#12X\n", 45));
// 		printf ("number 4|%d\n", printf	 ("4 |%#012X\n", 45));
// 		printf ("number 5|%d\n", printf	 ("5 |%-12X\n", 45));
// 		printf ("number 6|%d\n", printf	 ("6 |%-#12X\n", 45));
// 		printf ("number 7|%d\n", printf	 ("7 |%12.4X\n", 45));
// 		printf ("number 8|%d\n", printf	 ("8 |%-#12.4X\n", 45));
// }