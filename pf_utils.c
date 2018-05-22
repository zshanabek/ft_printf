#include "ft_printf.h"

t_item		*create_struct(void)
{
	t_item *form;

	form = (t_item *)malloc(sizeof(t_item));
	if (form == NULL)
		return (NULL);
	form->plus = false;
	form->minus = false;
	form->space = false;
	form->zero = false;
	form->hash = false;
	form->pad = 0;
	form->prec = 0;
	form->sign = 'E';
	form->hex_sign = ft_strnew(2);
	form->order = 0;
	return (form);
}

char		*ft_strfill(size_t size, char c)
{
	char *str;

	str = malloc(sizeof(char) * (size + 1));
	if (str == NULL)
		return (NULL);
	ft_memset(str, c, size);
	str[size] = '\0';
	return (str);
}

int			find_length_s(char *flags)
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

wint_t		find_length_c(va_list ap, char *flags, t_item *form)
{
	int i;

	i = 0;
	while (flags[i])
	{
		if (flags[i] == 'l' || form->spec == 'C')
			return (va_arg(ap, wint_t));
		i++;
	}
	return (va_arg(ap, int));
}

char		*get_inform(const char *restrict format, int i, t_item *form)
{
	int		k;
	int		len;
	char	*flags;

	flags = ft_strnew(0);
	k = i;
	len = 0;
	if (is_specifier(format[i]))
	{
		form->spec = format[i];
		return (flags);
	}
	while (!(is_specifier(format[i])))
	{
		i++;
		len++;
	}
	form->spec = format[i];
	flags = ft_strsub(format, k, len);
	return (flags);
}
