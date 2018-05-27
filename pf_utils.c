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
	form->l = false;	
	form->pad = 0;
	form->zer = 0;
	form->sign = 'E';
	form->order = 0;
	return (form);
}

void	form_del(t_item *form)
{
	if (form->pad >= 0)
		ft_strdel(&form->pad_str);
	if (form->zer >= 0)
		ft_strdel(&form->zer_str);

	free(form);
	form = NULL;
}

char		*ft_strfill(size_t size, char c)
{
	char *str;

	str = (char *)malloc(sizeof(char) * (size + 1));
	if (str == NULL)
		return (NULL);
	ft_memset(str, c, size);
	str[size] = '\0';
	return (str);
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
	ft_strdel(&flags);
	flags = ft_strsub(format, k, len);
	return (flags);
}
