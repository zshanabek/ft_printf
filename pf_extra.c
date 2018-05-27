#include "ft_printf.h"

int		is_specifier(char c)
{
	char *spec;
	char *flags;

	flags = "%sSpdDioOuUxXcC";
	spec = ft_strchr(flags, c);
	if (spec)
		return (1);
	return (0);
}

int		is_sign(char c)
{
	if (c == '+' || c == '-')
		return (1);
	return (0);
}

void	create_output(t_item *form)
{
	if (form->zer > 0)
		form->zer_str = ft_strfill(form->zer, '0');
	if (form->pad > 0 && form->zero == true)
		form->pad_str = ft_strfill(form->pad, '0');
	else if (form->pad > 0 && form->zero == false)
		form->pad_str = ft_strfill(form->pad, ' ');
}

void	ft_sign_order(t_item *form)
{
	if ((form->pad <= 0 && form->zer <= 0) ||
	(form->pad > 0 && form->zer <= 0 && form->zero == true) ||
	(form->zer > form->pad))
		form->order = 1;
	else if (form->pad > 0 && form->zer > 0)
		form->order = 2;
	else if (form->pad > 0 && form->zer <= 0)
		form->order = 3;
}

void	ft_basic_analyze(char *flags, t_item *form)
{
	if (find_minus(flags))
		form->minus = true;
	else if (find_zero(flags))
		form->zero = true;
}