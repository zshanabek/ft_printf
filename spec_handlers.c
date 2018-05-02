#include "ft_printf.h"

void print_wp(int width, int precision)
{
	printf("w: %d\n", width);
	printf("p: %d\n", precision);	
}

void ft_integer(int num, t_item *form)
{
	int width;
	int precision;

	precision = form->precision - ft_intlen(num) + 1;	
	if (form->precision > ft_intlen(num))
		width = form->width - form->precision;
	else
		width = form->width - ft_intlen(num);
	if (width > 0 && form->min_zer == 2 && form->precision == 0)
		while(width--)
			ft_putchar('0');
	else if (width > 0 && form->min_zer != 1)
		while(width--)
			ft_putchar(' ');
	if (precision > 0)
	{
		if (num >= 0)
			precision--; 
		while(precision--)
			ft_putchar('0');
	}
	ft_putnbr(num);
	if (width > 0 && form->min_zer == 1)
		while(width--)
			ft_putchar(' ');
}