#include "ft_printf.h"

int		is_specifier(char c)
{
	char *spec;
	char *flags;

	flags = "%sSpdDioOuUxXcCfF";
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
