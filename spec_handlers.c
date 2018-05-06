#include "ft_printf.h"

int calculate_width(int num, t_item *form)
{
	int		prec;
	prec = form->precision - ft_intlen(num);
	return (prec);
}

int calculate_precision(int num, t_item *form)
{
	int		width;

	if (ft_intlen(num) >= form->precision)
		width = form->width - ft_intlen(num);
	else
		width = form->width - form->precision;
	return (width);
}

void ft_integer(int num, t_item *form)
{
	char	sign;
	int		zeros;
	int		padding;
}

void ft_string(char *str, t_item *form)
{
	int width;

	width = form->width - ft_strlen(str);
	if (width > 0 && form->zero == 1)
		while (width--)
			ft_putchar(' ');
	ft_putstr(str);
	if (width > 0)
		while (width--)
			ft_putchar(' ');
}

void ft_character(char c, t_item *form)
{
	ft_putchar(c);
}