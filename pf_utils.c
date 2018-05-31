#include "ft_printf.h"

void print_struct(t_item *form)
{
	if (form->plus == 1)
		printf("plus\n");
	if (form->space == 1)
		printf("space\n");
	if (form->minus == 1)
		printf("minus\n");
	if (form->zero == 1)
		printf("zero\n");
	if (form->hash)
		printf("hash\n");
	printf("pad: %d\n", form->pad);
	if (form->zer != -1)
		printf("prec: %d\n", form->zer);
	else
		printf("no prec\n");
	if (form->size != 'E')
		printf("size: %c", form->size);
	if (form->size != 'E' && form->doubled)
		printf("%c\n", form->size);
	else
		printf("\n");
	printf("spec: %c\n", form->spec);
	printf("====================\n");	
}

int		is_specifier(char c)
{
	char *spec;
	const char *flags;

	flags = "%sSpdDioOuUxXcC";
	spec = ft_strchr(flags, c);
	if (spec)
		return (1);
	return (0);
}

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
	form->doubled = 0;	
	form->l = false;	
	form->pad = 0;
	form->zer = -1;
	form->sign = 'E';
	form->size = 'E';	
	form->order = 0;
	return (form);
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

int		ft_flags(const char *restrict format, int i, t_item *form)
{
	i++;
	while (format[i] == '-' || format[i] == '0' || format[i] == '+' || format[i] == ' ' || format[i] == '#')
	{
		form->minus = (form->minus || format[i] == '-') ? true : false;
		form->zero = ((form->zero || format[i] == '0') && form->minus == false) ? true : false;
		form->plus = (form->plus || format[i] == '+') ? true : false;
		form->space = ((form->space || format[i] == ' ') && form->plus == false) ? true : false;
		form->hash = (form->hash || format[i] == '#') ? true : false;
		i++;
	}
	return (i);
}

int		get_inform(const char *restrict format, int i, t_item *form)
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
	if (format[i] == 'h' || format[i] == 'l' || format[i] == 'z' || format[i] == 'j')
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
