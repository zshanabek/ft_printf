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
	printf("width: %d\n", form->padding);
	if (form->precision != -1)
		printf("precision: %d\n", form->precision);
	else
		printf("no precision\n");
	printf("specifier: %c\n", form->specifier);
	printf("====================\n");	
}

void print_wp(int width, int precision)
{
	printf("w: %d\n", width);
	printf("p: %d\n", precision);	
}

int is_specifier(char c)
{
	char *spec;
	char *flags;
	
	flags = "sSpdDioOuUxXcCfF";

	spec = ft_strchr(flags, c);
	if (spec)
		return (1);
	return (0);
}

t_item *create_struct()
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
	form->padding = 0;
	form->precision = 0;
	return (form);
}


char	*ft_paddingnew(size_t size)
{
	char *str;

	str = malloc(sizeof(char) * (size + 1));
	if (str == NULL)
		return (NULL);
	ft_memset(str, ' ', size + 1);
	return (str);
}


char	*ft_zerosnew(size_t size)
{
	char *str;

	str = malloc(sizeof(char) * (size + 1));
	if (str == NULL)
		return (NULL);
	ft_memset(str, '0', size + 1);
	return (str);
}
