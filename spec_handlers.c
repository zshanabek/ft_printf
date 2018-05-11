#include "ft_printf.h"


// calculate_padding_s(char *str, form, flags)

void create_output_s(char *str, t_item *form, int *count)
{
	
	
}

void	ft_analyze_s(char *str, t_item *form, char *flags, int *count)
{
	char *output;
	char *padding_str;

	output = ft_strnew(0);
	padding_str = ft_strnew(0);	
	if (find_minus(flags))
		form->minus = true;
	output = ft_strsub(str, 0, get_precision(flags));
	form->padding = calculate_padding_s(output, form, flags);
	
	if (form->padding > 0)
		padding_str = ft_strfill(form->padding, ' ');
	ft_putstr(padding_str);
	ft_putstr(output);	
}