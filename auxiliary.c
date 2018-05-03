#include "ft_printf.h"

void print_struct(t_item *form)
{
	if (form->pls_spc == 2)
		printf("pls_spc: %s\n", "space");
	else if (form->pls_spc == 1)
		printf("pls_spc: %c\n", '+');
	else
		printf("pls_spc: %s\n", "null");
	if (form->min_zer == 2)
		printf("min_zero: %s\n", "zero");
	else if (form->min_zer == 1)
		printf("min_zero: %c\n", '-');
	else
		printf("min_zero: %s\n", "null");		
	printf("hash: %d\n", form->hash);	
	printf("width: %d\n", form->width);
	printf("precision: %d\n", form->precision);
	printf("is precision: %d\n", form->is_precision);			
	printf("specifier: %c\n", form->specifier);
	printf("=====================\n");	
}

void print_wp(int width, int precision)
{
	printf("w: %d\n", width);
	printf("p: %d\n", precision);	
}