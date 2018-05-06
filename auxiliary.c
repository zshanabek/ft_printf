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
	printf("width: %d\n", form->width);
	if (form->precision != -1)
		printf("precision: %d\n", form->precision);
	else
		printf("no precision\n");
	printf("specifier: %c\n", form->specifier);
	printf("=====================\n");	
}

void print_wp(int width, int precision)
{
	printf("w: %d\n", width);
	printf("p: %d\n", precision);	
}