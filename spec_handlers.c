#include "ft_printf.h"


// calculate_padding_s(char *str, form, flags)

void create_output_s(char *str, t_item *form, int *count)
{
	
	
}

void	ft_analyze_s(char *str, t_item *form, char *flags, int *count)
{
	if (find_minus(flags))
		form->minus = true;
	// form->padding = calculate_padding_s(num, form, flags);
	create_output_s(str, form, count);
}