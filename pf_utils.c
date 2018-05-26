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
	form->prec = 0;
	form->sign = 'E';
	form->order = 0;
	form->hex_sign = ft_strnew(2);
	form->zer_str = ft_strnew(0);
	form->pad_str = ft_strnew(0);
	form->output = ft_strnew(0);
	return (form);
}

void	form_del(t_item *form)
{
	ft_strdel(&form->pad_str);
	ft_strdel(&form->zer_str);
	ft_strdel(&form->hex_sign);
	ft_strdel(&form->output);	

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

void	get_inform(const char *restrict format, int i, t_item *form)
{
	printf("ok: %s\n", format);
}
